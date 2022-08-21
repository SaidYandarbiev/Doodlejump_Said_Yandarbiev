//
// Created by said2 on 17-11-2021.
//

#include "World.h"
World::World(Vector2u l_windSize, const std::shared_ptr<Abstract_Factory>& confac)
{

        m_windowSize = l_windSize;
        concreteFactory = confac;
        camera = std::make_shared<Utility::Camera>(m_windowSize);
        player = confac->CreatePlayer_Model(Vector2f(10, 30), camera);
        currentcameray = camera->GetPosition();
        states = std::make_unique<Utility::States>();

        BG_TileSpawner();
        PlatformSpawner();

        PlatformChances.emplace_back(50, "Static");
        PlatformChances.emplace_back(60, "Horizontal");
        PlatformChances.emplace_back(70, "Vertical");
        PlatformChances.emplace_back(80, "HorizontalNotMoving");
        PlatformChances.emplace_back(90, "VerticalNotMoving");
        PlatformChances.emplace_back(100, "Breaking");

        BonusChances.emplace_back(9, "Copter");
        BonusChances.emplace_back(40, "Spring");
        BonusChances.emplace_back(50, "Health");
        BonusChances.emplace_back(70, "Spikes");


        EnemyChances.emplace_back(35,"Simple");
        EnemyChances.emplace_back(50,"Complex");
}
void World::Update()
{
        previouscameray = currentcameray;

        //We first check if our game has ended or not
        //If our game has ended it means that we do not need to update anything anymore
        if(!camera->getGameEnded()) {
                //We first update the player position
                player->Update(states, m_windowSize, XWorldSize.GetY());

                //We check if a player is shooting or not
                //If he is then we make a ball
                if(player->GetShooting()){
                        float y = player->GetPosition().y;
                        float x = player->GetPosition().x;
                        Shots.push_back(concreteFactory->CreateBall_Model(Vector2f(x,y),false,true,camera));
                }

                currentcameray = camera->GetPosition();
                player->SetShooting();

                //In this loop we loop over every bg tile
                for (int i = 0; i < BG.size(); i++) {
                        //If the position of the first bg tile in the vector is smaller than the current camera y position
                        //Then we erase it from the front and put it at the back of the vector and change its position
                        if (BG[i][0]->GetPosition().GetY() < currentcameray) {
                                std::vector<std::shared_ptr<BG_Tile_Model>> row = BG[i];
                                BG.erase(BG.begin() + i);
                                std::vector<std::shared_ptr<BG_Tile_Model>> back = BG.back();
                                for (auto& tiles : row) {
                                        tiles->SetPosition(Vector2f(tiles->GetPosition().GetX(),
                                                                    back[0]->GetPosition().GetY() + 1));
                                }
                                BG.push_back(row);
                        }
                }

                float x = player->GetPosition().GetX();
                float y = player->GetPosition().GetY();

                //If our player is falling and has collision then we enter this statement
                if (player->GetFalling() && player->GetCollision()) {

                        //We loop over every platform and check if that the player has made a collision with the
                        //Current platform in the loop
                        for (int plat = 0; plat < platforms.size(); plat++) {

                                if (player->CheckCollision(platforms[plat]->GetPosition().x,
                                                           platforms[plat]->GetPosition().y, x, y,
                                                           player->GetWidth(), platforms[0]->GetWidth(),
                                                           platforms[0]->GetHeight(), player->GetHeight())) {
                                        //If this is the case then we set the hit platform in player to the current platform
                                        //in the loop
                                        player->Platformhit(platforms[plat]);
                                        platforms[plat]->PlayerHit();
                                        Vector2f newposition =
                                            Vector2f(player->GetPosition().x,
                                                     platforms[plat]->GetPosition().y + player->GetHeight());
                                        player->SetPosition(newposition);
                                        //If the platform was a breakin platform then we delete it from the world
                                        if (platforms[plat]->GetBreaking()) {
                                                platforms[plat]->Broken();
                                        }
                                        break;
                                }
                        }
                        //We loop over every bonus and check if that the player has made a collision with the
                        //Current bonus in the loop
                        for (auto& bonus : Bonus) {
                                //If the player made collision with a spring
                                //Then we enter this statement
                                if (player->CheckCollision(bonus->GetPosition().x, bonus->GetPosition().y, x, y,
                                                           player->GetWidth(), bonus->GetWidth(),
                                                           bonus->GetHeight(), player->GetHeight()) &&
                                    bonus->GetSpring()) {
                                        player->Bonus_hit();
                                        Vector2f newposition =
                                            Vector2f(player->GetPosition().x,
                                                     bonus->GetPosition().y + player->GetHeight());
                                        player->SetPosition(newposition);
                                        bonus->PlayerTouched();
                                        break;
                                }
                                //If has made collision with the spikes then we enter this statement and delete the spikes
                                //The player takes damage
                                else if (player->CheckCollision(bonus->GetPosition().x, bonus->GetPosition().y, x, y,
                                                                player->GetWidth(), bonus->GetWidth(),
                                                                bonus->GetHeight(), player->GetHeight()) &&
                                         bonus->GetSpikes()){
                                        player->GetHp()->Hit();
                                        concreteFactory->Delete_bonus_it(bonus);
                                        Bonus.erase(std::find(Bonus.begin(),Bonus.end(),bonus));
                                        break;
                                }
                        }
                }
                //We loop over every bonus
                for (auto& bonus : Bonus) {
                        //If our player is not necessarily falling and has made collision with a helicopter
                        //Then we enter this statement
                        if (player->CheckCollision(bonus->GetPosition().x, bonus->GetPosition().y, x, y,
                                                   player->GetWidth(), bonus->GetWidth(), bonus->GetHeight(),
                                                   player->GetHeight()) &&
                            bonus->GetCopter() && player->GetCollision()) {
                                player->Copterhit();
                                concreteFactory->Delete_bonus_it(bonus);
                                auto it = std::find(Bonus.begin(), Bonus.end(), bonus);
                                Bonus.erase(it);
                                break;
                        }
                        //If our player is not necessarily falling and has made collision with health
                        //Then we enter this statement and delete the health
                        //The player gains 1 health
                        else if (player->CheckCollision(bonus->GetPosition().x, bonus->GetPosition().y, x, y,
                                                        player->GetWidth(), bonus->GetWidth(), bonus->GetHeight(),
                                                        player->GetHeight()) &&
                                 bonus->GetHealth() && player->GetCollision()){
                                player->GetHp()->GainHealth();
                                concreteFactory->Delete_bonus_it(bonus);
                                Bonus.erase(std::find(Bonus.begin(),Bonus.end(),bonus));
                                break;
                        }
                }

                auto it = platforms.begin();
                bool broken = false;

                //Here we loop over every platform and delete it if it is broken
                //Then we update the position of the platform
                for (auto& plat : platforms) {
                        if (plat->GetBroken()) {
                                concreteFactory->Delete_platform_it(plat);
                                it = std::find(platforms.begin(), platforms.end(), plat);
                                broken = true;
                                break;
                        }
                        plat->Update();

                }
                //This vector contains all the shots that have to be deleted
                std::vector<std::shared_ptr<Ball_Model>> to_delete = {};

                //Here we loop over every shot
                for(auto shot:Shots){
                        //First we update the shot
                        shot->Update();

                        //We check if that the shot belongs to the player and if so then enter this statement
                        if(shot->GetPlayer()) {
                                //for every enemy we check if that it has made collision with the current shot in the loop
                                //If it has the enemy takes a hit and loses health and the shot is pushed into the to_delete vector
                                for (auto enemy : Enemies) {
                                        if (player->CheckCollision(
                                            enemy->GetPosition().x, enemy->GetPosition().y,
                                            shot->GetPosition().x, shot->GetPosition().y + 6, 1,
                                            enemy->GetWidth(), enemy->GetHeight(), 5)) {
                                                enemy->GetHp()->Hit();
                                                concreteFactory->Delete_Shot_It(shot);
                                                to_delete.push_back(shot);

                                        }
                                }
                        }
                        //If the shot belongs to an enemy then we enter this statement
                        else if (shot->GetEnemy()){
                                //If the current shot has collided with the player then the player loses health
                                //And the shot is pushed in the to_delete vector
                                if(player->CheckCollision(shot->GetPosition().x,shot->GetPosition().y,
                                                          x,y,player->GetWidth(),1,1
                                    ,player->GetHeight())){
                                        player->GetHp()->Hit();
                                        concreteFactory->Delete_Shot_It(shot);
                                        to_delete.push_back(shot);
                                }
                        }

                        //If the shot is above the camera view then it is pushed into the to_delete vector
                        else if(shot->GetPosition().y > currentcameray){
                                concreteFactory->Delete_Shot_It(shot);
                                to_delete.push_back(shot);
                        }

                }

                //We now delete everything in the to_delete vector
                for(auto deleted:to_delete){
                        Shots.erase(std::find(Shots.begin(),Shots.end(),deleted));
                }

                //This vector contains every enemy that has to be deleted
                std::vector<std::shared_ptr<Enemy_Model>> to_be_deleted = {};

                //We now loop over every enemy
                for(auto& enemy:Enemies){
                        //If the current enemy has made collision with the player then he gets pushed into the
                        //to_be_deleted vector and the player takes a hit
                        if (player->CheckCollision(enemy->GetPosition().x,
                                                   enemy->GetPosition().y -5, x, y,
                                                   player->GetWidth() , enemy->GetWidth()-1,
                                                   enemy->GetHeight(), player->GetHeight() + 1)){
                                concreteFactory->Delete_enemy_it(enemy);
                                player->GetHp()->Hit();
                                to_be_deleted.push_back(enemy);
                        }

                        //If the enemy is located under the camera then the enemy gets pushed into the to_be_deleted vector
                        else if(enemy->GetPosition().y < currentcameray){
                                concreteFactory->Delete_enemy_it(enemy);
                                to_be_deleted.push_back(enemy);
                        }

                        //If the enemy is dead it gets pushed into the to_be_deleted vector
                        else if(enemy->GetHp()->GetDead()){
                                concreteFactory->Delete_enemy_it(enemy);
                                to_be_deleted.push_back(enemy);
                        }

                        //If the enemy is shooting then we make a new ball model
                        if(enemy->Shooting()){
                                Shots.push_back(concreteFactory->CreateBall_Model(enemy->GetPosition()
                                    ,true,false,camera));
                        }

                        //We update the enemy
                        enemy->Update();
                }

                //Now we delete everything in the to_be_deleted vector
                for(auto deleted:to_be_deleted){
                        Enemies.erase(std::find(Enemies.begin(),Enemies.end(),deleted));
                }

                //If a breaking platform is broken we erase it from the platforms vector
                if (broken) {
                        platforms.erase(it);
                }

                //First we check with the bernoulli distribution if a new platform has spawned
                //And we check if that our first platform is under our camera
                if (random->getInstance()->Bernoulli(platchance) &&
                    platforms[0]->GetPosition().y < currentcameray) {
                        //We now get a random float number between 0 and 100
                        float number = random->getInstance()->RandomFloat(0, 100);

                        //We loop over our platformchances
                        for (auto& chance : PlatformChances) {
                                if (number < chance.first) {
                                        bool breaking = false;
                                        bool horizontal = false;
                                        bool vertical = false;
                                        bool notmoving = false;

                                        //Now we check what type of platform our newly spawned will be
                                        //By looking at the corresponding chance and name in the platformchances vector
                                        //Then we will make the corresponding booleans true
                                        if (chance.second == "Horizontal") {
                                                horizontal = true;
                                        } else if (chance.second == "Vertical") {
                                                vertical = true;
                                        } else if (chance.second == "Breaking") {
                                                breaking = true;
                                        } else if (chance.second == "HorizontalNotMoving" ){
                                                horizontal = true;
                                                notmoving = true;
                                        } else if (chance.second == "VerticalNotMoving"){
                                                vertical = true;
                                                notmoving = true;
                                        }

                                        float h =
                                            random->getInstance()->RandomFloat(XWorldSize.x, XWorldSize.y);
                                        std::shared_ptr<Platform_Model> back = platforms.back();

                                        //We make a new platform with the booleans above
                                        platforms.push_back(concreteFactory->CreatePlatform_Model(
                                            Vector2f(h, back->GetPosition().y + 3), vertical, horizontal,
                                            breaking, false, notmoving, camera));

                                        //If our platform is static and there is a bonus that is spawned then we enter this statement
                                        if (!breaking && !horizontal && !vertical
                                            &&
                                            random->getInstance()->Bernoulli(bonuschance)) {
                                                bool helicopter = false;
                                                bool spring = false;
                                                bool health = false;
                                                bool spikes = false;

                                                //We now get a random number between 0 and 100 to determine which type
                                                //of bonus will spawn
                                                float number1 = random->getInstance()->RandomFloat(0, 100);
                                                for (auto& chance1 : BonusChances) {
                                                        if (number1 < chance1.first) {
                                                                if (chance1.second == "Copter") {
                                                                        helicopter = true;
                                                                } else if (chance1.second == "Spring") {
                                                                        spring = true;
                                                                }else if (chance1.second == "Health") {
                                                                        health = true;
                                                                }else if (chance1.second == "Spikes") {
                                                                        spikes = true;
                                                                }
                                                                std::shared_ptr<Platform_Model> back =
                                                                    platforms.back();
                                                                Vector2f newposition = Vector2f(
                                                                    back->GetPosition().x +
                                                                    (back->GetWidth() / 2),
                                                                    back->GetPosition().y + back->GetHeight());
                                                                Bonus.push_back(
                                                                    concreteFactory->CreateBonus_Model(
                                                                        newposition, spring, helicopter, health, spikes,
                                                                        camera));
                                                                break;
                                                        }
                                                }
                                        }
                                        //If there is no bonus spawning, but there is an enemy spawning and the
                                        //platform that was created was static then we enter this statement
                                        else if(!breaking && !horizontal && !vertical
                                                &&
                                                random->getInstance()->Bernoulli(enemychance))
                                        {
                                                bool simple = false;
                                                bool complex = false;
                                                float number1 = random->getInstance()->RandomFloat(0, 100);
                                                for (auto& chance1 : EnemyChances){
                                                        if(number1 < chance1.first){
                                                                if (chance1.second == "Simple") {
                                                                        simple = true;
                                                                } else if (chance1.second == "Complex") {
                                                                        complex = true;
                                                                }
                                                                std::shared_ptr<Platform_Model> back =
                                                                    platforms.back();
                                                                if(simple){
                                                                        Vector2f newposition = Vector2f(
                                                                            back->GetPosition().x +
                                                                            (back->GetWidth() / 2) - 1,
                                                                            back->GetPosition().y + back->GetHeight() +2);
                                                                        Enemies.push_back(concreteFactory->
                                                                            CreateSimple_Enemy_Model(newposition,camera));
                                                                }
                                                                if(complex){
                                                                        Vector2f newposition = Vector2f(
                                                                            back->GetPosition().x +
                                                                            (back->GetWidth() / 2) - 1,
                                                                            back->GetPosition().y + back->GetHeight()+1);
                                                                        Enemies.push_back(concreteFactory->
                                                                            CreateComplex_Enemy_Model(newposition,camera));
                                                                }

                                                                break;
                                                        }
                                                }
                                        }

                                        break;
                                }
                        }

                        //We now delete the platform that was under the camera
                        concreteFactory->Pop_Platfrom_Front();
                        platforms.erase(platforms.begin());
                }

                //If our bonus isn't empty and the position of the first bonus is under our camera position
                //then we delete the first bonus
                if (!Bonus.empty() && Bonus[0]->GetPosition().y < currentcameray) {
                        concreteFactory->Pop_Bonus_Front();
                        Bonus.erase(Bonus.begin());
                }

                //We update every background tile model
                for (int i = 0; i < BG.size(); i++) {
                        for (auto tiles : BG[i]) {
                                tiles->Update();
                        }
                }

                //We update every bonus model
                for (int Bon = 0; Bon < Bonus.size(); Bon++) {
                        Bonus[Bon]->Update();
                }

                //Here we decrease the chances for certain platforms, bonuses, the chance for a platform
                //and the chance for a bonus to make it harder the higher you go
                if (int(camera->GetPosition()) % 100 == 0 && camera->GetPosition() != 0 &&
                    PlatformChances[0].first - 2 >= 0) {
                        PlatformChances[0].first -= 4;
                }

                if (int(camera->GetPosition()) % 200 == 0 && camera->GetPosition() != 0 &&
                    PlatformChances[1].first - 3 >= 0) {
                        PlatformChances[1].first -= 3;
                }

                if (int(camera->GetPosition()) % 150 == 0 && camera->GetPosition() != 0 &&
                    platchance - 0.03 > 0.15) {
                        platchance -= 0.03;
                }

                if (int(camera->GetPosition()) % 150 == 0 && camera->GetPosition() != 0 &&
                    BonusChances[0].first - 1.5 > 0) {
                        BonusChances[0].first -= 1.5;
                }

                if (int(camera->GetPosition()) % 350 == 0 && camera->GetPosition() != 0 &&
                    BonusChances[1].first - 2.5 > 15) {
                        BonusChances[1].first -= 2.5;
                }

                score->HandleEvent(player->GetPosition().y);
        }
}
void World::BG_TileSpawner()
{
        for (int i = 0; i < YWorldSize.GetY(); i++) {
                std::vector<std::shared_ptr<BG_Tile_Model>> row;
                for (int j = 0; j < XWorldSize.GetY(); j++) {
                        row.push_back(concreteFactory->CreateBG_Tile_Model(Vector2f(j, i), camera));
                }
                BG.push_back(row);
        }
}
void World::PlatformSpawner()
{
        for (int i = 0; i < YWorldSize.y; i++) {
                if (i % 3 == 0) {
                        float horizontal = random->getInstance()->RandomFloat(XWorldSize.x, XWorldSize.y);
                        platforms.push_back(concreteFactory->CreatePlatform_Model(
                            Vector2f(horizontal, i), false, false, false, false, false, camera));
                }
        }
}
bool World::getGameEnded() const {return camera->getGameEnded();}

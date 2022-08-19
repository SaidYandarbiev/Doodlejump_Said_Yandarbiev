//
// Created by said2 on 17-11-2021.
//

#include "Concrete_Factory.h"
Concrete_Factory::Concrete_Factory(Vector2f windowsize) { RenderWindowSize = windowsize; }
std::shared_ptr<Player_Model> Concrete_Factory::CreatePlayer_Model(Vector2f vector2I,
                                                                   std::shared_ptr<Utility::Camera> camera)
{
        //First we create a player model
        std::shared_ptr<Player_Model> players = std::make_shared<Player_Model>(vector2I.x, vector2I.y, camera);

        //Then we create a player view
        std::shared_ptr<Player_View> playerz = CreatePlayer_View(vector2I, players->GetDirection());

        player = playerz;

        //We add the player views to the observers of the player model
        players->AddPlayer(playerz);

        //We return the player model
        return players;
}
std::shared_ptr<Platform_Model> Concrete_Factory::CreatePlatform_Model(Vector2f vector2I, bool vertical,
                                                                       bool horizontal, bool breaking, bool broken,
                                                                       bool notmoving,
                                                                       std::shared_ptr<Utility::Camera> camera)
{
        //First we create a platform model
        std::shared_ptr<Platform_Model> platformModel = std::make_shared<Platform_Model>(vertical, horizontal, breaking,notmoving, vector2I, camera);

        //Then we calculate the position of the platform in pixels
        Vector2f pixels = camera->PositionInPixels(vector2I);

        //Then we create the platform view
        std::shared_ptr<Platform_View> platformView = CreatePlatform_View(pixels, vertical, horizontal, breaking, broken, notmoving);

        //Lastly we add the platform view to the observers of the platform model
        platformModel->AddPlatform(platformView);

        return platformModel;
}
std::shared_ptr<BG_Tile_Model> Concrete_Factory::CreateBG_Tile_Model(Vector2f vector2I,
                                                                     std::shared_ptr<Utility::Camera> camera)
{
        //First we create a background tile model
        std::shared_ptr<BG_Tile_Model> bgTileModel = std::make_shared<BG_Tile_Model>(vector2I, camera);

        //We then calculate the factorx that we have to multiply the position of the backrground tile view with
        float factorx = camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y;
        factorx = factorx / 18;

        //We create a backrgound view
        std::shared_ptr<BG_Tile_View> bgTileView = CreateBG_Tile_View(vector2I, factorx);

        BG_Tile.push_back(bgTileView);

        //Lastly, we add the background tile view to the observers of the backrgound tile model
        bgTileModel->SetBG_Tile_View(bgTileView);
        return bgTileModel;
}
std::shared_ptr<Bonus_Model> Concrete_Factory::CreateBonus_Model(Vector2f vector2I, bool spring, bool helicopter,
                                                                 bool health, bool spikes,
                                                                 std::shared_ptr<Utility::Camera> camera)
{
        //First we create a bonus model
        std::shared_ptr<Bonus_Model> bonusModel = std::make_shared<Bonus_Model>(vector2I, spring, helicopter, health, spikes, camera);

        //Then we calculate the position of the bonus view in pixels
        Vector2f pixels = camera->PositionInPixels(vector2I);

        //We create a bonus view
        std::shared_ptr<Bonus_View> bonusView = CreateBonus_View(pixels, spring,helicopter,health,spikes);

        //Lastly we add the bonus view to the observers of the bonus model
        bonusModel->AddBonus(bonusView);
        bonusModel->SetPosition(vector2I);

        return bonusModel;
}
std::shared_ptr<Simple_Enemy_Model> Concrete_Factory::CreateSimple_Enemy_Model(Vector2f vector2I,
                                                                               std::shared_ptr<Utility::Camera> camera)
{
        //First we create a simple enemy model
        std::shared_ptr<Simple_Enemy_Model> simpleEnemyModel = std::make_shared<Simple_Enemy_Model>(vector2I,camera);

        //Then we calculate the position of the simple enemy view in pixels
        Vector2f pixels = camera->PositionInPixels(vector2I);

        //We create a simple enemy view
        std::shared_ptr<Simple_Enemy_View> simpleEnemyView = CreateSimple_Enemy_View(pixels);

        //Lastly we add the simple enemy view to the observers of the simple enemy model
        simpleEnemyModel->Add_Enemy(simpleEnemyView);
        simpleEnemyModel->SetPosition(vector2I);

        return simpleEnemyModel;
}
std::shared_ptr<Complex_Enemy_Model> Concrete_Factory::CreateComplex_Enemy_Model(
    Vector2f vector2I, std::shared_ptr<Utility::Camera> camera)
{
        //First we create a complex enemy model
        std::shared_ptr<Complex_Enemy_Model> complexEnemyModel = std::make_shared<Complex_Enemy_Model>(vector2I,camera);

        //Then we calculate the position of the complex enemy view in pixels
        Vector2f pixels = camera->PositionInPixels(vector2I);

        //We create a complex enemy view
        std::shared_ptr<Complex_Enemy_View> complexEnemyView = CreateComplex_Enemy_View(pixels);

        //Lastly we add the complex enemy view to the observers of the complex enemy model
        complexEnemyModel->Add_Enemy(complexEnemyView);
        complexEnemyModel->SetPosition(vector2I);

        return complexEnemyModel;
}
std::shared_ptr<Ball_Model> Concrete_Factory::CreateBall_Model(Vector2f vector2I, bool enemy, bool player,
                                                               std::shared_ptr<Utility::Camera> camera)
{
        //First we create a ballmodel
        std::shared_ptr<Ball_Model> ballModel = std::make_shared<Ball_Model>(vector2I, enemy, player, camera);

        //Then we calculate the position of the ball view in pixels
        Vector2f pixels = camera->PositionInPixels(vector2I);

        //We create a ball view
        std::shared_ptr<Ball_View> ballView = CreateBall_View(pixels);

        //Lastly we add the ball view to the observers of the ball model
        ballModel->AddObserver(ballView);
        ballModel->SetPosition(vector2I);

        return ballModel;
}
std::shared_ptr<Player_View> Concrete_Factory::CreatePlayer_View(Vector2f vector2I, Direction direction)
{
        //We create a player view and return it
        std::shared_ptr<Player_View> playerView = std::make_shared<Player_View>(vector2I, direction);
        player = playerView;
        return playerView;
}
std::shared_ptr<Platform_View> Concrete_Factory::CreatePlatform_View(Vector2f vector2I, bool vertical, bool horizontal,
                                                                     bool breaking, bool broken, bool notmoving)
{
        //We create a platform view and return it
        std::shared_ptr<Platform_View> platformView = std::make_shared<Platform_View>(breaking, vertical, horizontal, broken, notmoving, vector2I);

        platforms.push_back(platformView);

        return platformView;
}
std::shared_ptr<BG_Tile_View> Concrete_Factory::CreateBG_Tile_View(Vector2f vector2I, float x)
{
        //We create a backrgound tile view and return it
        std::shared_ptr<BG_Tile_View> bgTileView = std::make_shared<BG_Tile_View>(vector2I, x);
        BG_Tile.push_back(bgTileView);
        return bgTileView;
}
std::shared_ptr<Bonus_View> Concrete_Factory::CreateBonus_View(Vector2f vector2I, bool spring, bool copter, bool health,
                                                               bool spikes)
{
        //We create a bonus view and return it
        std::shared_ptr<Bonus_View> bonusView = std::make_shared<Bonus_View>(vector2I, spring, copter, health, spikes);
        Bonus.push_back(bonusView);

        return bonusView;
}
std::shared_ptr<Simple_Enemy_View> Concrete_Factory::CreateSimple_Enemy_View(Vector2f vector2I)
{
        //We create a simple enemy view and return it
        std::shared_ptr<Simple_Enemy_View> simpleEnemyView = std::make_shared<Simple_Enemy_View>(vector2I);
        Enemy.push_back(simpleEnemyView);

        return simpleEnemyView;
}
std::shared_ptr<Complex_Enemy_View> Concrete_Factory::CreateComplex_Enemy_View(Vector2f vector2F)
{
        //We create a complex enemy view and return it
        std::shared_ptr<Complex_Enemy_View> complexEnemyView = std::make_shared<Complex_Enemy_View>(vector2F);
        Enemy.push_back(complexEnemyView);

        return complexEnemyView;
}
std::shared_ptr<Ball_View> Concrete_Factory::CreateBall_View(Vector2f vector2F)
{
        //We create a ball view and return it
        std::shared_ptr<Ball_View> ballView = std::make_shared<Ball_View>(vector2F);
        Shots.push_back(ballView);

        return ballView;
}

void Concrete_Factory::Pop_Bonus_Front() { Bonus.erase(Bonus.begin()); }

void Concrete_Factory::Pop_Platfrom_Front() { platforms.erase(platforms.begin()); }

std::vector<std::shared_ptr<Observer>> Concrete_Factory::GetPlatform() const { return platforms; }

std::vector<std::shared_ptr<Observer>> Concrete_Factory::GetBG_Tile() const { return BG_Tile; }

std::vector<std::shared_ptr<Observer>> Concrete_Factory::GetBonus() const { return Bonus; }

std::vector<std::shared_ptr<Observer>> Concrete_Factory::GetEnemy() const {return Enemy;}

std::shared_ptr<Observer> Concrete_Factory::GetPlayer() const { return player; }

std::vector<std::shared_ptr<Observer>> Concrete_Factory::GetShots() const { return Shots; }

void Concrete_Factory::SetPlatforms(std::vector<std::shared_ptr<Observer>> plat) { platforms = plat; }

void Concrete_Factory::Delete_platform_it(std::shared_ptr<Platform_Model> plat)
{
        auto it = std::find(platforms.begin(), platforms.end(), plat->GetView());
        platforms.erase(it);
}
void Concrete_Factory::Delete_enemy_it(std::shared_ptr<Entity_Model> enemy)
{
        auto it = std::find(Enemy.begin(), Enemy.end(), enemy->GetView());
        Enemy.erase(it);
}
void Concrete_Factory::Delete_bonus_it(std::shared_ptr<Bonus_Model> bonus)
{
        auto it = std::find(Bonus.begin(), Bonus.end(), bonus->GetView());
        Bonus.erase(it);
}
void Concrete_Factory::Delete_Shot_It(std::shared_ptr<Ball_Model> ball)
{
        auto it = std::find(Shots.begin(), Shots.end(), ball->GetView());
        Shots.erase(it);
}

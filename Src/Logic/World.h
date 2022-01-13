//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_WORLD_H
#define DOODLEJUMP_SAID_YANDARBIEV_WORLD_H

#include "../Game_Representation/Concrete_Factory.h"
#include "../Vector2.h"
#include "Camera.h"
#include "Random.h"
#include "SFML/Graphics.hpp"
#include "States.h"
#include "iostream"
#include "string"
#include "vector"
#include <algorithm>

class World
{
public:
        World(Vector2u l_windSize, Concrete_Factory* confac)
        {

                m_windowSize = l_windSize;
                concreteFactory = confac;
                camera = new Camera(m_windowSize);
                player = confac->CreatePlayer_Model(Vector2f(10, 30), camera);
                currentcameray = camera->GetPosition();
                states = new States();

                BG_TileSpawner();
                PlatformSpawner();

                PlatformChances.push_back(std::make_pair(50, "Static"));
                PlatformChances.push_back(std::make_pair(70, "Horizontal"));
                PlatformChances.push_back(std::make_pair(90, "Vertical"));
                PlatformChances.push_back(std::make_pair(100, "Breaking"));

                BonusChances.push_back(std::make_pair(50, "Spring"));
                BonusChances.push_back(std::make_pair(100, "Copter"));
        };

        void Update()
        {
                previouscameray = currentcameray;
                player->Update(states, m_windowSize, XWorldSize.GetY());
                currentcameray = camera->GetPosition();

                for (int i = 0; i < BG.size(); i++) {
                        if (BG[i][0]->GetPosition().GetY() < currentcameray) {
                                std::vector<BG_Tile_Model*> row = BG[i];
                                BG.erase(BG.begin() + i);
                                std::vector<BG_Tile_Model*> back = BG.back();
                                for (auto& tiles : row) {
                                        tiles->SetPosition(
                                            Vector2f(tiles->GetPosition().GetX(), back[0]->GetPosition().GetY() + 1));
                                }
                                BG.push_back(row);
                        }
                }

                float x = player->GetPosition().GetX();
                float y = player->GetPosition().GetY();

                if (player->GetFalling()) {
                        for (int plat = 0; plat < platforms.size(); plat++) {

                                if (player->CheckCollision(platforms[plat]->GetPosition().x,
                                                           platforms[plat]->GetPosition().y, x, y, player->GetWidth(),
                                                           platforms[0]->GetWidth(), platforms[0]->GetHeight(),
                                                           player->GetHeight())) {
                                        player->Platformhit(platforms[plat]);
                                        Vector2f newposition =
                                            Vector2f(player->GetPosition().x,
                                                     platforms[plat]->GetPosition().y + player->GetHeight());
                                        player->SetPosition(newposition);
                                        if (platforms[plat]->GetBreaking()) {
                                                platforms[plat]->Broken();
                                        }
                                        break;
                                }
                        }

                        for (auto& bonus : Bonus) {
                                if (player->CheckCollision(bonus->GetPosition().x, bonus->GetPosition().y, x, y,
                                                           player->GetWidth(), bonus->GetWidth(), bonus->GetHeight(),
                                                           player->GetHeight()) &&
                                    bonus->GetSpring()) {
                                        player->Bonus_hit();
                                        Vector2f newposition = Vector2f(player->GetPosition().x,
                                                                        bonus->GetPosition().y + player->GetHeight());
                                        player->SetPosition(newposition);
                                        bonus->PlayerTouched();
                                        break;
                                }
                        }
                }

                for (auto& bonus : Bonus) {
                        if (player->CheckCollision(bonus->GetPosition().x, bonus->GetPosition().y, x, y,
                                                   player->GetWidth(), bonus->GetWidth(), bonus->GetHeight(),
                                                   player->GetHeight()) &&
                            bonus->GetCopter()) {
                                player->Copterhit();
                                concreteFactory->Delete_bonus_it(bonus);
                                bonus->deleteview();
                                auto it = std::find(Bonus.begin(), Bonus.end(), bonus);
                                delete *it;
                                Bonus.erase(it);
                                break;
                        }
                }
                auto it = platforms.begin();
                bool broken = false;

                for (auto& plat : platforms) {
                        if (plat->GetBroken()) {
                                concreteFactory->Delete_platform_it(plat);
                                plat->DeleteView();
                                it = std::find(platforms.begin(), platforms.end(), plat);
                                broken = true;
                                break;
                        }
                        plat->Update();
                }

                if (broken) {
                        delete *it;
                        platforms.erase(it);
                }

                if (random->getInstance()->Bernouilli(platchance) && platforms[0]->GetPosition().y < currentcameray) {
                        float number = random->getInstance()->RandomFloat(0, 100);
                        for (auto& chance : PlatformChances) {
                                if (number < chance.first) {
                                        bool breaking = false;
                                        bool horizontal = false;
                                        bool vertical = false;

                                        if (chance.second == "Horizontal") {
                                                horizontal = true;
                                        } else if (chance.second == "Vertical") {
                                                vertical = true;
                                        } else if (chance.second == "Breaking") {
                                                breaking = true;
                                        }

                                        float h = random->getInstance()->RandomFloat(XWorldSize.x, XWorldSize.y);
                                        Platform_Model* back = platforms.back();
                                        platforms.push_back(concreteFactory->CreatePlatform_Model(
                                            Vector2f(h, back->GetPosition().y + 3), vertical, horizontal, breaking,
                                            false, camera));

                                        if (!breaking && !horizontal && !vertical) {
                                                Platform_Model* back = platforms.back();

                                                Vector2f newposition =
                                                    Vector2f(back->GetPosition().x + (back->GetWidth() / 2),
                                                             back->GetPosition().y + back->GetHeight());
                                                Bonus.push_back(concreteFactory->CreateBonus_Model(newposition, true,
                                                                                                   false, camera));
                                        }

                                        break;
                                }
                        }

                        platforms[0]->DeleteView();
                        concreteFactory->Pop_Platfrom_Front();
                        delete platforms[0];
                        platforms.erase(platforms.begin());
                }

                if (!Bonus.empty() && Bonus[0]->GetPosition().y < currentcameray) {
                        Bonus[0]->deleteview();
                        concreteFactory->Pop_Bonus_Front();
                        delete Bonus[0];
                        Bonus.erase(Bonus.begin());
                }

                for (int i = 0; i < BG.size(); i++) {
                        for (auto tiles : BG[i]) {
                                tiles->Update();
                        }
                }

                for (int Bon = 0; Bon < Bonus.size(); Bon++) {
                        Bonus[Bon]->Update();
                }

                if (int(camera->GetPosition()) % 200 == 0 && camera->GetPosition() != 0 &&
                    PlatformChances[0].first - 2 >= 0) {
                        PlatformChances[0].first -= 2;
                }

                if (int(camera->GetPosition()) % 700 == 0 && camera->GetPosition() != 0 &&
                    PlatformChances[1].first - 3 >= 0) {
                        PlatformChances[1].first -= 3;
                }

                if (int(camera->GetPosition()) % 1000 == 0 && camera->GetPosition() != 0 &&
                    PlatformChances[2].first - 4 >= 0) {
                        PlatformChances[2].first -= 4;
                }

                if (int(camera->GetPosition()) % 750 == 0 && camera->GetPosition() != 0 && platchance - 0.03 > 0) {
                        platchance -= 0.03;
                }
        }

        States* GetState() { return states; }

        ~World() {}

        void BG_TileSpawner()
        {
                for (int i = 0; i < YWorldSize.GetY(); i++) {
                        std::vector<BG_Tile_Model*> row;
                        for (int j = 0; j < XWorldSize.GetY(); j++) {
                                row.push_back(concreteFactory->CreateBG_Tile_Model(Vector2f(j, i), camera));
                        }
                        BG.push_back(row);
                }
        }

        void PlatformSpawner()
        {
                for (int i = 0; i < YWorldSize.y; i++) {
                        if (i % 3 == 0) {
                                float horizontal = random->getInstance()->RandomFloat(XWorldSize.x, XWorldSize.y);
                                platforms.push_back(concreteFactory->CreatePlatform_Model(
                                    Vector2f(horizontal, i), false, false, false, false, camera));
                        }
                }
        }

        Player_Model* GetPlayer() { return player; }

private:
        Vector2u m_windowSize = Vector2u(0, 0);
        Concrete_Factory* concreteFactory;

        Vector2f XWorldSize = Vector2f(0, 20);
        Vector2f YWorldSize = Vector2f(0, 60);

        Player_Model* player = nullptr;
        std::vector<Platform_Model*> platforms;
        std::vector<std::vector<BG_Tile_Model*>> BG;
        std::vector<Bonus_Model*> Bonus;
        Camera* camera;

        Random* random;

        float previouscameray;
        float currentcameray;

        //{static,horizontal,vertical,breaking}
        std::vector<std::pair<float, std::string>> PlatformChances = {};
        std::vector<std::pair<float, std::string>> BonusChances = {};
        float platchance = 0.95;
        float bonuschance = 0.2;
        States* states = nullptr;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_WORLD_H

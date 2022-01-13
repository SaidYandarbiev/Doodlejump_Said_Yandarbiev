//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_CONCRETE_FACTORY_H
#define DOODLEJUMP_SAID_YANDARBIEV_CONCRETE_FACTORY_H

#include "../Logic/Abstract_Factory.h"

class Concrete_Factory
{
public:
        Concrete_Factory(Vector2f windowsize) { RenderWindowSize = windowsize; }

        Player_Model* CreatePlayer_Model(Vector2f vector2I, Camera* camera)
        {

                Player_Model* players = new Player_Model(vector2I.x, vector2I.y, camera);

                Player_View* playerz = CreatePlayer_View(vector2I, players->GetDirection());

                player = playerz;
                players->AddPlayer(playerz);

                return players;
        }

        Platform_Model* CreatePlatform_Model(Vector2f vector2I, bool vertical, bool horizontal, bool breaking,
                                             bool broken, Camera* camera)
        {

                Platform_Model* platformModel = new Platform_Model(vertical, horizontal, breaking, vector2I, camera);
                Vector2f pixels = camera->PositionInPixels(vector2I);
                Platform_View* platformView = CreatePlatform_View(pixels, vertical, horizontal, breaking, broken);

                platformModel->AddPlatform(platformView);

                return platformModel;
        }

        BG_Tile_Model* CreateBG_Tile_Model(Vector2f vector2I, Camera* camera)
        {
                BG_Tile_Model* bgTileModel = new BG_Tile_Model(vector2I, camera);
                float factorx = camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y;
                factorx = factorx / 18;
                BG_Tile_View* bgTileView = CreateBG_Tile_View(vector2I, factorx);
                BG_Tile.push_back(bgTileView);

                bgTileModel->SetBG_Tile_View(bgTileView);
                return bgTileModel;
        }

        Bonus_Model* CreateBonus_Model(Vector2f vector2I, bool spring, bool helicopter, Camera* camera)
        {
                Bonus_Model* bonusModel = new Bonus_Model(vector2I, spring, helicopter, camera);
                Vector2f pixels = camera->PositionInPixels(vector2I);
                Bonus_View* bonusView = CreateBonus_View(pixels, bonusModel->GetSpring());

                bonusModel->AddBonus(bonusView);
                bonusModel->SetPosition(vector2I);

                return bonusModel;
        }

        Player_View* CreatePlayer_View(Vector2f vector2I, Direction direction)
        {
                Player_View* playerView = new Player_View(vector2I, direction);
                player = playerView;
                return playerView;
        }

        Platform_View* CreatePlatform_View(Vector2f vector2I, bool vertical, bool horizontal, bool breaking,
                                           bool broken)
        {
                Platform_View* platformView = new Platform_View(breaking, vertical, horizontal, broken, vector2I);

                platforms.push_back(platformView);

                return platformView;
        }

        BG_Tile_View* CreateBG_Tile_View(Vector2f vector2I, float x)
        {
                BG_Tile_View* bgTileView = new BG_Tile_View(vector2I, x);
                BG_Tile.push_back(bgTileView);
                return bgTileView;
        }

        Bonus_View* CreateBonus_View(Vector2f vector2I, bool spring)
        {
                Bonus_View* bonusView = new Bonus_View(vector2I, spring);
                Bonus.push_back(bonusView);

                return bonusView;
        }

        void Pop_Bonus_Front() { Bonus.erase(Bonus.begin()); }

        void Pop_Platfrom_Front() { platforms.erase(platforms.begin()); }

        std::vector<Observer*> GetPlatform() { return platforms; }

        std::vector<Observer*> GetBG_Tile() { return BG_Tile; }

        std::vector<Observer*> GetBonus() { return Bonus; }

        Observer* GetPlayer() { return player; }

        void SetPlatforms(std::vector<Observer*> plat) { platforms = plat; }

        void Delete_platform_it(Platform_Model* plat)
        {
                auto it = std::find(platforms.begin(), platforms.end(), plat->GetView());
                platforms.erase(it);
        }

        void Delete_bonus_it(Bonus_Model* bonus)
        {
                auto it = std::find(Bonus.begin(), Bonus.end(), bonus->GetView());
                Bonus.erase(it);
        }

private:
        std::vector<Observer*> platforms = {};
        std::vector<Observer*> BG_Tile = {};
        std::vector<Observer*> Bonus = {};
        Observer* player = nullptr;
        Vector2f RenderWindowSize = Vector2f(0, 0);
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_CONCRETE_FACTORY_H

//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_MODEL_H

#include "../Game_Representation/BG_Tile_View.h"
#include "Camera.h"
#include "Entity_Model.h"

//Class representing the model of a BG tile
class BG_Tile_Model : public Entity_Model
{
public:
        //Constructor
        BG_Tile_Model(Vector2f pos, std::shared_ptr<Utility::Camera> cam);

        //Updates the bg tile
        void Update();

        //This function returns the positions of the bg tile model
        Vector2f GetPosition() const override;

        //This function sets the position of the bg tile model
        void SetPosition(Vector2f pos) override;

        //This function sets the bg tile view of the bg tile model
        void SetBG_Tile_View(std::shared_ptr<BG_Tile_View> bgTileView);

        //This function returns the width of the bg tile model
        float GetWidth() const;

        //This function returns the height of the bg tile model
        float GetHeight() const;

        //This function returns the bg tile view of the bg tile model
        std::shared_ptr<BG_Tile_View> Get_BG_TileView() const;

private:
        std::shared_ptr<BG_Tile_View> bg = nullptr;
        float width = 1;
        float height = 1;
        std::shared_ptr<Utility::Camera> camera;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_MODEL_H

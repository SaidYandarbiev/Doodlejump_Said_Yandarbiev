//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_MODEL_H

#include "../Game_Representation/BG_Tile_View.h"
#include "Camera.h"
#include "Entity_Model.h"

class BG_Tile_Model : public Entity_Model
{
public:
        BG_Tile_Model(Vector2f pos, Camera* cam)
        {
                position = pos;
                camera = cam;
        }

        void Update()
        {
                Vector2f pixels = camera->PositionInPixels(position);
                float playergamesizex = (camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y) * width;
                float playergamesizey = (camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().y) * height;

                float factorx = playergamesizex / bg->GetWidth();
                float factory = playergamesizey / bg->GetHeight();

                bg->HandleEvent(pixels, factorx, factory);
        }

        Vector2f GetPosition() { return position; }

        void SetPosition(Vector2f pos)
        {
                position = pos;
                Vector2f pixels = camera->PositionInPixels(position);

                float playergamesizex = (camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y) * width;
                float playergamesizey = (camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().y) * height;

                float factorx = playergamesizex / bg->GetWidth();
                float factory = playergamesizey / bg->GetHeight();

                bg->HandleEvent(pixels, factorx, factory);
        }

        void SetBG_Tile_View(BG_Tile_View* bgTileView) { bg = bgTileView; }

        float GetWidth() { return width; }

        float GetHeight() { return height; }

        BG_Tile_View* Get_BG_TileView() { return bg; }

private:
        BG_Tile_View* bg = nullptr;

        float width = 1;
        float height = 1;

        Camera* camera;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_MODEL_H

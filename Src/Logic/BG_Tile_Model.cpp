//
// Created by said2 on 17-11-2021.
//

#include "BG_Tile_Model.h"
BG_Tile_Model::BG_Tile_Model(Vector2f pos, std::shared_ptr<Utility::Camera> cam)
{
        position = pos;
        camera = cam;
}
void BG_Tile_Model::Update()
{
        Vector2f pixels = camera->PositionInPixels(position);
        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,bg->GetWidth(),bg->GetHeight());

        bg->HandleEvent(pixels, vec[0], vec[1]);
}
Vector2f BG_Tile_Model::GetPosition() const { return position; }

void BG_Tile_Model::SetPosition(Vector2f pos)
{
        position = pos;
        Vector2f pixels = camera->PositionInPixels(position);

        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,bg->GetWidth(),bg->GetHeight());

        bg->HandleEvent(pixels, vec[0], vec[1]);
}

void BG_Tile_Model::SetBG_Tile_View(std::shared_ptr<BG_Tile_View> bgTileView) { bg = bgTileView; }

float BG_Tile_Model::GetWidth() const { return width; }

float BG_Tile_Model::GetHeight() const { return height; }

std::shared_ptr<BG_Tile_View> BG_Tile_Model::Get_BG_TileView() const { return bg; }

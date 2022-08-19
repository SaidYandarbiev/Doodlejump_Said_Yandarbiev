//
// Created by said2 on 17-11-2021.
//

#include "BG_Tile_View.h"
BG_Tile_View::BG_Tile_View(Vector2f pos, float scale)
{
        texture.loadFromFile("BG_tile.png");
        sprite->setTexture(texture);
        sprite->setPosition(pos.x, pos.y);
        sprite->setScale(scale, scale);
}
void BG_Tile_View::HandleEvent(Vector2f vector2I, float factorx, float factory)
{
        sprite->setPosition(vector2I.x, vector2I.y);
        sprite->setScale(factorx, factory);
}

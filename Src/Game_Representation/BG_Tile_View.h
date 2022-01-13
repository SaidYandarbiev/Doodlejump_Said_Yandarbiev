//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_VIEW_H

#include "Entity_view.h"

class BG_Tile_View : public Entity_view
{

public:
        BG_Tile_View(Vector2f pos, float scale)
        {
                texture.loadFromFile("BG_tile.png");
                sprite->setTexture(texture);
                sprite->setPosition(pos.x, pos.y);
                sprite->setScale(scale, scale);
        }

        void HandleEvent(Vector2f vector2I, float factorx, float factory)
        {
                sprite->setPosition(vector2I.x, vector2I.y);
                sprite->setScale(factorx, factory);
        }
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_VIEW_H

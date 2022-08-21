//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_VIEW_H

#include "Entity_view.h"

//Class representing the view of the Background tiles
class BG_Tile_View : public Entity_view
{

public:
        //Constructor
        BG_Tile_View(Vector2f pos, float scale);

        //Event handled every update
        void HandleEvent(Vector2f vector2I, float factorx, float factory) override;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BG_TILE_VIEW_H

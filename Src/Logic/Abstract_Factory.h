//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_ABSTRACT_FACTORY_H
#define DOODLEJUMP_SAID_YANDARBIEV_ABSTRACT_FACTORY_H

#include "../Game_Representation/Entity_view.h"
#include "BG_Tile_Model.h"
#include "Bonus_Model.h"
#include "Platform_Model.h"
#include "Player_Model.h"

#include "../Vector2.h"

class Abstract_Factory
{

        Abstract_Factory() {}
        virtual Entity_Model* CreatePlayer(Vector2i vector2I, Direction direction) = 0;

        virtual Entity_Model* CreatePlatform(Vector2i vector2I, bool vertical, bool horizontal, bool breaking) = 0;

        virtual Entity_Model* CreateBG_Tile(Vector2i vector2I) = 0;

        virtual Entity_Model* CreateBonus(Vector2i vector2I, Platform_Model* platformModel, bool spring) = 0;

        virtual Entity_view* CreatePlayer_View() = 0;

        virtual Entity_view* CreatePlatform_View() = 0;

        virtual Entity_view* CreateBG_Tile_View() = 0;

        virtual Entity_view* CreateBonus_View() = 0;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_ABSTRACT_FACTORY_H

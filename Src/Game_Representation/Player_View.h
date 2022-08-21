//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLAYER_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLAYER_VIEW_H

#include "Entity_view.h"
#include "iostream"

//Class representing the view of the player
class Player_View : public Entity_view
{
public:
        //Constructor
        Player_View(Vector2f pos, Direction direction);

        //Event handled every update
        void HandleEvent(Vector2f pos, bool flying, Direction direction, float factorx, float factory, bool shooting) override;

        //Function that returns the width of the player
        double GetWidth() const;

        //Function that returns the height of the player
        double GetHeight() const;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLAYER_VIEW_H

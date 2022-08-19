//
// Created by said2 on 8-8-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BALL_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_BALL_VIEW_H
#include "Entity_view.h"

//Class representing the view of the shot of a player or a complex enemy
class Ball_View: public Entity_view
{
public:
        //Constructor
        explicit Ball_View(Vector2f pos);

        //Event handled every update
        void HandleEvent(Vector2f vector2F, float factorx, float factory) override;


};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BALL_VIEW_H

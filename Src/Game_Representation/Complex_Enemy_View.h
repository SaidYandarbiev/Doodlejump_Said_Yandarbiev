//
// Created by said2 on 21-7-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_COMPLEX_ENEMY_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_COMPLEX_ENEMY_VIEW_H

#include "Entity_view.h"

//Class representing the view of a complex enemy
class Complex_Enemy_View : public Entity_view
{
public:
        //Constructor
        explicit Complex_Enemy_View(Vector2f vector2I);

        //Event handled every update
        void HandleEvent(Vector2f vector2I, float factorx, float factory, bool shooting) override;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_COMPLEX_ENEMY_VIEW_H

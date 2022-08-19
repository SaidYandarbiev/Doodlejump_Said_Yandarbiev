//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BONUS_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_BONUS_VIEW_H

#include "Entity_view.h"
#include <iostream>

//Class representing the view of a bonus
class Bonus_View : public Entity_view
{
public:
        //Constructor
        Bonus_View(Vector2f pos, bool spring, bool copter, bool health, bool spikes);

        //Event handled every update
        void HandleEvent(Vector2f pos, bool spring, bool copter, bool triggered, float factorx, float factory);

};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BONUS_VIEW_H

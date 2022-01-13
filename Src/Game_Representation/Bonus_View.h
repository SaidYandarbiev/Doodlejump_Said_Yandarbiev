//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BONUS_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_BONUS_VIEW_H

#include "Entity_view.h"
#include <iostream>

class Bonus_View : public Entity_view
{
public:
        Bonus_View(Vector2f pos, bool spring)
        {
                if (spring) {
                        texture.loadFromFile("spring.png");
                }

                else {
                        texture.loadFromFile("triggered_copter.png");
                }

                sprite->setTexture(texture);
                sprite->setPosition(pos.x, pos.y);
                positie = pos;
        }

        void HandleEvent(Vector2f pos, bool spring, bool copter, bool triggered, float factorx, float factory)
        {
                if (spring && !triggered) {
                        texture.loadFromFile("spring.png");
                        sprite->setPosition(pos.x, pos.y);
                }

                else if (copter) {
                        texture.loadFromFile("triggered_copter.png");
                }

                else if (spring) {
                        texture.loadFromFile("spring_jump.png");
                        sprite->setPosition(pos.x, pos.y - 10);
                }

                sprite->setTexture(texture);

                sprite->setScale(factorx, factory);
        }

        Vector2f positie = Vector2f(0, 0);
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BONUS_VIEW_H

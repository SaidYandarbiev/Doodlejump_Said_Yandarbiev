//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLAYER_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLAYER_VIEW_H

#include "Entity_view.h"
#include "iostream"

class Player_View : public Entity_view
{
public:
        Player_View(Vector2f pos, Direction direction)
        {
                if (direction == Direction::Right) {
                        texture.loadFromFile("doodle-right.png");
                }

                else if (direction == Direction::Left) {
                        texture.loadFromFile("doodle-left.png");
                }

                sprite->setTexture(texture);
                sprite->setPosition(pos.x, pos.y);
                int a = 0;
        }

        void HandleEvent(Vector2f pos, bool flying, Direction direction, float factorx, float factory)
        {
                if (direction == Direction::Right) {
                        if (flying) {
                                texture.loadFromFile("Doodle_Right_Flying.png");
                        }

                        else {
                                texture.loadFromFile("doodle-right.png");
                        }

                }

                else if (direction == Direction::Left) {
                        if (flying) {
                                texture.loadFromFile("Doodle_Left_Flying.png");
                        } else {
                                texture.loadFromFile("doodle-left.png");
                        }
                }

                sprite->setPosition(pos.x, pos.y);

                sprite->setTexture(texture);
                sprite->setScale(factorx, factory);
        }

        double GetWidth() { return sprite->getTexture()->getSize().x; }

        double GetHeight() { return sprite->getTexture()->getSize().y; }
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLAYER_VIEW_H

//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_VIEW_H

#include "Entity_view.h"

class Platform_View : public Entity_view
{
public:
        Platform_View(bool breaker, bool vertical, bool horizontal, bool broken, Vector2f pos)
        {

                if (breaker && !broken) {
                        texture.loadFromFile("breaking_platform.png");
                }

                else if (broken) {
                        texture.loadFromFile("broken_platform.png");
                }

                else if (horizontal || vertical) {
                        texture.loadFromFile("move_panel.png");
                }

                else {
                        texture.loadFromFile("static_panel.png");
                }

                sprite->setTexture(texture);
                sprite->setPosition(pos.x, pos.y);
        }

        double GetWidth() { return sprite->getTexture()->getSize().x; }

        double GetHeight() { return sprite->getTexture()->getSize().y; }

        void SetPosition(Vector2f pos) { sprite->setPosition(pos.x, pos.y); }

        void HandleEvent(Vector2f vector2F, float factorx, float factory)
        {
                sprite->setPosition(vector2F.x, vector2F.y);
                sprite->setScale(factorx, factory);
        }
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_VIEW_H

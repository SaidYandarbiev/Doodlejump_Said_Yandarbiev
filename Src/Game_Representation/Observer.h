//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_OBSERVER_H
#define DOODLEJUMP_SAID_YANDARBIEV_OBSERVER_H

#include "../Vector2.h"
#include "SFML/Graphics.hpp"
#include "string"
enum class Direction
{
        Left,
        Right,
        None
};
class Observer
{
public:
        sf::Sprite* GetSprite() { return sprite; }
        void HandleEvent(Vector2f vector2I)
        {
                sprite->setPosition(vector2I.x, vector2I.y);
                sprite->setTexture(texture);
        }

        void SetPosition(Vector2i vector2I) { sprite->setPosition(vector2I.x, vector2I.y); }

        sf::Sprite* sprite = new sf::Sprite;

protected:
        sf::Texture texture;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_OBSERVER_H

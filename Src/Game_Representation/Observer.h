//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_OBSERVER_H
#define DOODLEJUMP_SAID_YANDARBIEV_OBSERVER_H

#include "../Vector2.h"
#include "SFML/Graphics.hpp"
#include "string"
#include <memory>
enum class Direction
{
        Left,
        Right,
        None
};
class Observer
{
public:
        std::shared_ptr<sf::Sprite> GetSprite() const { return sprite; }
        void HandleEvent(Vector2f vector2I)
        {
                sprite->setPosition(vector2I.x, vector2I.y);
                sprite->setTexture(texture);
        }

        virtual double GetWidth(){return 0;}

        virtual double GetHeight(){return 0;}

        virtual void HandleEvent(Vector2f pos, bool flying, Direction direction, float factorx, float factory){};
        virtual void HandleEvent(Vector2f vector2F, float factorx, float factory){};

        void SetPosition(Vector2i vector2I) const { sprite->setPosition(vector2I.x, vector2I.y); }

        std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>(sf::Sprite());

protected:
        sf::Texture texture;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_OBSERVER_H

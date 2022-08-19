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
//This class gives the direction that the player is facing
{
        Left,
        Right,
        None
};
class Observer
{
public:
        //This function returns the sprite of the observer
        virtual std::shared_ptr<sf::Sprite> GetSprite() const;


        void HandleEvent(Vector2f vector2I);

        //This function returns the width of the observer
        virtual double GetWidth();

        //This function returns the height of the observer
        virtual double GetHeight();

        virtual void HandleEvent(Vector2f pos, bool flying, Direction direction, float factorx, float factory, bool shooting);;

        virtual void HandleEvent(Vector2f vector2F, float factorx, float factory);;

        virtual void HandleEvent(Vector2f vector2F, float factorx, float factory, bool shooting);;

        //This function sets the position of the observer
        void SetPosition(Vector2i vector2I) const;

        //This is the sprite of the observer
        std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>(sf::Sprite());

protected:
        //This is the texture of the observer
        sf::Texture texture;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_OBSERVER_H

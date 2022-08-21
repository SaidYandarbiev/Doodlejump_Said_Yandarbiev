//
// Created by said2 on 8-8-2022.
//

#include "Ball_View.h"
Ball_View::Ball_View(Vector2f pos)
{
        texture.loadFromFile("shot.png");
        sprite->setTexture(texture);
        sprite->setPosition(pos.x,pos.y);
}
void Ball_View::HandleEvent(Vector2f vector2F, float factorx, float factory)
{
        sprite->setPosition(vector2F.x, vector2F.y);
        sprite->setScale(factorx, factory);
}

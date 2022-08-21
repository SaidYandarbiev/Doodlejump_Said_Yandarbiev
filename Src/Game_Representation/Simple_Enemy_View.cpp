//
// Created by said2 on 21-7-2022.
//

#include "Simple_Enemy_View.h"
Simple_Enemy_View::Simple_Enemy_View(Vector2f vector2I)
{
        texture.loadFromFile("Simple_Monster.png");
        sprite->setTexture(texture);
        sprite->setPosition(vector2I.x,vector2I.y);
}
void Simple_Enemy_View::HandleEvent(Vector2f vector2I, float factorx, float factory)
{
        sprite->setPosition(vector2I.x, vector2I.y);
        sprite->setScale(factorx, factory);
}

//
// Created by said2 on 21-7-2022.
//

#include "Complex_Enemy_View.h"
Complex_Enemy_View::Complex_Enemy_View(Vector2f vector2I)
{
        texture.loadFromFile("Images/Complex_Enemy.png");
        sprite->setTexture(texture);
        sprite->setPosition(vector2I.x,vector2I.y);
}
void Complex_Enemy_View::HandleEvent(Vector2f vector2I, float factorx, float factory, bool shooting)
{
        //If the complex enemy is shooting we load in the texture that shows the enemy shooting
        if(shooting){
                texture.loadFromFile("Images/Complex_Enemy_Shoot.png");
        }

        //If the enemy is not shooting we load in the basic texture of the complex enemy
        else{
                texture.loadFromFile("Images/Complex_Enemy.png");
        }
        sprite->setPosition(vector2I.x, vector2I.y);
        sprite->setScale(factorx, factory);
}

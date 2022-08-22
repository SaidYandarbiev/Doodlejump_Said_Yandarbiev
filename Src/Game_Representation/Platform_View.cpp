//
// Created by said2 on 17-11-2021.
//

#include "Platform_View.h"
Platform_View::Platform_View(bool breaker, bool vertical, bool horizontal, bool broken, bool notmoving, Vector2f pos)
{
        //If a platform is a breaking platform then we load in the texture for a breaking platform
        if (breaker && !broken) {
                texture.loadFromFile("Images/breaking_platform.png");
        }

        else if (broken) {
                texture.loadFromFile("Images/broken_platform.png");
        }

        //If a platform is neither a breaking nor a horizontal nor a vertical platform and it only moves after the player touches it
        //Then we load in the texture for this type of platform
        else if(notmoving){
                texture.loadFromFile("Images/jump_panel.png");
        }

        //If a platform is either a horizontal or a vertical platform, we load in this texture
        else if (horizontal || vertical) {
                texture.loadFromFile("Images/move_panel.png");
        }

        //If the platform is just a static platform we load in this texture
        else {
                texture.loadFromFile("Images/static_panel.png");
        }

        sprite->setTexture(texture);
        sprite->setPosition(pos.x, pos.y);
}

double Platform_View::GetWidth() { return sprite->getTexture()->getSize().x; }

double Platform_View::GetHeight() { return sprite->getTexture()->getSize().y; }

void Platform_View::SetPosition(Vector2f pos) { sprite->setPosition(pos.x, pos.y); }

void Platform_View::HandleEvent(Vector2f vector2F, float factorx, float factory)
{
        sprite->setPosition(vector2F.x, vector2F.y);
        sprite->setScale(factorx, factory);
}

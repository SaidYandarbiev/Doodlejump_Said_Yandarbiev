//
// Created by said2 on 17-11-2021.
//

#include "Bonus_View.h"
Bonus_View::Bonus_View(Vector2f pos, bool spring, bool copter, bool health, bool spikes)
{
        //Depending on the type of bonus, we load in a different texture
        if (spring) {
                texture.loadFromFile("spring.png");
        }

        else if(copter){
                texture.loadFromFile("triggered_copter.png");
        }

        else if(health){
                texture.loadFromFile("Health.png");
        }
        else if(spikes){
                texture.loadFromFile("spikes.png");
        }

        sprite->setTexture(texture);
        sprite->setPosition(pos.x, pos.y);
}
void Bonus_View::HandleEvent(Vector2f pos, bool spring, bool copter, bool triggered, float factorx, float factory)
{

        //If the bonus is a spring and it is not yet triggered, the spring has the normal texture
        if (spring && !triggered) {
                texture.loadFromFile("spring.png");
                sprite->setPosition(pos.x, pos.y);
        }

        else if (copter) {
                texture.loadFromFile("triggered_copter.png");
                sprite->setPosition(pos.x, pos.y);
        }

        //If the bonus is a spring and it is touched by the player, then we load in the triggered spring texture
        else if (spring) {
                texture.loadFromFile("spring_jump.png");
                sprite->setPosition(pos.x, pos.y - 10);
        }

        else{
                sprite->setPosition(pos.x - 30, pos.y - 17);
        }

        sprite->setTexture(texture);

        sprite->setScale(factorx, factory);
}

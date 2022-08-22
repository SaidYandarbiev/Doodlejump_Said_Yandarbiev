//
// Created by said2 on 17-11-2021.
//

#include "Player_View.h"
Player_View::Player_View(Vector2f pos, Direction direction)
{
        //If the player is facing right, then the texture for the player facing right is loaded in
        if (direction == Direction::Right) {
                texture.loadFromFile("Images/doodle-right.png");
        }
        //If the player is facing left, then the texture for the player facing left is loaded in
        else if (direction == Direction::Left) {
                texture.loadFromFile("Images/doodle-left.png");
        }

        sprite->setTexture(texture);
        sprite->setPosition(pos.x, pos.y);
}

void Player_View::HandleEvent(Vector2f pos, bool flying, Direction direction, float factorx, float factory,
                              bool shooting)
{
        //if the player is shooting, then the texture for a player shooting is loaded in
        if (shooting){
                texture.loadFromFile("Images/doodle-pow.png");
        }

        //If the player is facing right, then the texture for the player facing right is loaded in
        else if (direction == Direction::Right) {
                //Depending if the player has the helicopter bonus we load in 2 different textures

                //If the player has the helicopter bonus, we load in this texture
                if (flying) {
                        texture.loadFromFile("Images/Doodle_right_flying.png");
                }

                //If the player doesn't have the helicopter bonus then we load in this texture
                else {
                        texture.loadFromFile("Images/doodle-right.png");
                }

        }

        //If the player is facing left, then the texture for the player facing left is loaded in
        else if (direction == Direction::Left) {
                //Depending if the player has the helicopter bonus we load in 2 different textures

                //If the player has the helicopter bonus, we load in this texture
                if (flying) {
                        texture.loadFromFile("Images/Doodle_left_flying.png");
                }
                //If the player doesn't have the helicopter bonus then we load in this texture
                else {
                        texture.loadFromFile("Images/doodle-left.png");
                }
        }

        sprite->setPosition(pos.x, pos.y);

        sprite->setTexture(texture);
        sprite->setScale(factorx, factory);
}

double Player_View::GetWidth() const { return sprite->getTexture()->getSize().x; }

double Player_View::GetHeight() const { return sprite->getTexture()->getSize().y; }

//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLAYER_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLAYER_MODEL_H


#include "Bonus_Model.h"
#include "Camera.h"
#include "Entity_Model.h"
#include "Platform_Model.h"
#include "States.h"
#include "Stopwatch.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include "Hp.h"

class Bonus_Model;

//Class that represents the model of a player
class Player_Model : public Entity_Model
{

public:
        //Constructor
        Player_Model(double x, double y, std::shared_ptr<Utility::Camera> cam);

        //This function updates the position of the model
        void Update(std::shared_ptr<Utility::States> states, Vector2u windowsize, float XworldMax);

        // Changing the direction of the model
        void DirectionChange(Direction direction2);

        // Switching between jumping and falling when platform hit or when peak is reached
        void ToggleJumpingAndFalling();

        //Set the platform hit and set platformhit to true
        void Platformhit(std::shared_ptr<Platform_Model>platform);

        // Set the direction
        void SetDirection(Direction l_dir);

        //Sets the position of the model
        void SetPosition(Vector2f vector2F);

        // Direction
        Direction GetDirection() const;

        //Returns the boolean falling
        bool GetFalling() const;

        //Returns the position of the model
        Vector2f GetPosition() const;

        //Sets spring to true, called when the player hits a spring
        void Bonus_hit();

        //Adds a playerview to the playermodel
        void AddPlayer(const std::shared_ptr<Entity_view>& playerView);

        //Returns the width of the model
        double GetWidth() const;

        //Returns the height of the model
        double GetHeight() const;

        //Sets the copterhit boolean to true, this function is called when the helicopter bonus is hit
        void Copterhit();

        //Returns the hp pointer that belongs to this model
        std::shared_ptr<Hp> GetHp();

        //Sets the collision of the player to false
        void NoCollision();

        //Returns the collision boolean
        bool GetCollision() const;

        //Returns the shooting boolean of the model
        bool GetShooting() const;

        //Sets the shooting boolean to false
        void SetShooting();

private:
        //Vector containing the views belonging to the player
        std::vector<std::shared_ptr<Entity_view>> observerz = {};

        //If falling == true then the player is falling
        bool falling = true;

        //If jumping == true then the player is jumping
        bool jumping = false;

        //If platformhit == true then the player hit a platform
        bool platformhit = false;

        //This variable holds which platform the player hit
        std::shared_ptr<Platform_Model> platform_hit = nullptr;

        //This gives the direction the player is facing
        Direction direction = Direction::Right;

        //If movingleft == true then the player is moving left
        bool movingleft = false;

        //If movingright == true the player is moving right
        bool movingright = false;

        //This is the position of the model
        Vector2f position = Vector2f(10, 30);

        //If spring == true then the player has hit a spring
        bool spring = false;

        //This is the x acceleration of the player
        float xversnelling = 0;

        //This is the x speed of the player
        float xsnelheid = 0;

        //This is the y speed of the player (if the speed is positive he goes down, otherwise up)
        float ysnelheid = 0;

        //This is the weight of the player
        float massa = 50;

        //These are the forces that are dragging the player down
        Vector2f forces = Vector2f(0, 0);

        //Width of the model
        double width = 2;

        //Height of the model
        double height = 3;

        //Camera pointer
        std::shared_ptr<Utility::Camera> camera;

        //If copterhit == true then the player has hit the helicopter bonus
        bool copterhit = false;

        //If flying == true then the player is flying with the helicopter bonus
        bool flying = false;

        //This gives the start and end position of when the player starts flying and when he stops
        Vector2f start_end = Vector2f(0, 0);

        //This is a pointer to the hp class which holds the hp of this player
        std::shared_ptr<Hp> hp = std::make_shared<Hp>(3);

        //If collision == false then the player can't hit platforms and will fall into the void
        bool collision = true;

        //If shooting == true then the player is shooting
        bool shooting = false;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLAYER_MODEL_H

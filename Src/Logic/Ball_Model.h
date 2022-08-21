//
// Created by said2 on 8-8-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BALL_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_BALL_MODEL_H

#include <utility>

#include "Entity_Model.h"
#include "Stopwatch.h"
#include "../Game_Representation/Ball_View.h"
#include "Camera.h"

//Class representing the model of the Ball of the player or an enemy
class Ball_Model : public Entity_Model
{
public:
        //Constructor
        explicit Ball_Model(Vector2f pos, bool enemy, bool player, std::shared_ptr<Utility::Camera> cam);

        //Updates the ball
        void Update();

        //This function returns the enemy boolean
        bool GetEnemy() const;

        //This function returns the player boolean
        bool GetPlayer() const;

        //This function returns the position of the ball
        Vector2f GetPosition() const override;

private:
        //Boolean that says if the ball belongs to an enemy
        bool Enemy = true;

        //Boolean that says if the ball belongs to an player
        bool Player = true;

        //Position of the ball
        Vector2f position = Vector2f(0,0);

        //Float which contains the y speed of the ball
        float ysnelheid = 0;

        //Camera pointer
        std::shared_ptr<Utility::Camera> camera;

        //Width of the ball
        double width = 1;

        //Height of the ball
        double height = 1;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BALL_MODEL_H

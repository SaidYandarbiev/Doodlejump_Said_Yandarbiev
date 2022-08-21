//
// Created by said2 on 21-7-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_COMPLEX_ENEMY_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_COMPLEX_ENEMY_MODEL_H

#include "Enemy_Model.h"
#include "../Game_Representation/Complex_Enemy_View.h"

//Class that represents the model of a complex enemy
class Complex_Enemy_Model : public Enemy_Model
{
public:
        //Constructor
        explicit Complex_Enemy_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera);

        //Function that is called when we need to know if an enemy is shooting
        //It returns true if it is shooting, otherwise it returns false
        bool Shooting() override;;

        void Update() override;

        //Function that returns the view of the enemy model
        std::shared_ptr<Observer> GetView() override;

        //Function that returns the height of the model
        double GetHeight() override;

        //Function that returns the width of the model
        double GetWidth() override;

private:
        //Width of the model
        double width = 3;

        //Height of the model
        double height = 3;

        //The previous y position of the model
        float prevYpos = 40;

        //If boolean shooting == true, then the enemy is shooting
        bool shooting = false;

};

#endif // DOODLEJUMP_SAID_YANDARBIEV_COMPLEX_ENEMY_MODEL_H

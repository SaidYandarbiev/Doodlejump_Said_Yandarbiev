//
// Created by said2 on 21-7-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_SIMPLE_ENEMY_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_SIMPLE_ENEMY_MODEL_H

#include "Enemy_Model.h"
#include "../Game_Representation/Simple_Enemy_View.h"


class Simple_Enemy_Model : public Enemy_Model
{
public:
        //Constructor
        explicit Simple_Enemy_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera);

        //Function that is called when we need to know if an enemy is shooting
        //It returns true if it is shooting, otherwise it returns false
        bool Shooting() override;;

        void Update() override;

        //This function returns the view of the model
        std::shared_ptr<Observer> GetView() override;

        //This function returns the height of the model
        double GetHeight() override;

        //This function returns the width of the model
        double GetWidth() override;
private:

        //Widht of the model
        double width = 2;

        //Height of the model
        double height = 3;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_SIMPLE_ENEMY_MODEL_H

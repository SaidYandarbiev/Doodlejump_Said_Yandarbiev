//
// Created by said2 on 21-7-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_ENEMY_H
#define DOODLEJUMP_SAID_YANDARBIEV_ENEMY_H

#include "../Game_Representation/Entity_view.h"
#include "Camera.h"
#include "Entity_Model.h"
#include "Hp.h"

class Enemy_Model : public Entity_Model
{

public:
        //Constructor
        Enemy_Model()= default;

        //Adds an observer to the model
        virtual void Add_Enemy(const std::shared_ptr<Entity_view>& enemy_view);

        //Function that is called when we need to know if an enemy is shooting
        //It returns true if it is shooting, otherwise it returns false
        virtual bool Shooting();


        virtual void Update();

        //This function returns the height of the model
        virtual double GetHeight();

        //This function returns the width of the model
        virtual double GetWidth();

        //This function returns the hp of the model
        std::shared_ptr<Hp> GetHp();

protected:
        //A pointer to the hp of this model
        std::shared_ptr<Hp> hp;

        //Pointer to the camera of this model
        std::shared_ptr<Utility::Camera> cam;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_ENEMY_H

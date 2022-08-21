//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BONUS_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_BONUS_MODEL_H

#include "../Game_Representation/Bonus_View.h"
#include "Camera.h"
#include "Entity_Model.h"
#include "Platform_Model.h"
#include "Player_Model.h"

class Player_Model;

//Class representing the model of a bonus
class Bonus_Model : public Entity_Model
{
public:
        //Constructor
        Bonus_Model(Vector2f pos, bool spring1, bool helicopter, bool hp, bool spike, std::shared_ptr<Utility::Camera> camera1);

        //Function that is called when a player has touched the bonus
        void PlayerTouched();

        //Function that gives the bonus model the bonus view that belongs to the model
        void AddBonus(std::shared_ptr<Bonus_View> bonusView);

        //Function that sets the position of the bonus model
        void SetPosition(Vector2f vector2I);

        //Function that returns the position of the model
        Vector2f GetPosition() const;

        //Function that returns the spring boolean
        bool GetSpring() const;

        //Function that returns the copter boolean
        bool GetCopter() const;

        void Update();

        //Function that returns the width of the model
        double GetWidth() const;

        //Function that returns the height of the model
        double GetHeight() const;

        //Function that returns the health boolean
        bool GetHealth() const;

        //Function that returns the spikes boolean
        bool GetSpikes() const;

        //Function that returns the view of the model
        std::shared_ptr<Bonus_View> GetView() const;

private:
        //Position of the model
        Vector2f position = Vector2f(0, 0);

        //View of the model
        std::shared_ptr<Bonus_View> bonusView = nullptr;

        //If a player has touched the bonus then trigger == true
        bool trigger = false;

        //If the bonus is a spring then spring == true
        bool spring = false;
        //If the bonus is a helicopter then copter == true
        bool copter = false;
        //If the bonus is health then health == true
        bool health = false;
        //If the bonus is spikes then spikes == true
        bool spikes = false;

        //Width of the model
        double width = 1;
        //Height of the model
        double height = 1;
        std::shared_ptr<Utility::Camera> camera;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BONUS_MODEL_H

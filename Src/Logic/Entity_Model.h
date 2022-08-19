//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_ENTITY_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_ENTITY_MODEL_H

#include "Subject.h"
#include "../Game_Representation/Entity_view.h"

class Entity_Model : public Logic::Subject
{
public:
        //This function returns the position of the model
        virtual Vector2f GetPosition() const;

        //This function sets the position of the model
        virtual void SetPosition(Vector2f pos);

        //This function checks the collision of one model (player) and another model (platform)
        //It returns true if they have collided with eachother, otherwise it returns false
        static bool CheckCollision(float xplatform, float yplatform, float xplayer, float yplayer, double playerwidth,
                            double platformwidth, double height, double playerheight);

        //This function returns the view of the model
        virtual std::shared_ptr<Observer> GetView();
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_ENTITY_MODEL_H

//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_ENTITY_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_ENTITY_MODEL_H

#include "Subject.h"

class Entity_Model : public Subject
{
public:
        virtual Vector2f GetPosition() { return position; }

        virtual void SetPosition(Vector2f pos) {}

        bool CheckCollision(float xplatform, float yplatform, float xplayer, float yplayer, double playerwidth,
                            double platformwidth, double height, double playerheight)
        {

                if ((xplatform <= xplayer + playerwidth) && (xplayer <= (xplatform + platformwidth)) &&
                    (yplatform < yplayer - playerheight) && (yplayer - playerheight < (yplatform + height))) {
                        return true;
                }

                return false;
        }
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_ENTITY_MODEL_H

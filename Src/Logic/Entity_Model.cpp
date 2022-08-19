//
// Created by said2 on 17-11-2021.
//

#include "Entity_Model.h"
Vector2f Entity_Model::GetPosition() const { return position; }

void Entity_Model::SetPosition(Vector2f pos) {}

bool Entity_Model::CheckCollision(float xplatform, float yplatform, float xplayer, float yplayer, double playerwidth,
                                  double platformwidth, double height, double playerheight)
{

        if ((xplatform <= xplayer + playerwidth) && (xplayer <= (xplatform + platformwidth)) &&
            (yplatform < yplayer - playerheight) && (yplayer - playerheight < (yplatform + height))) {
                return true;
        }

        return false;
}

std::shared_ptr<Observer> Entity_Model::GetView() {return observers[0];}

//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_ENTITY_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_ENTITY_VIEW_H

#include "../Logic/Entity_Model.h"
#include "Observer.h"

class Entity_view : public Observer
{

public:
        double GetWidth() { return sprite->getTexture()->getSize().x; }

        double GetHeight() { return sprite->getTexture()->getSize().y; }
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_ENTITY_VIEW_H

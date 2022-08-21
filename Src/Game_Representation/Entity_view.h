//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_ENTITY_VIEW_H
#define DOODLEJUMP_SAID_YANDARBIEV_ENTITY_VIEW_H

#include "../Logic/Entity_Model.h"
#include "../Logic/Observer.h"

//Class representing the view of an entity
class Entity_view : public Observer
{

public:
        //Function that returns the width of an entity
        double GetWidth() override;

        //Function that returns the height of an entity
        double GetHeight() override;

        //Function that returns the sprite of an entity
        std::shared_ptr<sf::Sprite> GetSprite() const;


};

#endif // DOODLEJUMP_SAID_YANDARBIEV_ENTITY_VIEW_H

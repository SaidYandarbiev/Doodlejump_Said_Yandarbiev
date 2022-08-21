//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_SUBJECT_H
#define DOODLEJUMP_SAID_YANDARBIEV_SUBJECT_H

#include "../Vector2.h"
#include "Observer.h"
#include "vector"
#include "SFML/Graphics.hpp"
namespace Logic{
class Subject
{
public:
        //Function used to notify observers
        void NotifyObservers()
        {
                for (int i = 0; i < observers.size(); i++) {
                        observers[i]->HandleEvent(position);
                }
        }

        //Function used to add an observer
        void AddObserver(std::shared_ptr<Observer> observer) { observers.push_back(observer); }

protected:
        //Position of the subject
        Vector2f position = Vector2f(0, 0);

        //Vector with all the observers
        std::vector<std::shared_ptr<Observer>> observers;
};
}


#endif // DOODLEJUMP_SAID_YANDARBIEV_SUBJECT_H

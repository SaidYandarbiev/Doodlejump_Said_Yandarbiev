//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_SUBJECT_H
#define DOODLEJUMP_SAID_YANDARBIEV_SUBJECT_H

#include "../Game_Representation/Observer.h"
#include "../Vector2.h"
#include "vector"

class Subject
{
public:
        void NotifyObservers()
        {
                for (int i = 0; i < observers.size(); i++) {
                        observers[i]->HandleEvent(position);
                }
        }

        void AddObserver(Observer* observer) { observers.push_back(observer); }

protected:
        Vector2f position = Vector2f(0, 0);
        std::vector<Observer*> observers;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_SUBJECT_H

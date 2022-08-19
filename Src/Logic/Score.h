//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_SCORE_H
#define DOODLEJUMP_SAID_YANDARBIEV_SCORE_H

#include "Observer.h"

class Score : public Observer
{
public:
        //Constructor
        Score()= default;

        void HandleEvent(float height);

        //Returns the current score of the player
        float GetScore() const;

private:

        //Float that holds the current score of the player
        float score = 0;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_SCORE_H

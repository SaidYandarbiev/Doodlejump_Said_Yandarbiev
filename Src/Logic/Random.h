//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_RANDOM_H
#define DOODLEJUMP_SAID_YANDARBIEV_RANDOM_H

#include "../Vector2.h"
#include "tuple"
#include <random>
namespace Utility{

//Class where random numbers can be generated
class Random
{
public:
        //Constructor
        static Random* getInstance();

        //This function returns a random int
        int RandomInt(int from, int to);

        //This function returns a random float
        float RandomFloat(float from, float to);

        //This function returns a boolean
        bool Bernoulli(float chance);

private:

        Random() : gen(rd()) {}

        std::random_device rd{};
        std::mt19937 gen;

        static Random* Instance;
};
}


#endif // DOODLEJUMP_SAID_YANDARBIEV_RANDOM_H

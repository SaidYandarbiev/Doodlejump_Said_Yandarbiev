//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_RANDOM_H
#define DOODLEJUMP_SAID_YANDARBIEV_RANDOM_H

#include "../Vector2.h"
#include "tuple"
#include <random>

class Random
{
public:
        static Random* getInstance()
        {
                static Random instance;

                return &instance;
        }

        int RandomInt(int from, int to)
        {

                std::uniform_int_distribution<> distrib(from, to);
                return distrib(gen);
        }

        float RandomFloat(float from, float to)
        {

                std::uniform_real_distribution<> dis(from, to);
                return dis(gen);
        }

        bool Bernouilli(float chance)
        {

                std::bernoulli_distribution distribution(chance);
                return distribution(gen);
        }

private:
        Random() : gen(rd()) {}

        std::random_device rd{};
        std::mt19937 gen;

        static Random* Instance;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_RANDOM_H

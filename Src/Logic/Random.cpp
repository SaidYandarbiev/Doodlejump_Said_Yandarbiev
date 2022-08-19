//
// Created by said2 on 17-11-2021.
//

#include "Random.h"
Utility::Random* Utility::Random::getInstance()
{
        static Random instance;

        return &instance;
}
int Utility::Random::RandomInt(int from, int to)
{

        std::uniform_int_distribution<> distrib(from, to);
        return distrib(gen);
}
float Utility::Random::RandomFloat(float from, float to)
{

        std::uniform_real_distribution<> dis(from, to);
        return dis(gen);
}
bool Utility::Random::Bernoulli(float chance)
{

        std::bernoulli_distribution distribution(chance);
        return distribution(gen);
}

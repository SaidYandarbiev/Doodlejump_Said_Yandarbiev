//
// Created by said2 on 17-11-2021.
//

#include "Stopwatch.h"
Utility::Stopwatch* Utility::Stopwatch::getInstance()
{
        static Stopwatch instance;

        return &instance;
}

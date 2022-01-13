//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_STOPWATCH_H
#define DOODLEJUMP_SAID_YANDARBIEV_STOPWATCH_H

#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>

class Stopwatch
{
public:
        static Stopwatch* getInstance()
        {
                static Stopwatch instance;

                return &instance;
        }

        void Release()
        {
                delete instance;
                instance = nullptr;
        }

        void TimeScale(float t = 1.0f) { timescale = t; }

        float TimeScale() { return timescale; }

        void Reset() { start_time = std::chrono::steady_clock::now(); }

        void tick() { delta_time = std::chrono::steady_clock::now() - start_time; }

        float getDeltaTime() { return delta_time.count(); }

        void FrameBalancing()
        {
                if (delta_time.count() < 1000.0 / 60.0) {
                        std::chrono::duration<double, std::milli> delta_ms(1000.0 / 60 - delta_time.count());
                        auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
                        std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
                }
                tick();
                Reset();
        }

private:
        Stopwatch() { Reset(); }

        ~Stopwatch() {}

        static Stopwatch* instance;

        double PreviousUpdateTime;
        double CurrentUpdateTime;

        std::chrono::duration<float, std::milli> delta_time;
        std::chrono::steady_clock::time_point start_time;

        float timescale;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_STOPWATCH_H

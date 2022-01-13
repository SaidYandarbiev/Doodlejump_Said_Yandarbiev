//
// Created by said2 on 13-1-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_VECTOR2_H
#define DOODLEJUMP_SAID_YANDARBIEV_VECTOR2_H

class Vector2
{
public:
        int x;
        int y;

        void SetX(int x1) { x = x1; }

        void SetY(int y1) { y = y1; }

        int GetX() { return x; }

        int GetY() { return y; }
};

class Vector2i : public Vector2
{
public:
        Vector2i(int X, int Y)
        {
                x = X;
                y = Y;
        }

        int x;
        int y;
};

class Vector2u : public Vector2
{
public:
        Vector2u(unsigned int X, unsigned int Y)
        {
                x = X;
                y = Y;
        }

        unsigned int x;
        unsigned int y;
};

class Vector2f : public Vector2
{
public:
        Vector2f(float X, float Y)
        {
                x = X;
                y = Y;
        }

        void SetX(float x1) { x = x1; }

        void SetY(float y1) { y = y1; }

        float GetX() { return x; }

        float GetY() { return y; }

        float x;
        float y;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_VECTOR2_H

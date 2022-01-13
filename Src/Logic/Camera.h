//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_CAMERA_H
#define DOODLEJUMP_SAID_YANDARBIEV_CAMERA_H

#include "../Vector2.h"

class Camera
{
public:
        Camera(Vector2u windowsize) { RenderWindow = windowsize; }

        void UpdatePlayer(Vector2f position, bool jumping)
        {
                position.x = position.x - OorsprongPunt.x;
                position.y = position.y - OorsprongPunt.y;

                if (position.y > CameraSizeY.y / 2 && jumping) {
                        OorsprongPunt.y = OorsprongPunt.y + (position.y - CameraSizeY.y / 2);
                }
        }

        Vector2f PositionInPixels(Vector2f position2)
        {
                position2.x = position2.x - OorsprongPunt.x;
                position2.y = position2.y - OorsprongPunt.y;

                position2.x *= (RenderWindow.x / CameraSizeX.y);
                position2.y *= (RenderWindow.y / CameraSizeY.y);
                position2.y = RenderWindow.y - position2.y;

                return position2;
        }

        Vector2f GetCameraSizeX() { return CameraSizeX; }

        Vector2f GetCameraSizeY() { return CameraSizeY; }

        float GetRenderWindowSizeX() { return RenderWindow.x; }

        float GetRenderWindowSizeY() { return RenderWindow.y; }

        float GetPosition() { return OorsprongPunt.y; }

private:
        Vector2u RenderWindow = Vector2u(600, 900);
        Vector2f position = Vector2f(0, 0);
        Vector2f CameraSizeX = Vector2f(0, 20);
        Vector2f CameraSizeY = Vector2f(0, 40);

        Vector2f OorsprongPunt = Vector2f(0, 0);
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_CAMERA_H

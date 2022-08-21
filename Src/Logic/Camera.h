//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_CAMERA_H
#define DOODLEJUMP_SAID_YANDARBIEV_CAMERA_H

#include "../Vector2.h"
#include "vector"
#include "iostream"

namespace Utility{
//Class representing the camera of the game
class Camera
{
public:
        //Constructor
        explicit Camera(Vector2u windowsize);

        //Function that updates the position of the player
        void UpdatePlayer(Vector2f position1, bool jumping);

        //Function that determines the factor that the position of the view of the model has to be multiplied with
        std::vector<float> UpdateBonus(double width, double height, double bonuswidth, double bonusheight) const;

        //Returns the position in pixels of the given position
        Vector2f PositionInPixels(Vector2f position2) const;

        //Returns the x size of the camera
        Vector2f GetCameraSizeX();

        //Returns the y size of the camera
        Vector2f GetCameraSizeY();

        //Returns the renderwindow x size
        float GetRenderWindowSizeX() const;

        //Returns the renderwindow y size
        float GetRenderWindowSizeY() const;

        //Returns the position of the camera
        float GetPosition() const;

        //Returns the boolean gameended
        bool getGameEnded()const;

private:
        //The size of the renderwindow
        Vector2u RenderWindow = Vector2u(600, 900);

        //Position of the camera
        Vector2f position = Vector2f(0, 0);

        //X size of the camera
        Vector2f CameraSizeX = Vector2f(0, 20);

        //Y size of the camera
        Vector2f CameraSizeY = Vector2f(0, 40);

        //Gives the source point
        Vector2f OorsprongPunt = Vector2f(0, 0);

        //If gameended boolean == true, then the game has ended
        bool gameended = false;
};

}

#endif // DOODLEJUMP_SAID_YANDARBIEV_CAMERA_H

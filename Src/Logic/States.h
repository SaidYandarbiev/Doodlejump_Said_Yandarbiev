//
// Created by said2 on 13-1-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_STATES_H
#define DOODLEJUMP_SAID_YANDARBIEV_STATES_H
namespace Utility{
struct States
{
        //This function sets the shooting to false so that the player will stop shooting
        void SetShooting();

        //If Clickedleft == true then there was a left arrow press on the keyboard
        bool ClickedLeft = false;
        //If Clickedright == true then there was a right arrow press on the keyboard
        bool ClickedRight = false;
        //If Shooting == true then there was an up arrow press on the keyboard
        bool Shooting = false;
};

}

#endif // DOODLEJUMP_SAID_YANDARBIEV_STATES_H

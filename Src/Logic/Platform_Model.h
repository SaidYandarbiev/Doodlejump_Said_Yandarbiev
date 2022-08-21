//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_MODEL_H

#include "../Game_Representation/Platform_View.h"
#include "Camera.h"
#include "Entity_Model.h"

//Class that represents the model of a platform
class Platform_Model : public Entity_Model
{
public:
        //Constructor
        Platform_Model(bool verticalmove, bool horizontalmove, bool breaker, bool Moving,
                       Vector2f pos, std::shared_ptr<Utility::Camera> cam);

        //This function returns the position of the platform
        Vector2f GetPosition();

        //This function sets playerhit on true if the player has hit this platform
        void PlayerHit();

        //This function sets the platformview to the given platformview
        void AddPlatform(std::shared_ptr<Platform_View> platform);

        //This function returns the width of the platform
        double GetWidth() const;

        //This function returns the height of the platform
        double GetHeight() const;;

        //This function sets the position of the platform to the given position
        void SetPosition(Vector2f pos) override;

        //This function updates the position of the model
        void Update();

        //This function returns the breaking boolean
        bool GetBreaking() const;

        //This function sets the broken boolean to true
        void Broken();

        //This function returns the broken boolean
        bool GetBroken() const;

        //This function returns the view of the platform
        std::shared_ptr<Observer> GetView() override;

private:
        //Position of the model
        Vector2f position = Vector2f(5, 20);

        //If verticalmoving == true then the platform is moving vertically
        bool verticalmoving = false;

        //If horizontalmoving == true then the platform is moving horizontally
        bool horizontalmoving = false;

        //If breaking == true then the platform is a breaking platform
        bool breaking = false;

        //Width of the model
        double width = 3;

        //Height of the model
        double height = 1;

        //View of the model
        std::shared_ptr<Platform_View> platformView = nullptr;

        //If the platform is moving horizontal, this is the most left position for the platform
        Vector2f Lhorizontalpos = Vector2f(0, 0);

        //If the platform is moving horizontal, this is the most right position for the platform
        Vector2f Rhorizontalpos = Vector2f(0, 0);

        //If the platform is moving vertical, this is the lowest position for the platform
        Vector2f Dverticalpos = Vector2f(0, 0);

        //If the platform is moving vertical, this is the highest position for the platform
        Vector2f Uverticalpos = Vector2f(0, 0);

        //If movingright == true then the platform is moving right
        bool movingright = false;

        //If movingleft == true then the platform is moving left
        bool movingleft = false;

        //If movingup == true then the platform is moving up
        bool movingup = false;

        //If movingdown == true then the platform is moving down
        bool movingdown = false;

        //Pointer to camera
        std::shared_ptr<Utility::Camera> camera;

        bool broken = false;

        //If playerhit == true then the player has hit the platform
        bool playerhit = false;

        //If notmoving == true then the player has hit the platform and it starts moving horizontally or vertically
        //depending on different booleans
        bool notmoving = false;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_MODEL_H

//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_BONUS_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_BONUS_MODEL_H

#include "../Game_Representation/Bonus_View.h"
#include "Camera.h"
#include "Entity_Model.h"
#include "Platform_Model.h"
#include "Player_Model.h"

class Player_Model;

class Bonus_Model : public Entity_Model
{
public:
        Bonus_Model(Vector2f pos, bool spring1, bool helicopter, Camera* camera1)
        {

                spring = spring1;
                copter = helicopter;

                camera = camera1;
                position = pos;
        }

        void PlayerTouched()
        {

                trigger = true;

                height = 3;

                float playergamesizex = (camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y) * width;
                float playergamesizey = (camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().y) * height;

                float factorx = playergamesizex / bonusView->GetWidth();
                float factory = playergamesizey / bonusView->GetHeight();

                Vector2f pixels = camera->PositionInPixels(position);

                bonusView->HandleEvent(pixels, spring, copter, trigger, factorx, factory);
        }

        void AddBonus(Bonus_View* platform) { bonusView = platform; }

        void SetPosition(Vector2f vector2I)
        {

                position = vector2I;
                float playergamesizex = (camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y) * width;
                float playergamesizey = (camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().y) * height;

                float factorx = playergamesizex / bonusView->GetWidth();
                float factory = playergamesizey / bonusView->GetHeight();

                Vector2f pixels = camera->PositionInPixels(position);
                bonusView->HandleEvent(pixels, spring, copter, trigger, factorx, factory);
        }

        Vector2f GetPosition() { return position; }

        bool GetSpring() { return spring; }

        bool GetCopter() { return copter; }

        void Update()
        {
                float playergamesizex = (camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y) * width;
                float playergamesizey = (camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().y) * height;

                float factorx = playergamesizex / bonusView->GetWidth();
                float factory = playergamesizey / bonusView->GetHeight();
                Vector2f pixels = camera->PositionInPixels(position);
                bonusView->HandleEvent(pixels, spring, copter, trigger, factorx, factory);
        }

        void deleteview() { delete bonusView; }

        double GetWidth() { return width; }

        double GetHeight() { return height; }

        Bonus_View* GetView() { return bonusView; }

private:
        Vector2f position = Vector2f(0, 0);

        Bonus_View* bonusView = nullptr;

        bool trigger = false;
        bool spring = false;
        bool copter = false;

        double width = 1;
        double height = 1;
        Camera* camera;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_BONUS_MODEL_H

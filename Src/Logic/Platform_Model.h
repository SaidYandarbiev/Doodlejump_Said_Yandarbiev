//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_MODEL_H

#include "../Game_Representation/Platform_View.h"
#include "Camera.h"
#include "Entity_Model.h"

class Platform_Model : public Entity_Model
{
public:
        Platform_Model(bool verticalmove, bool horizontalmove, bool breaker, Vector2f pos, Camera* cam)
        {
                position = pos;
                if (horizontalmove) {
                        Lhorizontalpos = pos;
                        movingright = true;

                        Rhorizontalpos = pos;
                        Rhorizontalpos.x += 4;
                }

                if (verticalmove) {
                        Dverticalpos = pos;
                        movingup = true;

                        Uverticalpos = pos;
                        Uverticalpos.y += 7;
                }

                verticalmoving = verticalmove;
                horizontalmoving = horizontalmove;

                breaking = breaker;
                camera = cam;
        }

        Vector2f GetPosition() { return position; }

        void SetWidth(double width1) { width = width1; }

        void SetHeight(double heigth1) { height = heigth1; }

        void AddPlatform(Platform_View* platform) { platformView = platform; }

        double GetWidth() { return width; }

        double GetHeight() { return height; };

        void SetPosition(Vector2f pos)
        {
                position = pos;
                Vector2f pixels = camera->PositionInPixels(position);
                platformView->SetPosition(pixels);
        }

        void Update()
        {
                if (horizontalmoving) {
                        if (movingright) {
                                position.x += 0.2;
                        }

                        if (movingleft) {
                                position.x -= 0.2;
                        }

                        if (position.x >= Rhorizontalpos.x && movingright) {
                                movingleft = true;
                                movingright = false;
                        }

                        if (position.x <= Lhorizontalpos.x && movingleft) {
                                movingleft = false;
                                movingright = true;
                        }
                }

                if (verticalmoving) {
                        if (movingup) {
                                position.y += 0.2;
                        }

                        if (movingdown) {
                                position.y -= 0.2;
                        }

                        if (position.y >= Uverticalpos.y && movingup) {
                                movingdown = true;
                                movingup = false;
                        }

                        if (position.y <= Dverticalpos.y && movingdown) {
                                movingdown = false;
                                movingup = true;
                        }
                }
                Vector2f pixels = camera->PositionInPixels(position);
                float playergamesizex = (camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y) * width;
                float playergamesizey = (camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().y) * height;

                float factorx = playergamesizex / platformView->GetWidth();
                float factory = playergamesizey / platformView->GetHeight();
                platformView->HandleEvent(pixels, factorx, factory);
        }

        void DeleteView() { delete platformView; }

        bool GetBreaking() { return breaking; }

        void Broken() { broken = true; }

        bool GetBroken() { return broken; }

        Platform_View* GetView() { return platformView; }

private:
        Vector2f position = Vector2f(5, 20);

        bool verticalmoving = false;
        bool horizontalmoving = false;
        bool breaking = false;

        double width = 3;
        double height = 1;

        Platform_View* platformView = nullptr;

        Vector2f Lhorizontalpos = Vector2f(0, 0);
        Vector2f Rhorizontalpos = Vector2f(0, 0);

        Vector2f Dverticalpos = Vector2f(0, 0);
        Vector2f Uverticalpos = Vector2f(0, 0);

        bool movingright = false;
        bool movingleft = false;

        bool movingup = false;
        bool movingdown = false;

        Camera* camera;

        bool broken = false;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLATFORM_MODEL_H

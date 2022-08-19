//
// Created by said2 on 17-11-2021.
//

#include "Platform_Model.h"
Platform_Model::Platform_Model(bool verticalmove, bool horizontalmove, bool breaker, bool Moving, Vector2f pos,
                               std::shared_ptr<Utility::Camera> cam)
{
        notmoving = Moving;
        position = pos;
        //If the platform is a horizontal moving platform then enter this statement
        if (horizontalmove) {
                Lhorizontalpos = pos;
                movingright = true;
                Rhorizontalpos = pos;
                Rhorizontalpos.x += 4;

        }

        //If the platform is a vertical moving platform then enter this statement
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
Vector2f Platform_Model::GetPosition() { return position; }

void Platform_Model::PlayerHit() { playerhit = true;}

void Platform_Model::AddPlatform(std::shared_ptr<Platform_View> platform) { platformView = platform; }

double Platform_Model::GetWidth() const { return width; }

double Platform_Model::GetHeight() const { return height; }

void Platform_Model::SetPosition(Vector2f pos)
{
        position = pos;
        Vector2f pixels = camera->PositionInPixels(position);
        platformView->SetPosition(pixels);
}

void Platform_Model::Update()
{
        //This ifstatement is entered if the platform is not moving and a horizontal moving platform or
        //if this platform is hit by a player and it only moves when it is hit by a player
        if ((horizontalmoving && !notmoving) || (notmoving && playerhit)) {
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

        //This ifstatement is entered if the platform is not moving and a vertical moving platform or
        //if this platform is hit by a player and it only moves when it is hit by a player
        if ((verticalmoving && !notmoving) || (notmoving && playerhit)) {
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
        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,platformView->GetWidth(),platformView->GetHeight());

        platformView->HandleEvent(pixels, vec[0], vec[1]);
}

bool Platform_Model::GetBreaking() const { return breaking; }

void Platform_Model::Broken() { broken = true; }

bool Platform_Model::GetBroken() const { return broken; }

std::shared_ptr<Observer> Platform_Model::GetView() { return platformView; }

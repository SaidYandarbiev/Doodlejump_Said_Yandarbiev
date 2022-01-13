//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_PLAYER_MODEL_H
#define DOODLEJUMP_SAID_YANDARBIEV_PLAYER_MODEL_H

#include "../Game_Representation/Player_View.h"
#include "Bonus_Model.h"
#include "Camera.h"
#include "Entity_Model.h"
#include "Platform_Model.h"
#include "States.h"
#include "Stopwatch.h"
#include <algorithm>
#include <cmath>
#include <iostream>

class Bonus_Model;
class Player_Model : public Entity_Model
{

public:
        Player_Model(double x, double y, Camera* cam)
        {
                position.x = x;
                position.y = y;
                camera = cam;
        }

        void Update(States* states, Vector2u windowsize, float XworldMax)
        {

                movingleft = states->ClickedLeft;
                movingright = states->ClickedRight;
                forces.SetX(0);
                forces.SetY(9.81);

                if (movingleft) {
                        DirectionChange(Direction::Left);
                        forces.SetX(-2);
                }

                if (movingright) {
                        DirectionChange(Direction::Right);
                        forces.SetX(2);
                }

                if (platformhit) {
                        falling = false;
                        jumping = true;
                        ysnelheid = -20;
                        platformhit = false;
                }

                if (spring) {
                        falling = false;
                        jumping = true;
                        ysnelheid = -35;
                        spring = false;
                }

                if (ysnelheid >= 0) {
                        falling = true;
                        jumping = false;
                }

                if (flying && position.y > start_end.y) {
                        flying = false;
                        ysnelheid = -20;
                }

                ysnelheid += (forces.GetY() / 2 * std::pow(Stopwatch::getInstance()->getDeltaTime() / 100, 2));
                position.y -= ysnelheid * (Stopwatch::getInstance()->getDeltaTime() / 500);

                xsnelheid *= 0.90;
                xversnelling = forces.GetX() / massa;
                xsnelheid = xsnelheid + (0.5 * xversnelling * (Stopwatch::getInstance()->getDeltaTime() / 10));
                position.x += xsnelheid * (Stopwatch::getInstance()->getDeltaTime() / 10);

                if (position.x > camera->GetCameraSizeX().y) {
                        position.x = 0;
                }

                if (position.x < 0) {
                        position.x = XworldMax;
                }

                if (copterhit) {
                        copterhit = false;
                        flying = true;
                        start_end.x = position.y;
                        start_end.y = position.y + 100;
                        ysnelheid = -20;
                        ysnelheid += (forces.GetY() / 2 * std::pow(Stopwatch::getInstance()->getDeltaTime() / 100, 2));
                        position.y -= ysnelheid * (Stopwatch::getInstance()->getDeltaTime() / 500);
                }

                if (flying) {
                        ysnelheid = -20;
                        ysnelheid += (forces.GetY() / 2 * std::pow(Stopwatch::getInstance()->getDeltaTime() / 100, 2));
                        position.y -= ysnelheid * (Stopwatch::getInstance()->getDeltaTime() / 500);
                }

                camera->UpdatePlayer(position, jumping);

                Vector2f pixels = camera->PositionInPixels(position);

                float playergamesizex = (camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().y) * width;
                float playergamesizey = (camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().y) * height;

                float factorx = playergamesizex / observerz[0]->GetWidth();
                float factory = playergamesizey / observerz[0]->GetHeight();

                for (int i = 0; i < observerz.size(); i++) {
                        observerz[i]->HandleEvent(pixels, flying, direction, factorx, factory);
                }
        }

        // Changing the direction
        void DirectionChange(Direction direction2) { direction = direction2; }

        // Switching betweeen jumping and falling when platform hit or when peak is reached
        void ToggleJumpingAndFalling()
        {
                jumping = !jumping;
                falling = !falling;
        }

        // Set the platform hit and set platformhit to true
        void Platformhit(Platform_Model* platform)
        {
                platformhit = true;
                platform_hit = platform;
        }

        // Set the direction
        void SetDirection(Direction l_dir) { direction = l_dir; }

        void SetPosition(Vector2f vector2F)
        {
                position = vector2F;
                float factorx = camera->GetRenderWindowSizeX() / camera->GetCameraSizeX().GetY() * width;
                float factory = camera->GetRenderWindowSizeY() / camera->GetCameraSizeY().GetY() * height;

                factorx = factorx / observerz[0]->GetWidth();
                factory = factory / observerz[0]->GetHeight();

                Vector2f pixels = camera->PositionInPixels(position);
                for (int i = 0; i < observerz.size(); i++) {
                        observerz[i]->HandleEvent(pixels, flying, direction, factorx, factory);
                }
        }

        // Direction
        Direction GetDirection() { return direction; }

        bool GetJumping() { return jumping; }

        bool GetFalling() { return falling; }

        Vector2f GetPosition() { return position; }

        void Bonus_hit() { spring = true; }

        void AddPlayer(Player_View* playerView) { observerz.push_back(playerView); }

        void SetWidth(double width1) { width = width1; }

        void SetHeight(double height1) { height = height1; }

        double GetWidth() { return width; }

        double GetHeight() { return height; }

        void Copterhit() { copterhit = true; }

private:
        std::vector<Player_View*> observerz = {};

        // Wanneer valt hij
        bool falling = true;
        // Wanneer springt hij
        bool jumping = false;
        // Wanneer hit hij een platform
        bool platformhit = false;
        // Welke platform hit hij
        Platform_Model* platform_hit = nullptr;
        // Welke richting faced hij
        Direction direction = Direction::Right;
        // Beweegt hij naar links
        bool movingleft = false;
        // Beweegt hij naar rechts
        bool movingright = false;
        // Welke positie zit hij momenteel?
        Vector2f position = Vector2f(10, 30);

        bool spring = false;

        bool copter = false;

        float xversnelling = 0;
        float yversnelling = 0;

        float xsnelheid = 0;
        float ysnelheid = 0;

        float massa = 50;

        Vector2f forces = Vector2f(0, 0);

        double width = 2;
        double height = 3;

        Camera* camera;

        bool copterhit = false;
        bool flying = false;

        Vector2f start_end = Vector2f(0, 0);
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_PLAYER_MODEL_H

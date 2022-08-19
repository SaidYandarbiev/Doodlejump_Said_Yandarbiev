//
// Created by said2 on 8-8-2022.
//

#include "Ball_Model.h"
Ball_Model::Ball_Model(Vector2f pos, bool enemy, bool player, std::shared_ptr<Utility::Camera> cam)
{
        position = pos;
        ysnelheid = 0.40;
        camera = std::move(cam);
        Enemy = enemy;
        Player = player;
}
void Ball_Model::Update()
{
        //If the ball model belongs to a player, this ifstatement is entered
        if (Player) {
                position.y += ysnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 20);
                Vector2f pixels = camera->PositionInPixels(position);

                std::vector<float> vec;
                vec = camera->UpdateBonus(width,height,observers[0]->GetWidth(),observers[0]->GetHeight());

                observers[0]->HandleEvent(pixels, vec[0], vec[1]);
        }

        //If the ball model belongs to an enemy, this ifstatement is entered
        else if(Enemy){
                position.y -= ysnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 20);
                Vector2f pixels = camera->PositionInPixels(position);
                std::vector<float> vec;
                vec = camera->UpdateBonus(width,height,observers[0]->GetWidth(),observers[0]->GetHeight());

                observers[0]->HandleEvent(pixels, vec[0], vec[1]);
        }
}
bool Ball_Model::GetEnemy() const {return Enemy;}

bool Ball_Model::GetPlayer() const {return Player;}

Vector2f Ball_Model::GetPosition() const { return position; }

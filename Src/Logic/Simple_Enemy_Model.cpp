//
// Created by said2 on 21-7-2022.
//

#include "Simple_Enemy_Model.h"

Simple_Enemy_Model::Simple_Enemy_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera)
{
    position = vector2I;
    hp = std::make_shared<Hp>(1);
    cam = camera;
}

bool Simple_Enemy_Model::Shooting() { return false;}

void Simple_Enemy_Model::Update()
{
        Vector2f pixels = cam->PositionInPixels(position);

        std::vector<float> vec;
        vec = cam->UpdateBonus(width,height,observers[0]->GetWidth(),observers[0]->GetHeight());

        observers[0]->HandleEvent(pixels,vec[0],vec[1]);
}

std::shared_ptr<Observer> Simple_Enemy_Model::GetView() {return observers[0];}

double Simple_Enemy_Model::GetHeight() {return height;}

double Simple_Enemy_Model::GetWidth() {return width;}

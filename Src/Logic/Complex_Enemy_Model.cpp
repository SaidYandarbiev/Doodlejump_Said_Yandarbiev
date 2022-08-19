//
// Created by said2 on 21-7-2022.
//

#include "Complex_Enemy_Model.h"
Complex_Enemy_Model::Complex_Enemy_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera)
{
        position = vector2I;
        hp = std::make_shared<Hp>(2);
        cam = camera;
}
bool Complex_Enemy_Model::Shooting()
{
        Vector2f pixels = cam->PositionInPixels(position);

        //If the position of the model in pixels is >= 300 and if the previous y in pixels < 300 then the enemy shoots
        //and returns true
        if(pixels.y >= 300 && prevYpos < 300) {
                shooting = true;
                return true;
        }
        //Else the enemy doesn't shoot and returns false
        shooting = false;
        return false;
}
void Complex_Enemy_Model::Update()
{
        Vector2f pixels = cam->PositionInPixels(position);
        prevYpos = pixels.y;

        std::vector<float> vec;
        vec = cam->UpdateBonus(width,height,observers[0]->GetWidth(),observers[0]->GetHeight());

        observers[0]->HandleEvent(pixels, vec[0], vec[1], shooting);
}
std::shared_ptr<Observer> Complex_Enemy_Model::GetView() {return observers[0];}

double Complex_Enemy_Model::GetHeight() {return height;}

double Complex_Enemy_Model::GetWidth() {return width;}

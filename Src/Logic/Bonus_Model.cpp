//
// Created by said2 on 17-11-2021.
//

#include "Bonus_Model.h"
Bonus_Model::Bonus_Model(Vector2f pos, bool spring1, bool helicopter, bool hp, bool spike,
                         std::shared_ptr<Utility::Camera> camera1)
{

        spring = spring1;
        copter = helicopter;
        health = hp;
        spikes = spike;

        camera = camera1;
        position = pos;

        //If the bonus are spikes then this ifstatement is entered
        if (spike){
                width = 3;
                height = 2;
        }

        //If the bonus is health then this ifstatement is entered
        else if(health){
                width = 2;
                height = 2;
        }
}
void Bonus_Model::PlayerTouched()
{

        trigger = true;

        height = 3;
        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,bonusView->GetWidth(),bonusView->GetHeight());

        Vector2f pixels = camera->PositionInPixels(position);

        bonusView->HandleEvent(pixels, spring, copter, trigger, vec[0], vec[1]);
}
void Bonus_Model::AddBonus(std::shared_ptr<Bonus_View> platform) { bonusView = platform; }

void Bonus_Model::SetPosition(Vector2f vector2I)
{
        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,bonusView->GetWidth(),bonusView->GetHeight());
        position = vector2I;
        Vector2f pixels = camera->PositionInPixels(position);
        bonusView->HandleEvent(pixels, spring, copter, trigger, vec[0], vec[1]);
}

Vector2f Bonus_Model::GetPosition() const { return position; }

bool Bonus_Model::GetSpring() const { return spring; }

bool Bonus_Model::GetCopter() const { return copter; }

void Bonus_Model::Update()
{
        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,bonusView->GetWidth(),bonusView->GetHeight());

        Vector2f pixels = camera->PositionInPixels(position);
        bonusView->HandleEvent(pixels, spring, copter, trigger, vec[0], vec[1]);
}

double Bonus_Model::GetWidth() const { return width; }

double Bonus_Model::GetHeight() const { return height; }

bool Bonus_Model::GetHealth() const {return health; }

bool Bonus_Model::GetSpikes() const { return spikes;}

std::shared_ptr<Bonus_View> Bonus_Model::GetView() const { return bonusView; }

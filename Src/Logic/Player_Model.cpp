//
// Created by said2 on 17-11-2021.
//

#include "Player_Model.h"
Player_Model::Player_Model(double x, double y, std::shared_ptr<Utility::Camera> cam)
{
        position.x = x;
        position.y = y;
        camera = cam;
}

void Player_Model::Update(std::shared_ptr<Utility::States> states, Vector2u windowsize, float XworldMax)
{
        //If the player is dead then the player can't hit any platforms and will fall into the void
        if(this->GetHp()->GetDead()){
                this->NoCollision();
        }

        //To determine if a player is moving left, moving right or shooting we check the states class
        movingleft = states->ClickedLeft;
        movingright = states->ClickedRight;
        shooting = states->Shooting;


        forces.SetX(0);
        forces.SetY(9.81);

        //Depending on if the player is moving left or right his position will decrease or increase respectively
        if (movingleft) {
                DirectionChange(Direction::Left);
                forces.SetX(-2);
        }

        if (movingright) {
                DirectionChange(Direction::Right);
                forces.SetX(2);
        }

        //If a platform is hit then the player will jump and his y position will go up
        if (platformhit) {
                falling = false;
                jumping = true;
                ysnelheid = -20;
                platformhit = false;
        }

        //If a player hits a spring then the player will go up rapidly
        if (spring) {
                falling = false;
                jumping = true;
                ysnelheid = -35;
                spring = false;
        }

        //If the y speed is <= 0 then we know that the player is falling
        if (ysnelheid >= 0) {
                falling = true;
                jumping = false;
        }


        //If a player was flying and past his endpoint of flying then he will return to his normal speed
        if (flying && position.y > start_end.y) {
                flying = false;
                ysnelheid = -20;
        }

        //This calculates the y speed with the forces and the time and updates the y position
        ysnelheid += (forces.GetY() / 2 * std::pow(Utility::Stopwatch::getInstance()->getDeltaTime() / 70, 2));
        position.y -= ysnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 500);

        //This calculates the x speed with the forces and the time and updates the x position
        xsnelheid *= 0.90;
        xversnelling = forces.GetX() / massa;
        xsnelheid = xsnelheid + (0.5 * xversnelling * (Utility::Stopwatch::getInstance()->getDeltaTime() / 10));
        position.x += xsnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 10);


        if (position.x > camera->GetCameraSizeX().y) {
                position.x = 0;
        }

        if (position.x < 0) {
                position.x = XworldMax;
        }

        //If a helicopter bonus is hit then our y speed will increase (will become more negative)
        //And the player will start flying
        if (copterhit) {
                copterhit = false;
                flying = true;
                start_end.x = position.y;
                start_end.y = position.y + 100;
                ysnelheid = -20;
                ysnelheid += (forces.GetY() / 2 * std::pow(Utility::Stopwatch::getInstance()->getDeltaTime() / 100, 2));
                position.y -= ysnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 500);
        }

        if (flying) {
                ysnelheid = -20;
                ysnelheid += (forces.GetY() / 1.5 * std::pow(Utility::Stopwatch::getInstance()->getDeltaTime() / 100, 2));
                position.y -= ysnelheid * (Utility::Stopwatch::getInstance()->getDeltaTime() / 500);
        }

        camera->UpdatePlayer(position, jumping);

        Vector2f pixels = camera->PositionInPixels(position);

        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,50,50);

        for (int i = 0; i < observerz.size(); i++) {
                observerz[i]->HandleEvent(pixels, flying, direction, vec[0], vec[1], shooting);
        }
        //We set the shooting to false so that the player doesn't shoot
        states->SetShooting();
}

void Player_Model::DirectionChange(Direction direction2) { direction = direction2; }

void Player_Model::ToggleJumpingAndFalling()
{
        jumping = !jumping;
        falling = !falling;
}

void Player_Model::Platformhit(std::shared_ptr<Platform_Model> platform)
{
        platformhit = true;
        platform_hit = platform;
}

void Player_Model::SetDirection(Direction l_dir) { direction = l_dir; }
void Player_Model::SetPosition(Vector2f vector2F)
{
        position = vector2F;

        std::vector<float> vec;
        vec = camera->UpdateBonus(width,height,50,50);
        Vector2f pixels = camera->PositionInPixels(position);
        for (int i = 0; i < observerz.size(); i++) {
                observerz[i]->HandleEvent(pixels, flying, direction, vec[0], vec[1], shooting);
        }
}

Direction Player_Model::GetDirection() const { return direction; }

bool Player_Model::GetFalling() const { return falling; }

Vector2f Player_Model::GetPosition() const { return position; }

void Player_Model::Bonus_hit() { spring = true; }

void Player_Model::AddPlayer(const std::shared_ptr<Entity_view>& playerView) { observerz.push_back(playerView); }

double Player_Model::GetWidth() const { return width; }

double Player_Model::GetHeight() const { return height; }

void Player_Model::Copterhit() { copterhit = true; }

std::shared_ptr<Hp> Player_Model::GetHp() { return hp; }

void Player_Model::NoCollision() { collision = false; }

bool Player_Model::GetCollision() const {return collision; }

bool Player_Model::GetShooting() const {return shooting;}

void Player_Model::SetShooting() {shooting = false;}


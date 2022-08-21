//
// Created by said2 on 17-11-2021.
//

#include "Observer.h"
std::shared_ptr<sf::Sprite> Observer::GetSprite() const { return sprite; }
void Observer::HandleEvent(Vector2f vector2I)
{
        sprite->setPosition(vector2I.x, vector2I.y);
        sprite->setTexture(texture);
}

double Observer::GetWidth() {return 0;}

double Observer::GetHeight() {return 0;}

void Observer::HandleEvent(Vector2f pos, bool flying, Direction direction, float factorx, float factory, bool shooting)
{}

void Observer::HandleEvent(Vector2f vector2F, float factorx, float factory) {}

void Observer::HandleEvent(Vector2f vector2F, float factorx, float factory, bool shooting) {}

void Observer::SetPosition(Vector2i vector2I) const { sprite->setPosition(vector2I.x, vector2I.y); }

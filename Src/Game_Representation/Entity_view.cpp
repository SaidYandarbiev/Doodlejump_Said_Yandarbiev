//
// Created by said2 on 17-11-2021.
//

#include "Entity_view.h"

double Entity_view::GetWidth() { return sprite->getTexture()->getSize().x; }

double Entity_view::GetHeight() { return sprite->getTexture()->getSize().y; }

std::shared_ptr<sf::Sprite> Entity_view::GetSprite() const { return sprite; }


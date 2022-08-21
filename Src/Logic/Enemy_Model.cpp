//
// Created by said2 on 21-7-2022.
//

#include "Enemy_Model.h"
void Enemy_Model::Add_Enemy(const std::shared_ptr<Entity_view>& enemy_view) {observers.push_back(enemy_view);}

bool Enemy_Model::Shooting() {return false;}

void Enemy_Model::Update() {}

double Enemy_Model::GetHeight() {return 0;}

double Enemy_Model::GetWidth() {return 0;}

std::shared_ptr<Hp> Enemy_Model::GetHp() {return hp;}

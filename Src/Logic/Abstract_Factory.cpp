//
// Created by said2 on 17-11-2021.
//

#include "Abstract_Factory.h"
std::shared_ptr<Player_Model> Abstract_Factory::CreatePlayer_Model(Vector2f vector2I,
                                                                   std::shared_ptr<Utility::Camera> camera)
{return nullptr;}
std::shared_ptr<Platform_Model> Abstract_Factory::CreatePlatform_Model(Vector2f vector2I, bool vertical,
                                                                       bool horizontal, bool breaking, bool broken,
                                                                       bool notmoving,
                                                                       std::shared_ptr<Utility::Camera> camera)
{return nullptr;}
std::shared_ptr<BG_Tile_Model> Abstract_Factory::CreateBG_Tile_Model(Vector2f vector2I,
                                                                     std::shared_ptr<Utility::Camera> camera)
{return nullptr;}
std::shared_ptr<Bonus_Model> Abstract_Factory::CreateBonus_Model(Vector2f vector2I, bool spring, bool helicopter,
                                                                 bool health, bool spikes,
                                                                 std::shared_ptr<Utility::Camera> camera)
{return nullptr;}
std::shared_ptr<Simple_Enemy_Model> Abstract_Factory::CreateSimple_Enemy_Model(Vector2f vector2I,
                                                                               std::shared_ptr<Utility::Camera> camera)
{return nullptr;}
std::shared_ptr<Complex_Enemy_Model> Abstract_Factory::CreateComplex_Enemy_Model(
    Vector2f vector2F, std::shared_ptr<Utility::Camera> camera)
{return nullptr;}
std::shared_ptr<Ball_Model> Abstract_Factory::CreateBall_Model(Vector2f vector2F, bool enemy, bool player,
                                                               std::shared_ptr<Utility::Camera> camera)
{return nullptr;}
std::shared_ptr<Player_View> Abstract_Factory::CreatePlayer_View(Vector2f vector2I, Direction direction)
{return nullptr;}
std::shared_ptr<Platform_View> Abstract_Factory::CreatePlatform_View(Vector2f vector2I, bool vertical, bool horizontal,
                                                                     bool breaking, bool broken, bool notmoving)
{return nullptr;}
std::shared_ptr<BG_Tile_View> Abstract_Factory::CreateBG_Tile_View(Vector2f vector2I, float x) {return nullptr;}
std::shared_ptr<Bonus_View> Abstract_Factory::CreateBonus_View(Vector2f vector2I, bool spring, bool copter, bool health,
                                                               bool spikes)
{return nullptr;}
std::shared_ptr<Simple_Enemy_View> Abstract_Factory::CreateSimple_Enemy_View(Vector2f vector2I) {return nullptr;}
std::shared_ptr<Complex_Enemy_View> Abstract_Factory::CreateComplex_Enemy_View(Vector2f vector2F) {return nullptr;}
std::shared_ptr<Ball_View> Abstract_Factory::CreateBall_View(Vector2f vector2F) {return nullptr;}
void Abstract_Factory::Pop_Bonus_Front() {}
void Abstract_Factory::Pop_Platfrom_Front() {}
std::vector<std::shared_ptr<Observer>> Abstract_Factory::GetPlatform() const {return {}; }
std::vector<std::shared_ptr<Observer>> Abstract_Factory::GetBG_Tile() const { return {}; }
std::vector<std::shared_ptr<Observer>> Abstract_Factory::GetBonus() const {return {};}
std::vector<std::shared_ptr<Observer>> Abstract_Factory::GetEnemy() const {return {};}
std::shared_ptr<Observer> Abstract_Factory::GetPlayer() const {return nullptr;  }
std::vector<std::shared_ptr<Observer>> Abstract_Factory::GetShots() const {return {};  }
void Abstract_Factory::SetPlatforms(std::vector<std::shared_ptr<Observer>> plat) {}
void Abstract_Factory::Delete_platform_it(std::shared_ptr<Platform_Model> plat) {}
void Abstract_Factory::Delete_enemy_it(std::shared_ptr<Entity_Model> enemy) {}
void Abstract_Factory::Delete_bonus_it(std::shared_ptr<Bonus_Model> bonus) {}
void Abstract_Factory::Delete_Shot_It(std::shared_ptr<Ball_Model> ball) {}

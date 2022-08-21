//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_CONCRETE_FACTORY_H
#define DOODLEJUMP_SAID_YANDARBIEV_CONCRETE_FACTORY_H

#include "../Logic/Abstract_Factory.h"
#include "Player_View.h"

//Class representing the concrete factory, where all the entities are made
class Concrete_Factory : public Abstract_Factory
{
public:
        //Constructor
        explicit Concrete_Factory(Vector2f windowsize);

        //This function is used to create and return the player model
        std::shared_ptr<Player_Model> CreatePlayer_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) override;

        //This function is used to create and return a platform model
        std::shared_ptr<Platform_Model> CreatePlatform_Model(Vector2f vector2I, bool vertical, bool horizontal, bool breaking,
                                             bool broken, bool notmoving, std::shared_ptr<Utility::Camera> camera) override;

        //This function is used to create and return a background tile model
        std::shared_ptr<BG_Tile_Model> CreateBG_Tile_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera) override;

        //This function is used to create and return a bonus model
        std::shared_ptr<Bonus_Model> CreateBonus_Model(Vector2f vector2I, bool spring, bool helicopter, bool health,
                                                       bool spikes,
                                                       std::shared_ptr<Utility::Camera> camera) override;

        //This function is used to create and return a simple enemy model
        std::shared_ptr<Simple_Enemy_Model> CreateSimple_Enemy_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera)override;

        //This function is used to create and return a complex enemy model
        std::shared_ptr<Complex_Enemy_Model> CreateComplex_Enemy_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera)override;

        //This function is used to create and return a ball model
        std::shared_ptr<Ball_Model> CreateBall_Model(Vector2f vector2I, bool enemy, bool player, std::shared_ptr<Utility::Camera> camera)override;

        //This function is used to create and return the view of the player
        std::shared_ptr<Player_View> CreatePlayer_View(Vector2f vector2I, Direction direction) override;

        //This function is used to create and return the view of a platform
        std::shared_ptr<Platform_View> CreatePlatform_View(Vector2f vector2I, bool vertical, bool horizontal, bool breaking,
                                           bool broken, bool notmoving) override;

        //This function is used to create and return the view of a background tile
        std::shared_ptr<BG_Tile_View> CreateBG_Tile_View(Vector2f vector2I, float x) override;

        //This function is used to create and return the view of a bonus
        std::shared_ptr<Bonus_View> CreateBonus_View(Vector2f vector2I, bool spring, bool copter, bool health, bool spikes) override;

        //This function is used to create and return the view of a simple enemy
        std::shared_ptr<Simple_Enemy_View> CreateSimple_Enemy_View(Vector2f vector2I) override;

        //This function is used to create and return the view of a complex enemy
        std::shared_ptr<Complex_Enemy_View> CreateComplex_Enemy_View(Vector2f vector2F) override;

        //This function is used to create and return the view of a ball
        std::shared_ptr<Ball_View> CreateBall_View(Vector2f vector2F) override;

        //This function deletes the first bonus view in the vector "Bonus"
        void Pop_Bonus_Front() override;

        //This function deletes the first platform view in the vector "platforms"
        void Pop_Platfrom_Front() override;

        //This function returns a vector of platform views
        std::vector<std::shared_ptr<Observer>> GetPlatform() const override;

        //This function returns a vector of background tile views
        std::vector<std::shared_ptr<Observer>> GetBG_Tile() const override;

        //This function returns a vector of bonus views
        std::vector<std::shared_ptr<Observer>> GetBonus() const override;

        //This function returns a vector of enemy views
        std::vector<std::shared_ptr<Observer>> GetEnemy() const override;

        //This function returns a pointer to the player view
        std::shared_ptr<Observer> GetPlayer() const override;

        //This function returns a vector of ball views
        std::vector<std::shared_ptr<Observer>> GetShots() const override;

        //This function sets the value of the platforms view to "plat"
        void SetPlatforms(std::vector<std::shared_ptr<Observer>> plat) override;

        //This function deletes the "plat" platform from the vector "platforms"
        void Delete_platform_it(std::shared_ptr<Platform_Model> plat) override;

        //This function deletes the "enemy" enemy from the vector "Enemy"
        void Delete_enemy_it(std::shared_ptr<Entity_Model> enemy) override;

        //This function deletes the "bonus" bonus from the vector "Bonus"
        void Delete_bonus_it(std::shared_ptr<Bonus_Model> bonus) override;

        //This function deletes the "ball" shot from the vector "Shots"
        void Delete_Shot_It(std::shared_ptr<Ball_Model> ball) override;

private:
        //Vector with all platform views
        std::vector<std::shared_ptr<Observer>> platforms = {};

        //Vector with all background tile views
        std::vector<std::shared_ptr<Observer>> BG_Tile = {};

        //Vector with all bonus views
        std::vector<std::shared_ptr<Observer>> Bonus = {};

        //Pointer with the player view
        std::shared_ptr<Observer> player = nullptr;

        //Vector with all enemy views
        std::vector<std::shared_ptr<Observer>> Enemy = {};

        //Vector withh all shot (ball) views
        std::vector<std::shared_ptr<Observer>> Shots = {};
        Vector2f RenderWindowSize = Vector2f(0, 0);
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_CONCRETE_FACTORY_H

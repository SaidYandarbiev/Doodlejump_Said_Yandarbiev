//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_ABSTRACT_FACTORY_H
#define DOODLEJUMP_SAID_YANDARBIEV_ABSTRACT_FACTORY_H


#include "BG_Tile_Model.h"
#include "Bonus_Model.h"
#include "Platform_Model.h"
#include "Player_Model.h"
#include "Simple_Enemy_Model.h"
#include "Complex_Enemy_Model.h"
#include "../Game_Representation/Player_View.h"
#include "../Vector2.h"
#include "Ball_Model.h"




class Abstract_Factory
{
public:
        //Constructor
        Abstract_Factory() = default;

        //This function is used to create and return the player model
        virtual std::shared_ptr<Player_Model> CreatePlayer_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera);

        //This function is used to create and return a platform model
        virtual std::shared_ptr<Platform_Model> CreatePlatform_Model(Vector2f vector2I, bool vertical, bool horizontal, bool breaking,
                                             bool broken, bool notmoving, std::shared_ptr<Utility::Camera> camera);

        //This function is used to create and return a background tile model
        virtual std::shared_ptr<BG_Tile_Model> CreateBG_Tile_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera);

        //This function is used to create and return a bonus model
        virtual std::shared_ptr<Bonus_Model> CreateBonus_Model(Vector2f vector2I, bool spring, bool helicopter,
                                                               bool health, bool spikes, std::shared_ptr<Utility::Camera> camera);

        //This function is used to create and return a simple enemy model
        virtual std::shared_ptr<Simple_Enemy_Model> CreateSimple_Enemy_Model(Vector2f vector2I, std::shared_ptr<Utility::Camera> camera);

        //This function is used to create and return a complex enemy model
        virtual std::shared_ptr<Complex_Enemy_Model> CreateComplex_Enemy_Model(Vector2f vector2F, std::shared_ptr<Utility::Camera> camera);

        //This function is used to create and return a ball model
        virtual std::shared_ptr<Ball_Model> CreateBall_Model(Vector2f vector2F, bool enemy, bool player, std::shared_ptr<Utility::Camera> camera);

        //This function is used to create and return the view of the player
        virtual std::shared_ptr<Player_View> CreatePlayer_View(Vector2f vector2I, Direction direction);

        //This function is used to create and return the view of a platform
        virtual std::shared_ptr<Platform_View> CreatePlatform_View(Vector2f vector2I, bool vertical, bool horizontal, bool breaking,
                                           bool broken, bool notmoving);

        //This function is used to create and return the view of a background tile
        virtual std::shared_ptr<BG_Tile_View> CreateBG_Tile_View(Vector2f vector2I, float x);

        //This function is used to create and return the view of a bonus
        virtual std::shared_ptr<Bonus_View> CreateBonus_View(Vector2f vector2I, bool spring, bool copter, bool health, bool spikes);

        //This function is used to create and return the view of a simple enemy
        virtual std::shared_ptr<Simple_Enemy_View> CreateSimple_Enemy_View(Vector2f vector2I);

        //This function is used to create and return the view of a complex enemy
        virtual std::shared_ptr<Complex_Enemy_View> CreateComplex_Enemy_View(Vector2f vector2F);

        //This function is used to create and return the view of a ball
        virtual std::shared_ptr<Ball_View> CreateBall_View(Vector2f vector2F);

        //This function deletes the first bonus view in the vector "Bonus"
        virtual void Pop_Bonus_Front();

        //This function deletes the first platform view in the vector "platforms"
        virtual void Pop_Platfrom_Front();

        //This function returns a vector of platform views
        virtual std::vector<std::shared_ptr<Observer>> GetPlatform() const;

        //This function returns a vector of background tile views
        virtual std::vector<std::shared_ptr<Observer>> GetBG_Tile() const;

        //This function returns a vector of bonus views
        virtual std::vector<std::shared_ptr<Observer>> GetBonus() const;

        //This function returns a vector of enemy views
        virtual std::vector<std::shared_ptr<Observer>> GetEnemy() const;

        //This function returns a pointer to the player view
        virtual std::shared_ptr<Observer> GetPlayer() const;

        //This function returns a vector of ball views
        virtual std::vector<std::shared_ptr<Observer>> GetShots() const;

        //This function sets the value of the platforms view to "plat"
        virtual void SetPlatforms(std::vector<std::shared_ptr<Observer>> plat);

        //This function deletes the "plat" platform from the vector "platforms"
        virtual void Delete_platform_it(std::shared_ptr<Platform_Model> plat);

        //This function deletes the "enemy" enemy from the vector "Enemy"
        virtual void Delete_enemy_it(std::shared_ptr<Entity_Model> enemy);

        //This function deletes the "bonus" bonus from the vector "Bonus"
        virtual void Delete_bonus_it(std::shared_ptr<Bonus_Model> bonus);

        //This function deletes the "ball" shot from the vector "Shots"
        virtual void Delete_Shot_It(std::shared_ptr<Ball_Model> ball);


};

#endif // DOODLEJUMP_SAID_YANDARBIEV_ABSTRACT_FACTORY_H

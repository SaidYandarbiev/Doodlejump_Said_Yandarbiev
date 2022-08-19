//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_WORLD_H
#define DOODLEJUMP_SAID_YANDARBIEV_WORLD_H

#include "Abstract_Factory.h"
#include "../Vector2.h"
#include "Camera.h"
#include "Random.h"
#include "SFML/Graphics.hpp"
#include "States.h"
#include "iostream"
#include "string"
#include "vector"
#include <algorithm>
#include "Score.h"

class World
{
public:
        //Constructor
        World(Vector2u l_windSize, const std::shared_ptr<Abstract_Factory>& confac);;

        //Updates every model and every view inside the world
        void Update();

        //Returns the pointer to the state class
        std::shared_ptr<Utility::States> GetState() { return states; }

        //This function is called at the start of the game when the world is made
        //It makes all the bg tiles of the first screen in the game
        void BG_TileSpawner();

        //This function is called at the start of the game when the world is made
        //It makes all the platforms of the first screen in the game
        void PlatformSpawner();

        //Returns the player model
        std::shared_ptr<Player_Model> GetPlayer() { return player; }

        //Returns the score pointer
        std::shared_ptr<Score> GetScore(){return score;}

        //Returns a boolean that determines if the game is ended or not
        bool getGameEnded() const;

private:

        //The size of the window of the game and world
        Vector2u m_windowSize = Vector2u(0, 0);

        //Pointer to the abstract factory
        std::shared_ptr<Abstract_Factory> concreteFactory;

        //Size of the world in the x-axis
        Vector2f XWorldSize = Vector2f(0, 20);

        //Size of the world in the y-axis
        Vector2f YWorldSize = Vector2f(0, 60);

        //Pointer to player model
        std::shared_ptr<Player_Model> player = nullptr;

        //Vector with all the platform models
        std::vector<std::shared_ptr<Platform_Model>> platforms;

        //Vector with all the bg tile models
        std::vector<std::vector<std::shared_ptr<BG_Tile_Model>>> BG;

        //Vector with all the bonus models
        std::vector<std::shared_ptr<Bonus_Model>> Bonus;

        //Vector with all the enemy models
        std::vector<std::shared_ptr<Enemy_Model>> Enemies;

        //Vector with all the shot models
        std::vector<std::shared_ptr<Ball_Model>> Shots;

        //Pointer to the camera
        std::shared_ptr<Utility::Camera> camera;

        //Pointer to the random class
        std::unique_ptr<Utility::Random> random = static_cast<std::unique_ptr<Utility::Random>>(Utility::Random::getInstance());

        //Float containing the previous y position of the camera
        float previouscameray = 0;

        //Float containing the current y position of the camera
        float currentcameray;

        //The chances that a specific platform will spawn
        std::vector<std::pair<float, std::string>> PlatformChances = {};

        //The chances that a specific bonus will spawn
        std::vector<std::pair<float, std::string>> BonusChances = {};

        //The chances that a specific enemy will spawn
        std::vector<std::pair<float,std::string>> EnemyChances = {};

        //Chance that a platform will spawn
        float platchance = 0.80;

        //Chance that a bonus will spawn
        float bonuschance = 0.4;

        //Chance that a enemy will spawn
        float enemychance = 0.3;

        //Pointer to the states class
        std::shared_ptr<Utility::States> states = nullptr;

        //Pointer to the score class with the current score of the player
        std::shared_ptr<Score> score = std::make_shared<Score>();
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_WORLD_H

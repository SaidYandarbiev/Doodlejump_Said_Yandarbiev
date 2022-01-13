//
// Created by said2 on 17-11-2021.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_GAME_H
#define DOODLEJUMP_SAID_YANDARBIEV_GAME_H
#include "../window.h"
#include "string"

#include "../Logic/Camera.h"
#include "../Logic/Entity_Model.h"
#include "../Logic/Stopwatch.h"
#include "../Logic/World.h"
#include "Concrete_Factory.h"

class Game
{
public:
        Game(std::string title, sf::Vector2u vector2U);
        ~Game();

        World* GetWorld() { return m_world; }
        void HandleInput();

        Observer* GetPlayer() { return player; }
        void Update();

        void Render();
        ;

        Window* GetWindow() { return m_window; };

private:
        Window* m_window = nullptr;
        World* m_world = nullptr;
        std::vector<Observer*> platforms = {};
        std::vector<Observer*> BG_Tiles = {};
        std::vector<Observer*> Bonus = {};
        Observer* player = nullptr;
        Concrete_Factory* concreteFactory = nullptr;
        double xsize;
        double ysize;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_GAME_H

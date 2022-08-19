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
        //Constructor
        Game(std::string title, sf::Vector2u vector2U);
        //Destructor
        ~Game();

        //This functions handles the keyboard inputs
        void HandleInput();

        void Update();

        //This functions renders the game every tick
        void Render();
        ;

        //This function returns the window
        Window* GetWindow() const { return m_window; };

        //This function returns the boolean ended
        //ended tells us if a game has ended or not
        bool GetEnded() const {return ended;}


private:
        //The game window
        Window* m_window = nullptr;

        //The world of the game
        std::shared_ptr<World> m_world = nullptr;

        //Vecotr with all the platform views
        std::vector<shared_ptr<Observer>> platforms = {};

        //Vector with all the bg tile views
        std::vector<shared_ptr<Observer>> BG_Tiles = {};

        //Vector with all the bonus views
        std::vector<shared_ptr<Observer>> Bonus = {};

        //Vector with all the enemy views
        std::vector<shared_ptr<Observer>> Enemies = {};

        //Vector with all the shot views
        std::vector<shared_ptr<Observer>> Shots = {};

        //Pointer with the player view
        shared_ptr<Observer> player = nullptr;

        //Pointer to the abstract factory
        shared_ptr<Abstract_Factory> concreteFactory = nullptr;

        //Text that displays the score
        sf::Text score;
        sf::Font font;

        //Text that displays "game over"
        sf::Text game_over;

        //Text that displays the current hp of the player
        sf::Text hp_counter;

        sf::Text hp;

        //Boolean that tells if our program has ended or not
        bool ended = false;

        //Boolean that tells us if the previous key state was the up key button
        bool previousKeyState;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_GAME_H

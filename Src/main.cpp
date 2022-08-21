//
// Created by said2 on 13-1-2022.
//

#include "Game_Representation/Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
        // Program entry point.
        Game game("Doodlejump", sf::Vector2u(600, 900)); // Creating our game object.

        while (!game.GetWindow()->IsDone()) {
                sf::Event event{};
                while (game.GetWindow()->m_window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                                game.GetWindow()->SetIsDone();
                        }
                }

                // Game loop.
                if (game.GetWindow()->m_window.isOpen() && !game.GetEnded()) {
                        game.HandleInput();
                        Utility::Stopwatch::getInstance()->tick();

                        Utility::Stopwatch::getInstance()->FrameBalancing();

                        game.Update();

                        game.Render();
                }

                if(game.GetEnded()){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                                exit(0);}
                }


                // Sleep for 0.2 seconds
        }

}
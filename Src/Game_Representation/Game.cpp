//
// Created by said2 on 17-11-2021.
//

#include "Game.h"

Game::Game(string title, sf::Vector2u vector2U)
{
        Vector2f vector2F = Vector2f(vector2U.x, vector2U.y);
        concreteFactory = make_shared<Concrete_Factory>(vector2F);
        Vector2u vector2U1(vector2U.x, vector2U.y);
        m_world = make_shared<World>(vector2U1, concreteFactory);
        m_window = new Window(title, vector2U);

        sf::Color color(0,0,0);
        font.loadFromFile("OpenSans-Bold.ttf");
        score.setFont(font);
        score.setFillColor(color);
        score.setPosition(25,25);

        hp.setFont(font);
        hp.setString("HP:");
        hp.setFillColor(color);
        hp.setPosition(480,25);

        hp_counter.setFont(font);
        hp_counter.setFillColor(color);
        hp_counter.setPosition(540,25);

}



void Game::Update()
{
        //In this function we update every vector with the corresponding vector in the concrete factory
        m_world->Update();

        Bonus = concreteFactory->GetBonus();

        platforms = concreteFactory->GetPlatform();

        //Only if our player is a nullptr can we update the player
        if (player == nullptr) {
                player = concreteFactory->GetPlayer();
        }

        BG_Tiles = concreteFactory->GetBG_Tile();

        Enemies = concreteFactory->GetEnemy();

        Shots = concreteFactory->GetShots();

        Utility::Stopwatch::getInstance()->FrameBalancing();

}

void Game::HandleInput()
{

        //First we update the clickedright and clickedleft with the key presses on our keyboard
        m_world->GetState()->ClickedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        m_world->GetState()->ClickedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

        //Then we check if our up key has been pressed
        bool KeyUpDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

        //If our up key has been pressed and our previouskey was not the upkey (so false) then we can let the player shoot
        //And set previousKeyState on true (because our previous pressed key was up)
        if(KeyUpDown && !previousKeyState){
                m_world->GetState()->Shooting = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
                previousKeyState = true;
        }
        //If we dont press the up key then our previousKeyState is false (because the up key was not the key pressed previously)
        if(!KeyUpDown){
                previousKeyState = false;
        }
}

void Game::Render()
{
        //If the program has not ended yet
        if(!ended) {

                m_window->BeginDraw(); // Clear the window

                std::shared_ptr<sf::Sprite> sprite;

                //We loop over every bg tile view and draw them
                for (int i = 0; i < BG_Tiles.size(); i++) {

                        sprite = BG_Tiles[i]->GetSprite();
                        m_window->Draw(*sprite);
                }
                //If our game has not ended yet enter this ifstatement
                if (!m_world->getGameEnded()) {
                        //Here we loop over every view vector (except bg tile) and draw every view
                        for (int i = 0; i < Bonus.size(); i++) {

                                sprite = Bonus[i]->GetSprite();
                                m_window->Draw(*sprite);
                        }
                        for (int i = 0; i < platforms.size(); i++) {
                                sprite = platforms[i]->GetSprite();
                                m_window->Draw(*sprite);
                        }

                        for (int i = 0; i < Enemies.size(); i++) {
                                sprite = Enemies[i]->GetSprite();
                                m_window->Draw(*sprite);
                        }

                        for (int i = 0; i < Shots.size(); i++){
                                sprite = Shots[i]->GetSprite();
                                m_window->Draw(*sprite);
                        }
                        sprite = player->GetSprite();

                        sprite->setPosition(player->sprite->getPosition().x, player->sprite->getPosition().y);

                        //Here we get the score and the hp and display them on the screen
                        int sscore = m_world->GetScore()->GetScore();
                        score.setString(to_string(sscore));
                        m_window->Draw(score);
                        m_window->Draw(*sprite);
                        m_window->Draw(hp);
                        hp_counter.setString(to_string(m_world->GetPlayer()->GetHp()->GetHealth()));
                        m_window->Draw(hp_counter);
                }
                //If our game has ended then enter this ifstatement
                else if (m_world->getGameEnded()) {
                        //Here we display a text "Game over" with under this text the current score that the player had
                        ended = m_world->getGameEnded();
                        game_over.setString("Game Over");
                        game_over.setFont(font);
                        game_over.setPosition(190, 330);
                        sf::Color color(0, 0, 0);
                        game_over.setFillColor(color);
                        game_over.setCharacterSize(40);
                        score.setPosition(230, 400);
                        m_window->Draw(game_over);
                        m_window->Draw(score);


                }

                m_window->EndDraw(); // Display
                //Here we reset the starttime of the stopwatch
                Utility::Stopwatch::getInstance()->Reset();
        }
}

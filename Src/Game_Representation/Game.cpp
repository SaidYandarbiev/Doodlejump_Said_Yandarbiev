//
// Created by said2 on 17-11-2021.
//

#include "Game.h"

Game::Game(string title, sf::Vector2u vector2U)
{
        Vector2f vector2F = Vector2f(vector2U.x, vector2U.y);
        concreteFactory = new Concrete_Factory(vector2F);
        Vector2u vector2U1(vector2U.x, vector2U.y);
        m_world = new World(vector2U1, concreteFactory);
        m_window = new Window(title, vector2U);

        xsize = vector2U.x;
        ysize = vector2U.y;
}

Game::~Game() {}

void Game::Update()
{

        m_world->Update();
        // World accessen en concrete factory pointer meegeven

        Bonus = concreteFactory->GetBonus();

        platforms = concreteFactory->GetPlatform();

        if (player == nullptr) {
                player = concreteFactory->GetPlayer();
        }

        BG_Tiles = concreteFactory->GetBG_Tile();

        Stopwatch::getInstance()->FrameBalancing();
}

void Game::HandleInput()
{

        m_world->GetState()->ClickedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        m_world->GetState()->ClickedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

void Game::Render()
{
        m_window->BeginDraw(); // Clear

        sf::Sprite* sprite;
        for (int i = 0; i < BG_Tiles.size(); i++) {

                sprite = BG_Tiles[i]->GetSprite();
                m_window->Draw(*sprite);
        }

        for (int i = 0; i < Bonus.size(); i++) {

                sprite = Bonus[i]->GetSprite();
                m_window->Draw(*sprite);
        }
        for (int i = 0; i < platforms.size(); i++) {
                sprite = platforms[i]->GetSprite();
                m_window->Draw(*sprite);
        }

        sprite = player->GetSprite();

        sprite->setPosition(player->sprite->getPosition().x, player->sprite->getPosition().y);
        m_window->Draw(*sprite);
        m_window->EndDraw(); // Display

        Stopwatch::getInstance()->Reset();
}

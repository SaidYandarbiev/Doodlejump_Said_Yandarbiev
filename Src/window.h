//
// Created by said2 on 13-1-2022.
//

#ifndef DOODLEJUMP_SAID_YANDARBIEV_WINDOW_H
#define DOODLEJUMP_SAID_YANDARBIEV_WINDOW_H

#include "SFML/Graphics.hpp"
#include "string"
using namespace std;

class Window
{
public:
        Window() { Setup("Window", sf::Vector2u(640, 480)); }
        Window(const string& l_title, const sf::Vector2u& l_size) { Setup(l_title, l_size); };
        ~Window() { Destroy(); };
        void BeginDraw() { m_window.clear(sf::Color::Black); };
        void EndDraw() { m_window.display(); };

        void Update()
        {
                sf::Event event;
                while (m_window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                                m_isDone = true;
                        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
                                ToggleFullscreen();
                        }
                }
        };

        bool IsDone() { return m_isDone; };
        bool IsFullscreen() { return m_isFullscreen; };
        sf::Vector2u GetWindowSize() { return m_windowSize; };
        void SetIsDone() { m_isDone = !m_isDone; }

        void ToggleFullscreen()
        {
                m_isFullscreen = !m_isFullscreen;
                Destroy();
                Create();
        };

        void Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); };

        sf::RenderWindow m_window;

private:
        void Setup(const std::string& l_title, const sf::Vector2u& l_size)
        {
                m_windowTitle = l_title;
                m_windowSize = l_size;
                m_isFullscreen = false;
                m_isDone = false;
                Create();
        };
        void Destroy() { m_window.close(); };
        void Create()
        {
                auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
                m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
        };

        sf::Vector2u m_windowSize;
        string m_windowTitle;
        bool m_isDone;
        bool m_isFullscreen;
};

#endif // DOODLEJUMP_SAID_YANDARBIEV_WINDOW_H

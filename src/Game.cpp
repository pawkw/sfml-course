#include "Game.hpp"
#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game()
:m_window(sf::VideoMode(640, 480), "PacWoman") {
    if(!m_font.loadFromFile("assets/font.ttf")) {
        throw std::runtime_error("Unable to load asset: font.ttf");
    }
    if(!m_texture.loadFromFile("assets/texture.png")) {
        throw std::runtime_error("Unable to load asset: texture.png");
    }
    if(!m_logo.loadFromFile("assets/logo.png")) {
        throw std::runtime_error("Unable to load asset: logo.png");
    }
  m_gameStates[GameState::NoCoin] = new NoCoinState(this);
  m_gameStates[GameState::GetReady] = new GetReadyState(this);
  m_gameStates[GameState::Playing] = new PlayingState(this);
  m_gameStates[GameState::Won] = new WonState(this);
  m_gameStates[GameState::Lost] = new LostState(this);

  changeGameState(GameState::NoCoin);

}

Game::~Game() {
  for(GameState* gameState : m_gameStates) {
    delete gameState;
  }
}

void Game::run() {
    sf::Clock frameClock;
    while (m_window.isOpen())
    {
        // Process events
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                m_window.close();

            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Escape)
                    m_window.close();

                // Insert coin
                if(event.key.code == sf::Keyboard::I)
                    m_currentState->insertCoin();

                // Start button
                if(event.key.code == sf::Keyboard::S)
                    m_currentState->pressStartButton();

                if(event.key.code == sf::Keyboard::Left)
                    m_currentState->moveJoystick(sf::Vector2i(-1, 0));
                if(event.key.code == sf::Keyboard::Right)
                    m_currentState->moveJoystick(sf::Vector2i(1, 0));
                if(event.key.code == sf::Keyboard::Up)
                    m_currentState->moveJoystick(sf::Vector2i(0, -1));
                if(event.key.code == sf::Keyboard::Down)
                    m_currentState->moveJoystick(sf::Vector2i(0, 1));
            }

        }
        m_currentState->update(frameClock.restart());
        m_window.clear(sf::Color(0, 0, 0));
        // Draw code here.
        m_currentState->draw(m_window);
        // Update the window
        m_window.display();

        m_window.setFramerateLimit(60);
        sf::sleep(sf::seconds(1.0f/60.0f));
    }
}

void Game::changeGameState(GameState::State gameState) {
  m_currentState = m_gameStates[gameState];
}

sf::Font& Game::getFont() {
    return m_font;
}

sf::Texture& Game::getTexture() {
    return m_texture;
}

sf::Texture& Game::getLogo() {
    return m_logo;
}

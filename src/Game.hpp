#ifndef PACWOMAN_GAME_HPP
#define PACWOMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include <array>

class Game {
public:
    Game();
    ~Game();

    void run();
    
    sf::Font& getFont();
    sf::Texture& getTexture();
    sf::Texture& getLogo();

    void changeGameState(GameState::State gameState);

private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::Count> m_gameStates;
    sf::Font m_font;
    sf::Texture m_logo;
    sf::Texture m_texture;
};

#endif // PACWOMAN_GAME_HPP

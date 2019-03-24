#include "GameState.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

template <typename T>

// Set the origin to horizontal and vertical center of the drawable.
void centerOrigin(T& drawable) {
  sf::FloatRect bound = drawable.getLocalBounds();
  drawable.setOrigin(bound.width/2, bound.height/2);
}


GameState::GameState(Game* game)
:m_game(game) {

}
Game* GameState::getGame() const {
  return m_game;
}

/**************************************
 * No coin state                      *
 **************************************/
NoCoinState::NoCoinState(Game* game)
:GameState(game) {
  m_sprite.setTexture(m_game->getLogo());
  m_sprite.setPosition(20, 50);

  m_text.setFont(m_game->getFont());
  m_text.setString("Insert coin");
  centerOrigin(m_text);
  m_text.setPosition(240, 150);
  m_displayText = true;
}

void NoCoinState::insertCoin() {
    getGame()->changeGameState(GameState::GetReady);
}

void NoCoinState::pressStartButton() {

}
void NoCoinState::moveJoystick(sf::Vector2i direction) {

}
void NoCoinState::update(sf::Time delta) {
  static sf::Time timeBuffer = sf::Time::Zero;
  timeBuffer += delta;

  while(timeBuffer >= sf::seconds(0.5)) {
      m_displayText = !m_displayText;
      timeBuffer -= sf::seconds(1);
  }
}
void NoCoinState::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);

    if(m_displayText)
      window.draw(m_text);
}

/**************************************
 * Get ready state                    *
 **************************************/
GetReadyState::GetReadyState(Game* game)
:GameState(game) {
    m_text.setFont(game->getFont());
    m_text.setString("Press start!");
    centerOrigin(m_text);
    m_text.setPosition(320, 240);
}

void GetReadyState::insertCoin() {

}
void GetReadyState::pressStartButton() {
    getGame()->changeGameState(GameState::Playing);
}
void GetReadyState::moveJoystick(sf::Vector2i direction) {

}
void GetReadyState::update(sf::Time delta) {

}
void GetReadyState::draw(sf::RenderWindow& window) {
    window.draw(m_text);
}

/**************************************
 * Playing state                      *
 **************************************/
PlayingState::PlayingState(Game* game)
:GameState(game) {

}

void PlayingState::insertCoin() {

}
void PlayingState::pressStartButton() {

}
void PlayingState::moveJoystick(sf::Vector2i direction) {
    if(direction.x==-1)
        getGame()->changeGameState(GameState::Lost);
    if(direction.x==1)
        getGame()->changeGameState(GameState::Won);
}
void PlayingState::update(sf::Time delta) {

}
void PlayingState::draw(sf::RenderWindow& window) {

}

/**************************************
 * Won state                          *
 **************************************/
WonState::WonState(Game* game)
:GameState(game) {
    m_text.setFont(game->getFont());
    m_text.setString("You won!");
    m_text.setCharacterSize(42);
    centerOrigin(m_text);
    m_text.setPosition(320, 240);
}

void WonState::insertCoin() {

}
void WonState::pressStartButton() {

}
void WonState::moveJoystick(sf::Vector2i direction) {

}
void WonState::update(sf::Time delta) {
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    if(timeBuffer.asSeconds() >= 5)
        getGame()->changeGameState(GameState::GetReady);
}
void WonState::draw(sf::RenderWindow& window) {
    window.draw(m_text);
}

/**************************************
 * Lost state                         *
 **************************************/
LostState::LostState(Game* game)
:GameState(game) {
    m_text.setFont(game->getFont());
    m_text.setString("You have lost.");
    centerOrigin(m_text);
    m_text.setPosition(320, 240);

    m_countDownText.setFont(game->getFont());
    m_countDownText.setCharacterSize(20);
    m_countDownText.setString("Insert coin to continue... 00");
    centerOrigin(m_countDownText);
    m_countDownText.setPosition(320, 300);
    m_countDown = sf::Time(sf::seconds(0));
}

void LostState::insertCoin() {
    getGame()->changeGameState(GameState::Playing);
}
void LostState::pressStartButton() {

}
void LostState::moveJoystick(sf::Vector2i direction) {

}
void LostState::update(sf::Time delta) {
    m_countDown += delta;

    if(m_countDown.asSeconds() >= 10) {
        m_countDown = sf::Time(sf::seconds(0));
        getGame()->changeGameState(GameState::NoCoin);
    }

    m_countDownText.setString("Insert a coin to continue... "+std::to_string(10-static_cast<int>(m_countDown.asSeconds())));
}
void LostState::draw(sf::RenderWindow& window) {
    window.draw(m_text);
    window.draw(m_countDownText);
}

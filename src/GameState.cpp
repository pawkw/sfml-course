#include "GameState.hpp"
#include <SFML/Graphics.hpp>

GameState::GameState(Game* game)
:m_game(game) {

}
Game* GameState::getGame() const {
  return m_game;
}

NoCoinState::NoCoinState(Game* game)
:GameState(game) {

}

void NoCoinState::insertCoin() {

}
void NoCoinState::pressStartButton() {

}
void NoCoinState::moveJoystick(sf::Vector2i direction) {

}
void NoCoinState::update(sf::Time delta) {

}
void NoCoinState::draw(sf::RenderWindow& window) {

}

GetReadyState::GetReadyState(Game* game)
:GameState(game) {

}

void GetReadyState::insertCoin() {

}
void GetReadyState::pressStartButton() {

}
void GetReadyState::moveJoystick(sf::Vector2i direction) {

}
void GetReadyState::update(sf::Time delta) {

}
void GetReadyState::draw(sf::RenderWindow& window) {

}

PlayingState::PlayingState(Game* game)
:GameState(game) {

}

void PlayingState::insertCoin() {

}
void PlayingState::pressStartButton() {

}
void PlayingState::moveJoystick(sf::Vector2i direction) {

}
void PlayingState::update(sf::Time delta) {

}
void PlayingState::draw(sf::RenderWindow& window) {

}

WonState::WonState(Game* game)
:GameState(game) {

}

void WonState::insertCoin() {

}
void WonState::pressStartButton() {

}
void WonState::moveJoystick(sf::Vector2i direction) {

}
void WonState::update(sf::Time delta) {

}
void WonState::draw(sf::RenderWindow& window) {

}

LostState::LostState(Game* game)
:GameState(game) {

}

void LostState::insertCoin() {

}
void LostState::pressStartButton() {

}
void LostState::moveJoystick(sf::Vector2i direction) {

}
void LostState::update(sf::Time delta) {

}
void LostState::draw(sf::RenderWindow& window) {

}

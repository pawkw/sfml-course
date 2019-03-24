#ifndef PacWoman_GAMESTATE_HPP
#define PacWoman_GAMESTATE_HPP

#include <SFML/Graphics.hpp>

class Game;

class GameState {
  public:
    enum State {
        NoCoin,
        GetReady,
        Playing,
        Won,
        Lost,
        Count
    };

    GameState (Game* game);
    Game* getGame() const;

    virtual void insertCoin()=0;
    virtual void pressStartButton()=0;
    virtual void moveJoystick(sf::Vector2i direction)=0;
    virtual void update(sf::Time delta)=0;
    virtual void draw(sf::RenderWindow& window)=0;

  private:
    Game* m_game;
};

class NoCoinState : public GameState {
public:
  NoCoinState (Game* game);
  void insertCoin();
  void pressStartButton();
  void moveJoystick(sf::Vector2i direction);
  void update(sf::Time delta);
  void draw(sf::RenderWindow& window);
};

class GetReadyState : public GameState {
public:
  GetReadyState (Game* game);
  void insertCoin();
  void pressStartButton();
  void moveJoystick(sf::Vector2i direction);
  void update(sf::Time delta);
  void draw(sf::RenderWindow& window);
};

class PlayingState : public GameState {
public:
  PlayingState (Game* game);
  void insertCoin();
  void pressStartButton();
  void moveJoystick(sf::Vector2i direction);
  void update(sf::Time delta);
  void draw(sf::RenderWindow& window);
};

class WonState : public GameState {
public:
  WonState (Game* game);
  void insertCoin();
  void pressStartButton();
  void moveJoystick(sf::Vector2i direction);
  void update(sf::Time delta);
  void draw(sf::RenderWindow& window);
};

class LostState : public GameState {
public:
  LostState (Game* game);
  void insertCoin();
  void pressStartButton();
  void moveJoystick(sf::Vector2i direction);
  void update(sf::Time delta);
  void draw(sf::RenderWindow& window);
};
#endif

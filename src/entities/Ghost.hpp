#ifndef PACWOMAN_GHOST_HPP
#define PACWOMAN_GHOST_HPP

#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "PacWoman.hpp"

class Ghost : public Character
{
public:
    Ghost(sf::Texture& texture);
    enum State {
        Strong,
        Weak
    };

    void setWeak(sf::Time duration);
    bool isWeak() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite m_visual;
    bool m_isWeak;
    sf::Time m_weaknessDuration;
};


#endif

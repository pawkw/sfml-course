#ifndef PACWOMAN_PACWOMAN_HPP
#define PACWOMAN_PACWOMAN_HPP

#include "Character.hpp"

class PacWoman : public Character
{
public:
    PacWoman(sf::Texture& texture);
    void die();

    bool isDead() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite m_visual;
    bool m_isDead;
};

#endif

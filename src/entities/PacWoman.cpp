#include "PacWoman.hpp"

PacWoman::PacWoman(sf::Texture& texture)
: m_visual(texture), m_isDead(false) {
    m_visual.setOrigin(20, 20);
}

void PacWoman::die() {
    m_isDead = true;
}

bool PacWoman::isDead() const {
    return m_isDead;
}

void PacWoman::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    if(!m_isDead)
        target.draw(m_visual, states);
}

#include "Bonus.hpp"

Bonus::Bonus(sf::Texture& texture)
: m_visual(texture) {
    setFruit(Banana);
    m_visual.setOrigin(15, 15);
}

void Bonus::setFruit(Fruit fruit) {
    m_visual.setTextureRect(sf::IntRect(32+fruit*30, 0, 30, 30));
}

void Bonus::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_visual, states);
}

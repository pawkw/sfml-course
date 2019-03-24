#include "Character.hpp"

Character::Character()
: m_speed(1.0f) {

}

void Character::setSpeed(float speed) {
    this->m_speed = speed;
}

float Character::getSpeed() const {
    return this->m_speed;
}

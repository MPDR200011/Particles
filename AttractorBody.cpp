#include "AttractorBody.h"

using namespace sf;

AttractorBody::AttractorBody(float mass, float radius, sf::Vector2f pos) {
    this->mass = mass;
    center = pos;
    shape = CircleShape(radius);
    shape.setPosition(pos - Vector2f(radius, radius));
}

void AttractorBody::moveCenter(sf::Vector2f delta) {
    center += delta;
    shape.move(delta);
}
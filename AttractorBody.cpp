#include "AttractorBody.h"

using namespace sf;

AttractorBody::AttractorBody(float mass, float radius, sf::Vector2f pos) {
    this->mass = mass;
    centerOfMass = pos;
    shape = CircleShape(radius);
    shape.setPosition(pos - Vector2f(radius, radius));
}

void AttractorBody::moveCenter(sf::Vector2f delta) {
    centerOfMass += delta;
    shape.move(delta);
}
#include "AttractorBody.h"

using namespace sf;

AttractorBody::AttractorBody(float mass, float radius, sf::Vector2f pos) : CircleShape(radius){
    this->mass = mass;
    centerOfMass = pos;
    CircleShape::setPosition(pos - Vector2f(radius, radius));
}

void AttractorBody::moveCenter(sf::Vector2f delta) {
    centerOfMass += delta;
    CircleShape::move(delta);
}
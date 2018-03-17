#include "CircleBody.h"

using namespace sf;

CircleBody::CircleBody() : Body(10.0, Vector2f(0, 0)) {
    shape = CircleShape(10);
    shape.setPosition(-10,-10);
}

CircleBody::CircleBody(float c_mass, float radius, sf::Vector2f pos, std::size_t pointCount) : Body(c_mass, pos) {
    shape = CircleShape(radius, pointCount);
    shape.setPosition(pos - Vector2f(radius, radius));
}

void CircleBody::moveCenter(Vector2f delta) {
    Body::moveCenter(delta);
    shape.move(delta);
}

void CircleBody::update(float deltaT, float pPMRatio) {
    Body::update(deltaT, pPMRatio);
    shape.move(velocity*deltaT);
}
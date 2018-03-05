#include "../headers/CircleBody.h"

using namespace sf;

CircleBody::CircleBody() : Body(10.0, Vector2f(0, 0)) {
    shape = CircleShape(10);
    shape.setPosition(-10,-10);
}

CircleBody::CircleBody(float c_mass, float radius, sf::Vector2f pos, std::size_t pointCount) : Body(c_mass, pos) {
    shape = CircleShape(radius, pointCount);
    shape.setPosition(pos - Vector2f(radius, radius));
}

CircleShape CircleBody::getShape() {
    return shape;
}
#include "CircleBody.h"

using namespace sf;

CircleBody::CircleBody() : Body(10.0, Vector2f(0, 0)), CircleShape(10) {
    setPosition(-10,-10);
}

CircleBody::CircleBody(float c_mass, float radius, sf::Vector2f pos, std::size_t pointCount) :
        Body(c_mass, pos),
        CircleShape(radius, pointCount){
    CircleShape::setPosition(pos - Vector2f(radius, radius));
}

void CircleBody::moveCenter(Vector2f &delta) {
    Body::moveCenter(delta);
    move(delta);
}

void CircleBody::update(float &deltaT) {
    Body::update(deltaT);
    CircleShape::move(velocity*deltaT);
}

Drawable &CircleBody::getShape(){
    return *this;
}
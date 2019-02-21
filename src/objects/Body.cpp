#include "Body.h"

using namespace sf;

Body::Body(){
    mass = 10.0;
    velocity = Vector2f();
}

Body::Body(float b_mass, Vector2f center){
    mass = b_mass;
    centerOfMass = center;
    velocity = Vector2f();
}

void Body::moveCenter(sf::Vector2f &delta) {
    centerOfMass += delta;
}

void Body::accelerate(Vector2f acceleration) {
    velocity += acceleration;
}

void Body::update(float &deltaT) {
    centerOfMass += velocity*deltaT;
}



#include "../headers/Body.h"

Body::Body(){
    mass = 10.0;
    velocity = Vector2f();
}

Body::Body(float b_mass, Vector2f center){
    mass = b_mass;
    centerOfMass = center;
    velocity = Vector2f();
}

sf::Vector2f Body::getCenterOfMass() {
    return centerOfMass;
}

float Body::getMass() {
    return mass;
}

void Body::accelerate(Vector2f acceleration) {
    velocity += acceleration;
}

virtual void Body::update() {
    centerOfMass += velocity;
}

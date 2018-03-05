#ifndef PARTICLE_SIMULATOR_BODY_H
#define PARTICLE_SIMULATOR_BODY_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Body{

protected:
    float mass;
    Vector2f velocity;
    Vector2f centerOfMass;

    virtual void update();

public:
    Body();
    Body(float mass, Vector2f center);

    Vector2f getCenterOfMass();
    float getMass();

    void accelerate(Vector2f acceleration);

};

#endif //PARTICLE_SIMULATOR_BODY_H

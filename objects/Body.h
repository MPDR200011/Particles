#ifndef PARTICLE_SIMULATOR_BODY_H
#define PARTICLE_SIMULATOR_BODY_H

#include <SFML/Graphics.hpp>

class Body{

public:
    float mass;
    sf::Vector2f velocity; //This is in pixels per second, any changes to this variable have to have this in mind
    sf::Vector2f centerOfMass;

    Body();
    Body(float mass, sf::Vector2f center);

    virtual void moveCenter(sf::Vector2f &delta) = 0;
    void accelerate(sf::Vector2f acceleration);
    virtual void update(float &deltaT) = 0;
    virtual sf::Drawable &getShape() = 0;
};

#endif //PARTICLE_SIMULATOR_BODY_H

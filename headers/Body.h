#ifndef PARTICLE_SIMULATOR_BODY_H
#define PARTICLE_SIMULATOR_BODY_H

#include <SFML/Graphics.hpp>

class Body{

protected:
    float mass;
    sf::Vector2f velocity;
    sf::Vector2f centerOfMass;

public:
    Body();
    Body(float mass, sf::Vector2f center);
};

#endif //PARTICLE_SIMULATOR_BODY_H

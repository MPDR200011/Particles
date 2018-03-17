#ifndef PARTICLE_SIMULATOR_ATTRACTORBODY_H
#define PARTICLE_SIMULATOR_ATTRACTORBODY_H

#include <SFML/Graphics.hpp>

class AttractorBody {

public:
    float mass; //Kilograms
    sf::Vector2f centerOfMass;
    sf::CircleShape shape;

    AttractorBody(float mass, float radius, sf::Vector2f pos);

    void moveCenter(sf::Vector2f delta);

};


#endif //PARTICLE_SIMULATOR_ATTRACTORBODY_H

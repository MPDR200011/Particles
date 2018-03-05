#ifndef PARTICLE_SIMULATOR_CIRCLEBODY_H
#define PARTICLE_SIMULATOR_CIRCLEBODY_H

#include "Body.h"
#include <SFML/Graphics.hpp>

class CircleBody : public Body{

private:
    sf::CircleShape shape;

public:
    CircleBody();
    CircleBody(float c_mass, float radius, sf::Vector2f pos, std::size_t pointCount = 30);
    sf::CircleShape getShape();
};


#endif //PARTICLE_SIMULATOR_CIRCLEBODY_H

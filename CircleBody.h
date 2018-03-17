#ifndef PARTICLE_SIMULATOR_CIRCLEBODY_H
#define PARTICLE_SIMULATOR_CIRCLEBODY_H

#include "Body.h"
#include <SFML/Graphics.hpp>

class CircleBody : public Body{

public:
    sf::CircleShape shape;

    CircleBody();
    CircleBody(float c_mass, float radius, sf::Vector2f pos, std::size_t pointCount = 30);

    void moveCenter(sf::Vector2f delta);
    void update(float DeltaT, float pPMRatio);
};


#endif //PARTICLE_SIMULATOR_CIRCLEBODY_H

#ifndef PARTICLE_SIMULATOR_CIRCLEBODY_H
#define PARTICLE_SIMULATOR_CIRCLEBODY_H

#include "Body.h"
#include <SFML/Graphics.hpp>

class CircleBody : public Body{

private:
    CircleShape shape;

public:
    CircleBody();
    CircleBody(float c_mass, float radius, sf::Vector2f pos, std::size_t pointCount = 30);

    CircleShape getShape();

    void update();
};


#endif //PARTICLE_SIMULATOR_CIRCLEBODY_H

#ifndef PARTICLE_SIMLULATOR_SIMMATH_H
#define PARTICLE_SIMLULATOR_SIMMATH_H

#include <SFML/Graphics.hpp>

namespace sm {

    extern const float G;

    sf::Vector2f getPointToPointVector(sf::Vector2f origin, sf::Vector2f end);
    sf::Vector2f getOrbitSpeed(float M1, float M2, float distance);

    float vectorMagnitude(sf::Vector2f vector);
    float distanceBetweenVectors(sf::Vector2f v1, sf::Vector2f v2);
}

#endif //PARTICLE_SIMLULATOR_SIMMATH_H

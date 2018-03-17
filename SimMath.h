#ifndef PARTICLE_SIMLULATOR_SIMMATH_H
#define PARTICLE_SIMLULATOR_SIMMATH_H

#include <SFML/Graphics.hpp>

const float pixelsPerMeter = 5.0;
const float G = 6.67408; //6.67408E-11

sf::Vector2f getPointToPointVector(sf::Vector2f origin, sf::Vector2f end);
float vectorMagnitude(sf::Vector2f vector);
float distanceBetweenVectors(sf::Vector2f v1, sf::Vector2f v2);

#endif //PARTICLE_SIMLULATOR_SIMMATH_H

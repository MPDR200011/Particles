#include "SimMath.h"
#include <cmath>

using namespace sf;

sf::Vector2f getPointToPointVector(sf::Vector2f origin, sf::Vector2f end) {
    return end - origin;
}

float vectorMagnitude(Vector2f vector){
    return sqrtf(powf(vector.x,2) + powf(vector.y,2));
}

float distanceBetweenVectors(sf::Vector2f v1, sf::Vector2f v2){
    return vectorMagnitude(getPointToPointVector(v1, v2));
}
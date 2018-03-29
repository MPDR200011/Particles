#include "SimMath.h"
#include "../../settings/AppSettings.h"
#include <cmath>

const float sm::G = 6.67408E-11; //6.67408E-11

sf::Vector2f sm::getPointToPointVector(sf::Vector2f origin, sf::Vector2f end) {
    return end - origin;
}

sf::Vector2f sm::getOrbitSpeed(float M1, float M2, float distance){

    float force = G * ((M1*M2)/powf(distance / pixelsPerMeter, 2));
    float acceleration = force / M2;
    float velocity = sqrtf(acceleration*(distance / pixelsPerMeter));

    return sf::Vector2f(velocity, 0.0F);

}

float sm::vectorMagnitude(sf::Vector2f vector){
    return sqrtf(powf(vector.x,2) + powf(vector.y,2));
}

float sm::distanceBetweenVectors(sf::Vector2f v1, sf::Vector2f v2){
    return vectorMagnitude(getPointToPointVector(v1, v2));
}
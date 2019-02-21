#ifndef PARTICLE_SIMULATOR_APPSETTINGS_H
#define PARTICLE_SIMULATOR_APPSETTINGS_H

#include "SFML/Graphics.hpp"

//Frame rate control
extern int ticksPerSecond;
extern float framePeriod;
extern float timeStep;
extern float timePerFrame;

//Units and Constants
extern const float pixelsPerMeter;

//Useful App data
extern sf::Vector2f windowCenter;
void updateWindowCenter(sf::RenderWindow &window);


#endif //PARTICLE_SIMULATOR_APPSETTINGS_H

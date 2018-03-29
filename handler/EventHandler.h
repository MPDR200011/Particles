#ifndef PARTICLE_SIMULATOR_EVENTHANDLER_H
#define PARTICLE_SIMULATOR_EVENTHANDLER_H

#include "SFML/Graphics.hpp"
#include "../core/SimulatorCore.h"

void handle(sf::RenderWindow &window, SimulatorCore core, sf::Event &event);

#endif //PARTICLE_SIMULATOR_EVENTHANDLER_H

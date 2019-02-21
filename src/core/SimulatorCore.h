#ifndef PARTICLE_SIMULATOR_SIMULATORCORE_H
#define PARTICLE_SIMULATOR_SIMULATORCORE_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "../objects/Body.h"
#include "../objects/AttractorBody.h"

class SimulatorCore {

public:
    std::vector<Body*> bodyVector;
    std::vector<AttractorBody> attractorVector;

    SimulatorCore() = default;

    void addBody(Body &body);
    void addAttractor(AttractorBody attractor);

    void moveCenters(sf::Vector2f delta);

};


#endif //PARTICLE_SIMULATOR_SIMULATORCORE_H

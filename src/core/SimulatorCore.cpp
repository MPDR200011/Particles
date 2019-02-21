#include "SimulatorCore.h"

using namespace sf;

void SimulatorCore::addBody(Body &body) {
    bodyVector.push_back(&body);
}

void SimulatorCore::addAttractor(AttractorBody attractor) {
    attractorVector.push_back(attractor);
}

void SimulatorCore::moveCenters(Vector2f delta) {
    for (Body* body: bodyVector){
        body->moveCenter(delta);
    }

    for (AttractorBody attractor: attractorVector){
        attractor.moveCenter(delta);
    }
}
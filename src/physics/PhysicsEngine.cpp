#include <cmath>
#include "PhysicsEngine.h"
#include "math/SimMath.h"
#include "../settings/AppSettings.h"

using namespace sf;
using namespace sm;

void update(SimulatorCore core){

    for (AttractorBody &attractor: core.attractorVector){

        for (Body *body: core.bodyVector){

            Vector2f directionVector = getPointToPointVector(body->centerOfMass, attractor.centerOfMass);
            float distance = distanceBetweenVectors(body->centerOfMass, attractor.centerOfMass);
            float distanceInMeters = distance / pixelsPerMeter;

            Vector2f normalizedDirectionVector = directionVector / distance;

            float force = G * ((attractor.mass * body->mass)/powf(distanceInMeters, 2));

            body->accelerate(normalizedDirectionVector * (force/body->mass) * pixelsPerMeter * timePerFrame);

            body->update(timePerFrame);

        }
    }
}
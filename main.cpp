#include <iostream>
#include <SFML/Graphics.hpp>
#include "handler/EventHandler.h"
#include "objects/CircleBody.h"
#include "physics/PhysicsEngine.h"
#include "physics/math/SimMath.h"
#include "settings/GlobalStates.h"
#include "settings/AppSettings.h"

using namespace sf;
using namespace std;
using namespace sm;

int main() {

    RenderWindow App(VideoMode(600, 600), "Particle Simulator");
    App.setView(AppView);

    SimulatorCore core;

    updateWindowCenter(App);

    CircleBody circle(5970, 5, Vector2f(300, 150));
    core.addBody(circle);
    core.bodyVector[0]->velocity = getOrbitSpeed(5.97E24, 5970, 150) * pixelsPerMeter;
    core.addAttractor(AttractorBody(5.97E24, 10, Vector2f(300,300)));

    //FPS Setup
    Time period = seconds(framePeriod);
    Time skip = seconds(0);
    Clock clock;

    //Time elapsed per frame definition

    while (App.isOpen()){

        Vertex line[2];

        Event event;

        //Event Poling and handling
        handle(App, core, event);

        //Update section
        if (!isPaused){
            update(core);
        }

        //Render section
        App.clear();
        App.draw(core.bodyVector[0]->getShape());
        App.draw(core.attractorVector[0]);
        App.draw(line, 2, Lines);
        App.display();

        Time elapsed = clock.restart();
        sleep(elapsed > period ? skip : period - elapsed );
    }

    return 0;
}
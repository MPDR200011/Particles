#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "CircleBody.h"
#include "AttractorBody.h"
#include "SimMath.h"

using namespace sf;
using namespace std;

int main() {

    RenderWindow App(VideoMode(600, 600), "Particle Simulator");
    View AppView(FloatRect(0,0,600,600));
    App.setView(AppView);

    Vector2f windowCenter(App.getView().getSize().x/2.0F, App.getView().getSize().y/2.0F);

    //10.5268
    CircleBody circle(10, 5, Vector2f(0,150));
    circle.velocity = Vector2f(8.94428, 0)*pixelsPerMeter;
    AttractorBody attractor(500, 10, Vector2f(300,300));

    bool isPaused = true;
    bool accelerated = false;

    float timeStep = 1/60.0F;
    Time period = seconds(timeStep);
    Time skip = seconds(0);
    Clock clock;
    while (App.isOpen()){

        Vertex line[2];

        Event event;

        //Event Poling and handling
        while (App.pollEvent(event)) {

            switch (event.type){
                case Event::Closed:
                    App.close();
                    break;

                case (Event::KeyPressed):
                    switch (event.key.code){
                        case Keyboard::P:
                            isPaused = !isPaused;
                            break;
                        case Keyboard::Escape:
                            App.close();
                            break;
                        case Keyboard::R:
                            break;
                    }
                    break;

                case Event::Resized:
                    FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    AppView.reset(visibleArea);
                    App.setView(AppView);

                    Vector2f delta(Vector2f(App.getView().getSize().x/2.0F, App.getView().getSize().y/2.0F)-windowCenter);
                    windowCenter = Vector2f(App.getView().getSize().x/2.0F, App.getView().getSize().y/2.0F);

                    circle.moveCenter(delta);
                    attractor.moveCenter(delta);
                    break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::F)){
            if (!accelerated){
                accelerated = true;
                timeStep *= 2.0F;
            }
        } else {
            accelerated = false;
            timeStep = 1/60.0F;
        }

        //Update section
        if (!isPaused){

            Vector2f directionVector = getPointToPointVector(circle.centerOfMass, attractor.centerOfMass);
            float distance = vectorMagnitude(directionVector);
            float distanceInMeters = distance / pixelsPerMeter;

            Vector2f normalizedDirectionVector = directionVector / distance;

            float force = G * ((attractor.mass * circle.mass)/powf(distanceInMeters, 2));

            circle.accelerate(normalizedDirectionVector * (force/circle.mass) * pixelsPerMeter * timeStep);

            circle.update(timeStep, pixelsPerMeter);
        }

        line[0] = Vertex(circle.centerOfMass);
        line[1] = Vertex(windowCenter);

        //Render section
        App.clear();
        App.draw(circle.shape);
        App.draw(attractor.shape);
        App.draw(line, 2, Lines);
        App.display();

        Time elapsed = clock.restart();
        sleep(elapsed > period ? skip : period - elapsed );
    }

    return 0;
}
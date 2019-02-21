#include "EventHandler.h"
#include "../settings/GlobalStates.h"
#include "../settings/AppSettings.h"

using namespace sf;

void handle(RenderWindow &window, SimulatorCore core, Event &event){
    while (window.pollEvent(event)) {

        switch (event.type){
            case Event::Closed:
                window.close();
                break;

            case (Event::KeyPressed):
                switch (event.key.code){
                    case Keyboard::P:
                        isPaused = !isPaused;
                        break;
                    case Keyboard::Escape:
                        window.close();
                        break;
                    case Keyboard::R:
                        break;
                }
                break;

            case Event::Resized:
                FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                AppView.reset(visibleArea);
                window.setView(AppView);

                Vector2f delta(Vector2f(window.getView().getSize().x/2.0F, window.getView().getSize().y/2.0F)-windowCenter);
                windowCenter = Vector2f(window.getView().getSize().x/2.0F, window.getView().getSize().y/2.0F);

                core.moveCenters(delta);
                break;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::F)){
        if (!accelerated){
            accelerated = true;
            timePerFrame *= 2.0F;
        }
    } else {
        accelerated = false;
        timePerFrame = timeStep;
    }
}
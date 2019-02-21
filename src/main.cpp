#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {

    RenderWindow app(VideoMode(800, 600), "Particle Simulator");

    Clock clock;
    while (app.isOpen()){

        Event event;
        while(app.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    app.close();
                    break;
                default:
                    break;
            }
        }
        

        Time elapsed = clock.restart();

        app.clear();

        app.display();

    }

    return 0;
}
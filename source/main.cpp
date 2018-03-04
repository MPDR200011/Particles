#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

    RenderWindow App(VideoMode(600, 600), "Particle Simulator");

    while (App.isOpen()){

        Event event;

        while (App.pollEvent(event)){

            if (event.type == Event::Closed)
                App.close();
        }

        App.display();
    }

    return 0;
}
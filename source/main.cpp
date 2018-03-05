#include <SFML/Graphics.hpp>
#include "../headers/CircleBody.h"

using namespace sf;

int main() {

    CircleBody circle(10, 10, Vector2f(300,300));

    RenderWindow App(VideoMode(600, 600), "Particle Simulator");

    while (App.isOpen()){

        Event event;

        while (App.pollEvent(event)){

            if (event.type == Event::Closed)
                App.close();
        }

        App.clear();
        App.draw(circle.getShape());
        App.display();
    }

    return 0;
}
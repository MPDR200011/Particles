#include <SFML/Graphics.hpp>
#include <cstdint>
#include <iostream>
#include <vector>
#include "ECSAdmin.hpp"
#include "Components.hpp"
#include "Systems.hpp"

using namespace sf;
using namespace std;

int main(int argc, char* argv[]) {
    int num;
    if (argc > 1) {
        try {
            num = atoi(argv[1]);
        } catch (...) {
            num = 200;
        }
    } else {
        num = 200;
    }

    const uint32_t width = 1280;
    const uint32_t height = 720;

    cout << "Starting window.\n";
    sf::RenderWindow app = RenderWindow(VideoMode(width, height), "Particle Simulator", Style::Titlebar);
    ECSAdmin admin;
    admin.createSingleton(
        WindowComponent {
            .window = &app
        }
    );

    AppState* appState = admin.createSingleton(
        AppState {.paused=true}
    );

    cout << "Created window.\n";
    srand(time(nullptr));
    for (int i = 0; i < num; i++) {
        float x = rand() % width;
        float y = rand() % height;

        CircleShape shape(5);
        shape.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));

        admin.createEntity(
            PhysicsState {.position = Vector2f(x, y), .velocity = Vector2f(rand() % 100 - 50, rand() % 100 - 50)},
            MassComponent {.value = 100},
            DrawableComponent {.shape = shape}
        );
    }

    cout << "Generated particles.\n";

    ParticleGravitySystem grvSystem;
    ParticleUpdateSystem updateSystem;
    RenderSystem renderSystem;

    std::vector<BaseSystem*> systems {&grvSystem, &updateSystem, &renderSystem};

    Clock clock;
    Time frameTime = sf::milliseconds(16);
    Time zero;
    while (app.isOpen()) {

        Event event;

        while (app.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    app.close();
                    break;
                case Event::KeyPressed:
                    switch (event.key.code) {
                        case Keyboard::Escape:
                            app.close();
                            break;
                        case Keyboard::P:
                            appState->paused = !appState->paused;
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }

        admin.tickSystems(0.016, systems);

        app.display();
        Time elapsed = clock.restart();

        sleep(elapsed < frameTime ? frameTime - elapsed : zero);
    }

    cout << "Finished loop.\n";

    return 0;
}

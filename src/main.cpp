#include <SFML/Graphics.hpp>
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
#include "Particle.hpp"

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

    cout << "Starting window.\n";
    RenderWindow app(VideoMode(800, 600), "Particle Simulator",
                     Style::Titlebar);
    cout << "Created window.\n";
    srand(time(nullptr));
    for (int i = 0; i < num; i++) {
        float x = rand() % 800;
        float y = rand() % 600;
        // cout << "Spawning a particle at " << x << ", " << y << endl;
        auto* particle = new Particle(100, Vector2f(x, y));
        particle->setVelocity(Vector2f(rand() % 100 - 50, rand() % 100 - 50));
        particle->setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));
    }
    cout << "Generated particles.\n";

    CircleShape circ(5);
    float vel = 5;

    Clock clock;
    Time frameTime = sf::milliseconds(16);
    Time zero;
    bool paused = true;
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
                            paused = !paused;
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }

        if (!paused) {
            atomic<unsigned> current(0);
            vector<thread> threads;

            size_t numParticles = Particle::particles.size();
            for (int i = 0; i < 4; i++) {
                threads.emplace_back([&]() {
                    for (int i = 0; (i = current++) < numParticles;) {
                        Particle::particles[i]->preUpdate();
                    }
                });
            }

            for (thread& t : threads) {
                t.join();
            }

            for (Particle* p : Particle::particles) {
                p->update();
            }
        }

        app.clear();
        for (Particle* p : Particle::particles) {
            app.draw(p->getShape());
        }
        app.display();
        Time elapsed = clock.restart();

        sleep(elapsed < frameTime ? frameTime - elapsed : zero);
    }

    cout << "Finished loop.\n";

    for (Particle* particle : Particle::particles) {
        delete particle;
    }

    return 0;
}

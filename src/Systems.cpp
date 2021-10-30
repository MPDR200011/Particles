#include "Systems.hpp"
#include "Components.hpp"
#include <iostream>
#include <atomic>
#include <thread>
#include <cmath>

ParticleGravitySystem::ParticleGravitySystem() {
    setRequirements({PhysicsState::ID, MassComponent::ID});
}

void ParticleGravitySystem::tick(double timestep) {
    if (getSingleton<AppState>()->paused) {
        return;
    }

    auto entities = getEntities();

    std::atomic<size_t> current(0);
    std::vector<std::thread> threads;

    auto windowSize = getSingleton<WindowComponent>()->window->getSize();
    size_t numParticles = entities.size();
    for (int i = 0; i < 4; i++) {
        threads.emplace_back([&]() {
            for (size_t i = 0; (i = current++) < numParticles;) {
                PhysicsState* comp = getComponent<PhysicsState>(entities[i]);
                MassComponent* mass = getComponent<MassComponent>(entities[i]);
                for (size_t j = 0; j < entities.size(); j++) {
                    if (j == i) {
                        continue;
                    }

                    PhysicsState* dest = getComponent<PhysicsState>(entities[j]);
                    MassComponent* destMass = getComponent<MassComponent>(entities[j]);

                    auto destPosition = dest->position;

                    sf::Vector2f direction = destPosition - comp->position;
                    float distance = sqrtf(powf(direction.x, 2) + powf(direction.y, 2)) * 0.1f;
                    if (distance < 1) {
                        continue;
                    }

                    // Gravity across margins
                    std::vector<sf::Vector2f> destPositions = {
                        destPosition + sf::Vector2f(windowSize.x, 0),
                        destPosition + sf::Vector2f(-(float)windowSize.x, 0),
                        destPosition + sf::Vector2f(0, windowSize.y),
                        destPosition + sf::Vector2f(0, -(float)windowSize.y),
                        destPosition + sf::Vector2f(windowSize.x, windowSize.y),
                        destPosition + sf::Vector2f(-(float)windowSize.x, windowSize.y),
                        destPosition + sf::Vector2f(windowSize.x, -(float)windowSize.y),
                        destPosition + sf::Vector2f(-(float)windowSize.x, -(float)windowSize.y),
                    };

                    int counter = 0;
                    for (const auto& reflectedDest: destPositions) {
                        sf::Vector2f reflectedDirection = reflectedDest - comp->position;
                        float reflectedDistance = sqrtf(powf(reflectedDirection.x, 2) + powf(reflectedDirection.y, 2)) * 0.1f;

                        if (reflectedDistance < 1) {
                            continue;
                        }

                        if (reflectedDistance < distance) {
                            distance = reflectedDistance;
                            direction = reflectedDirection;
                        }
                    }

                    direction /= distance;

                    float attractionForceMag = mass->value * destMass->value / powf(distance, 2);
                    // NaN check
                    if (attractionForceMag == attractionForceMag) {
                        sf::Vector2f gravForce = direction * attractionForceMag;
                        comp->velocity += gravForce / mass->value * (float) timestep;
                    }
                }
            }
        });
    }

    for (std::thread& t : threads) {
        t.join();
    }
}

ParticleUpdateSystem::ParticleUpdateSystem() {
    setRequirements({PhysicsState::ID});
};

void ParticleUpdateSystem::tick(double timestep) {
    if (getSingleton<AppState>()->paused) {
        return;
    }

    auto entities = getEntities();

    std::atomic<size_t> current(0);
    std::vector<std::thread> threads;

    auto windowSize = getSingleton<WindowComponent>()->window->getSize();
    size_t numParticles = entities.size();
    for (int i = 0; i < 4; i++) {
        threads.emplace_back([&]() {
            for (size_t i = 0; (i = current++) < numParticles;) {
                PhysicsState* state = getComponent<PhysicsState>(entities[i]);

                state->position += state->velocity *  (float) timestep;

                auto position = state->position;
                if (position.x < 0) {
                    state->position.x = windowSize.x + position.x;
                } else if (position.x > windowSize.x) {
                    state->position.x = position.x - windowSize.x ;
                } 
                if (position.y < 0) {
                    state->position.y = windowSize.y + position.y;
                } else if (position.y > windowSize.y) {
                    state->position.y = position.y - windowSize.y ;
                }
            }
        });
    }

    for (std::thread& t : threads) {
        t.join();
    }
}

RenderSystem::RenderSystem() {
    setRequirements({DrawableComponent::ID, PhysicsState::ID});
}

void RenderSystem::tick(double timestep) {
    WindowComponent* window = getSingleton<WindowComponent>();
    auto windowSize = window->window->getSize();
    window->window->clear();
    for (EntityHandle ent: getEntities()) {
        PhysicsState* pos = getComponent<PhysicsState>(ent);
        DrawableComponent* comp = getComponent<DrawableComponent>(ent);

        comp->shape.setPosition(pos->position);
        window->window->draw(comp->shape);

        auto radius = comp->shape.getRadius();
        auto position = comp->shape.getPosition();
        if (position.x - radius < 0) {
            position.x += windowSize.x;
        } else if (position.x + radius > windowSize.x) {
            position.x -= windowSize.x ;
        } 

        if (position.y - radius < 0) {
            position.y += windowSize.y;
        } else if (position.y + radius > windowSize.y) {
            position.y -= windowSize.y ;
        }
        comp->shape.setPosition(position);

        window->window->draw(comp->shape);
    }
}

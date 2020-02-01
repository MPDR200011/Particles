#include "Systems.hpp"
#include "Components.hpp"
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

                    sf::Vector2f direction = dest->position - comp->position;
                    float distance = sqrtf(powf(direction.x, 2) + powf(direction.y, 2)) * 0.1f;
                    if (distance < 1) {
                        continue;
                    }

                    direction /= distance;

                    float attractionForceMag = mass->value * destMass->value / powf(distance, 2);
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

    size_t numParticles = entities.size();
    for (int i = 0; i < 4; i++) {
        threads.emplace_back([&]() {
            for (size_t i = 0; (i = current++) < numParticles;) {
                PhysicsState* state = getComponent<PhysicsState>(entities[i]);

                state->position += state->velocity *  (float) timestep;
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
    window->window->clear();
    for (EntityHandle ent: getEntities()) {
        PhysicsState* pos = getComponent<PhysicsState>(ent);
        DrawableComponent* comp = getComponent<DrawableComponent>(ent);

        comp->shape.setPosition(pos->position);
        window->window->draw(comp->shape);
    }
}
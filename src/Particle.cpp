#include "Particle.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

size_t Particle::nextIndex = 0;
vector<Particle*> Particle::particles;
const float Particle::PARTICLE_RADIUS = 5;

Particle::Particle(float mass, Vector2f position)
    : position(position), shape(PARTICLE_RADIUS) {
    this->particleIndex = nextIndex++;
    this->mass = mass;
    shape.setOrigin(PARTICLE_RADIUS, PARTICLE_RADIUS);
    shape.setPosition(position);
    particles.push_back(this);
}

void Particle::setVelocity(Vector2f vel) {
    this->velocity = vel;
}

void Particle::setFillColor(Color color) {
    shape.setFillColor(color);
}

const CircleShape& Particle::getShape() {
    return this->shape;
}

void Particle::applyForce(Vector2f force) {
    velocity += force / mass * 0.016f;
}

void Particle::preUpdate() {
    for (Particle* particle : particles) {
        if (particle == this) {
            continue;
        }
        Vector2f direction = particle->position - position;
        float distance = sqrtf(powf(direction.x, 2) + powf(direction.y, 2)) * 0.1f;
        if (distance < 1) {
            continue;
        }
        direction /= distance;

        float attractionForceMag = mass * particle->mass / powf(distance, 2);
        if (attractionForceMag == attractionForceMag) {
            Vector2f gravForce = direction * attractionForceMag;
            applyForce(gravForce);
        }
    }
}

void Particle::update() {
    position += velocity * 0.016f;
    shape.move(velocity * 0.016f);
}


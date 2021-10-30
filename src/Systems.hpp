#pragma once

#include "System.hpp"

class ParticleGravitySystem: public BaseSystem {
public:
    ParticleGravitySystem();

    void tick(double timestep) override;
};

class ParticleUpdateSystem: public BaseSystem {
public:
    ParticleUpdateSystem();

    void tick(double timestep) override;
};

class RenderSystem: public BaseSystem {
public:
    RenderSystem();

    void tick(double timestep) override;
};
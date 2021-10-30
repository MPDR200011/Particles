#pragma once

#include <SFML/Graphics.hpp>
#include "Component.hpp"

struct PhysicsState : public ECSComponent<PhysicsState> {
    sf::Vector2f position;
    sf::Vector2f velocity;
};

struct MassComponent: public ECSComponent<MassComponent> {
    float value = 0;
};

struct DrawableComponent: public ECSComponent<DrawableComponent> {
    sf::CircleShape shape;
};

struct WindowComponent: public ECSComponent<WindowComponent> {
    sf::RenderWindow* window;
};

struct AppState: public ECSComponent<AppState> {
    bool paused = false;
};

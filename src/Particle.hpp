#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Particle {
public:
    static size_t nextIndex;
    static std::vector<Particle*> particles;
    static const float PARTICLE_RADIUS;
private:
    size_t particleIndex;
    float mass;
    sf::Color color;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::CircleShape shape;

public:
    Particle(float mass, sf::Vector2f position);

    void setVelocity(sf::Vector2f vel);
    void setFillColor(sf::Color color);

    const sf::CircleShape & getShape();

    void applyForce(sf::Vector2f force);
    void preUpdate();
    void update();
    void postUpdate();
};

#endif

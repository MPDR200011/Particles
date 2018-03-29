#ifndef PARTICLE_SIMULATOR_CIRCLEBODY_H
#define PARTICLE_SIMULATOR_CIRCLEBODY_H

#include "Body.h"
#include <SFML/Graphics.hpp>

class CircleBody : public Body, public sf::CircleShape{

public:
    CircleBody();
    CircleBody(float c_mass, float radius, sf::Vector2f pos, std::size_t pointCount = 30);

    void moveCenter(sf::Vector2f &delta) override;
    void update(float &DeltaT) override;
    sf::Drawable &getShape() override ;
};

#endif //PARTICLE_SIMULATOR_CIRCLEBODY_H

#pragma once

#include <set>

#include "Component.hpp"
#include "ECSPool.hpp"

class BaseSystem {
public:
    BaseSystem() {}
    BaseSystem(std::set<uint32_t>& req)
        : requiredComponents(req) {}
    BaseSystem(std::set<uint32_t>&& req)
        : requiredComponents(std::move(req)) {}

    virtual void tick(double timestep) = 0;

    template <Component Component>
    void addRequirement() {
        requiredComponents.insert(Component::ID);
    }

    void setPool(ECSPool* admin);
    void setRequirements(std::set<uint32_t>& req);
    void setRequirements(std::set<uint32_t>&& req);

    template <Component Component>
    Component* getSingleton() {
        return pool->getSingleton<Component>();
    }

    template <Component Component>
    Component* getComponent(Entity* entity) {
        return pool->getComponent<Component>(entity);
    }

protected:
    std::vector<Entity*> getEntities() {
        return pool->query(requiredComponents);
    }

private:
    ECSPool* pool;
    std::set<uint32_t> requiredComponents;
};

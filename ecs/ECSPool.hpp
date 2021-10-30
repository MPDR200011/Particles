#pragma once

#include <set>
#include <unordered_map>
#include <vector>

#include "Component.hpp"
#include "Entity.hpp"

typedef Entity* EntityHandle;

class ECSPool {
public:
    ECSPool() {}
    ~ECSPool();

    EntityHandle createEntity();

    void removeEntity(EntityHandle entityID);

    template <Component Component>
    void addComponent(EntityHandle entity, const Component& comp) {
        ECSComponentCreateFunction createfn =
            BaseECSComponent::getTypeCreateFunction(Component::ID);
        ComponentPool& pool = components[Component::ID];

        entity->components[Component::ID] = createfn(pool, entity, &comp);
    }

    template <Component... Components>
    EntityHandle createEntity(const Components&... comps) {
        EntityHandle entity = createEntity();

        (addComponent(entity, comps), ...);

        return entity;
    }

    template <Component Component>
    bool removeComponent(EntityHandle entity) {
        //check if entity has component
        auto search = entity->components.find(Component::ID);
        //delete it if it has
        if (search != entity->components.end()) {
            deleteComponent(Component::ID, search->second);
        }

        return entity->components.erase(Component::ID) > 0;
    }

    template <Component Component>
    Component* getComponent(EntityHandle entity) {
        auto search = entity->components.find(Component::ID);
        if (search != entity->components.end()) {
            //return the component in the pool
            return (Component*) &components[Component::ID][search->second];
        }

        return nullptr;
    }

    const std::vector<Entity*> query(const std::set<uint32_t>& req) {
        std::vector<Entity*> res;

        if (req.size() == 0) {
            return res;
        }

        uint32_t firstComp = *req.begin();

        ComponentPool& componentPool = components[firstComp];
        size_t compSize = BaseECSComponent::getTypeSize(firstComp);
        if (req.size() == 1) {
            for (size_t i = 0; i < componentPool.size(); i+=compSize) {
                res.push_back(((BaseECSComponent*) &componentPool[i])->entity);
            }

            return res;
        }

        for (size_t i = 0; i < componentPool.size(); i+=compSize) {
            BaseECSComponent* comp = (BaseECSComponent*) &componentPool[i];
            bool valid = true;
            for (uint32_t id : req) {
                if (!comp->entity->components.count(id)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                res.push_back(comp->entity);
            }
        }

        return res;
    }

    template <Component Component>
    Component* getSingleton() {
        return (Component*)singletons.at(Component::ID);
    }

    template <Component Component>
    Component* createSingleton(const Component& component) {
        if (singletons.count(Component::ID) > 0) {
            return (Component*)singletons[Component::ID];
        }

        BaseECSComponent* comp = new Component(*(Component*)&component);

        singletons[Component::ID] = comp;

        return (Component*)comp;
    }

    template <Component Component>
    void removeSingleton() {
        singletons.erase(Component::ID);
    }

private:
    void deleteComponent(uint32_t compoonentType, size_t index);

    std::unordered_map<uint32_t, BaseECSComponent*> singletons;
    std::unordered_map<uint32_t, ComponentPool> components;
    std::vector<Entity*> entities;
};

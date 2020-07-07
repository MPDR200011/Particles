#pragma once

#include <unordered_map>
#include "ComponentTypes.hpp"

typedef std::unordered_map<uint32_t, size_t> EntityComponentsMap;

struct Entity {
    size_t index;
    EntityComponentsMap components;
};

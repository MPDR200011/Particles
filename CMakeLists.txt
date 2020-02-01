cmake_minimum_required(VERSION 3.12)

project("Particle Sim")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE PHYS_SRC src/*.cpp src/*.hpp) 
add_executable(phys ${PHYS_SRC})

target_compile_options(phys
    PUBLIC -std=c++17
)

target_include_directories(phys
    PRIVATE ecs/
)

file(GLOB_RECURSE ECS_SRC ecs/*.cpp)
add_library(ECS
    ${ECS_SRC}
)

target_compile_options(ECS
    PUBLIC -std=c++17
)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

target_link_libraries(phys 
    sfml-graphics 
    Threads::Threads 
    ECS
)
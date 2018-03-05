cmake_minimum_required(VERSION 3.9)
project(Particle_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Particle_Simulator source/main.cpp source/Body.cpp headers/Body.h headers/CircleBody.h source/CircleBody.cpp)

set(SFML_ROOT "C:/Libraries/SFML-2.4.2-MinGw")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Particle_Simulator ${SFML_LIBRARIES})
endif()
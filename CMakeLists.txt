cmake_minimum_required(VERSION 3.12)

project(PhysicsSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

set(SRC)
file(GLOB_RECURSE SRC "src/*.cpp" "src/*.hpp" "src/*.c" "src/*.h")

add_executable(PhysicsSim ${SRC})
target_link_libraries(PhysicsSim sfml-graphics)
#Source file names and header file names go here as well as all the binaries

set(SOURCE_FILES main.cpp objects/Body.cpp objects/CircleBody.cpp objects/AttractorBody.cpp physics/math/SimMath.cpp objects/Body.h objects/CircleBody.h objects/AttractorBody.h physics/math/SimMath.h settings/GlobalStates.h handler/EventHandler.cpp handler/EventHandler.h settings/AppSettings.cpp settings/AppSettings.h physics/PhysicsEngine.cpp physics/PhysicsEngine.h settings/GlobalStates.cpp core/SimulatorCore.cpp core/SimulatorCore.h)
add_executable(Particle_Simulator ${SOURCE_FILES})

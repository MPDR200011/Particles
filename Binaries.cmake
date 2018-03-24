#Source file names and header file names go here as well as all the binaries

set(SOURCE_FILES main.cpp Body.cpp CircleBody.cpp AttractorBody.cpp SimMath.cpp)
set(HEADER_FILES Body.h CircleBody.h AttractorBody.h SimMath.h)
add_executable(Particle_Simulator ${SOURCE_FILES} ${HEADER_FILES})

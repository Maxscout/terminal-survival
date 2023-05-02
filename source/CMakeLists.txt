# CMakeList.txt : CMake project for terminal survival, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (survivaltest "main.cpp" "terminal survival.h" "game.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET survivaltest PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# CMakeList.txt : CMake project for FLORENCE_Server, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (FLORENCE_Server "FLORENCE_Server.cpp" "FLORENCE_Server.h" "Server.h" "Framework.h" "Algorithms.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FLORENCE_Server PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

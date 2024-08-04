# CMakeList.txt : CMake project for FLORENCE_Server, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (FLORENCE_Server "FLORENCE_Server.cpp" "FLORENCE_Server.h" "Server.h" "Framework.h" "Algorithms.h" "Execute.h" "Global.h" "Concurrent.h" "ListenRespond.h" "user_files/Praise0_Algorithm.h" "Control_Of_Data.h" "Input.h" "Control_Of_Input.h" "user_files/Praise0_Input.h" "Output.h" "Control_Of_Output.h" "user_files/Praise0_Output.h" "Control_Of_Algorithms.h" "Control_Of_Concurrent.h" "Control_Of_Execute.h" "Control_Of_LaunchConcurrency.h" "Control_Of_ListenRespond.h" "Control_Of_WriteEnable.h" "LaunchConcurrency.h" "WriteEnable.h" "user_files/Praise0_Input.cpp" "user_files/Praise0_Output.cpp" "user_files/Praise0_Algorithm.cpp" "Algorithms.cpp" "Concurrent.cpp" "Control_Of_Algorithms.cpp" "Control_Of_Data.cpp" "Control_Of_Execute.cpp" "Control_Of_Input.cpp" "Control_Of_LaunchConcurrency.cpp" "Control_Of_ListenRespond.cpp" "Control_Of_Output.cpp" "Control_Of_WriteEnable.cpp" "Data.cpp" "Execute.cpp" "Framework.cpp" "Global.cpp" "Input.cpp" "LaunchConcurrency.cpp" "ListenRespond.cpp" "Output.cpp" "Server.cpp" "WriteEnable.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FLORENCE_Server PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

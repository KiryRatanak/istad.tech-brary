cmake_minimum_required(VERSION 3.14)
project(TechBrary)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# xlnt
FetchContent_Declare(
  xlnt
  GIT_REPOSITORY https://github.com/tfussell/xlnt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(xlnt)

# tabulate
FetchContent_Declare(
  tabulate
  GIT_REPOSITORY https://github.com/p-ranav/tabulate.git
  GIT_TAG master
)
FetchContent_MakeAvailable(tabulate)

# All .cpp files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create executable
add_executable(TechBrary main.cpp ${SOURCES})

# Include header folder
target_include_directories(TechBrary PUBLIC include)

# Link libraries
target_link_libraries(TechBrary PRIVATE xlnt tabulate)

# Copy xlnt.dll after build (Windows)
add_custom_command(TARGET TechBrary POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/build/_deps/xlnt-build/source/Release/xlnt.dll"
    $<TARGET_FILE_DIR:TechBrary>)

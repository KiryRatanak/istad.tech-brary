cmake_minimum_required(VERSION 3.14)
project(CodaAtlas)
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

# Automatically collect all .cpp files in src/ and data/
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/data/*.cpp"
)

# Create executable
add_executable(CodaAtlas main.cpp ${SOURCES})

# Include header folder
target_include_directories(CodaAtlas PUBLIC include)

# Link libraries
target_link_libraries(CodaAtlas PRIVATE xlnt tabulate)

# Copy xlnt.dll after build (Windows)
add_custom_command(TARGET CodaAtlas POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/build/_deps/xlnt-build/source/Release/xlnt.dll"
    $<TARGET_FILE_DIR:CodaAtlas>)

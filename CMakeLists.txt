cmake_minimum_required(VERSION 3.14)
project(Fractal)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.0          # or "master" for latest
    GIT_SHALLOW    TRUE         # faster clone
)

# Optional: customize before making available
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

# Your executable
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE GL m pthread dl rt X11)
endif()
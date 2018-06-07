cmake_minimum_required(VERSION 3.10)
project(game_of_life)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-stdlib=libc++")

include_directories("include")
link_directories("lib")

FILE(GLOB_RECURSE SRC_LIST "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
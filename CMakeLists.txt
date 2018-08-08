cmake_minimum_required(VERSION 3.10)
project(game_of_life)

set(CMAKE_CXX_STANDARD 11)
if (APPLE)
    set(CMAKE_CXX_FLAGS "-stdlib=libc++")
endif ()

FILE(GLOB_RECURSE SRC_LIST "src/**.cpp")
add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# Copy resources into build
set(DATA_RESOURCES "${CMAKE_SOURCE_DIR}/resources")
set(DATA_RESOURCES_DEST "${CMAKE_CURRENT_BINARY_DIR}/resources")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${DATA_RESOURCES} ${DATA_RESOURCES_DEST}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${DATA_RESOURCES} => ${DATA_RESOURCES_DEST}"
)

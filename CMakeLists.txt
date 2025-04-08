cmake_minimum_required(VERSION 3.23)

set(project lab_8)
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        PractiseSTLApp.cpp)

set(${project}_HEADERS
        PractiseSTLApp.hpp)

add_subdirectory(DateClass)
add_subdirectory(TimeClass)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} DateClass)
target_link_libraries(${project} TimeClass)

add_custom_target(
    clang-format
    COMMAND clang-format
    -Werror
    ${SOURCES}
    ${HEADERS}
)

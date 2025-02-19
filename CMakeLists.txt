cmake_minimum_required(VERSION 3.23)

set(project Application)
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        Application.cpp)

set(${project}_HEADERS
        Application.hpp)

add_subdirectory(PlanetClass)
add_subdirectory(DataBase)
add_subdirectory(StringClass)
add_subdirectory(CandidateClass)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} PlanetClass)
target_link_libraries(${project} DataBase)
target_link_libraries(${project} StringClass)
target_link_libraries(${project} CandidateClass)


add_custom_target(
    clang-format
    COMMAND clang-format
    -Werror
    ${SOURCES}
    ${HEADERS}
)

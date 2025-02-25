cmake_minimum_required(VERSION 3.23)

set(project Application)
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        mathFractionApp.cpp)

set(${project}_HEADERS
    mathFractionApp.hpp)

add_subdirectory(FractionClass)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} FractionClass)

add_custom_target(
    clang-format
    COMMAND clang-format
    -Werror
    ${SOURCES}
    ${HEADERS}
)

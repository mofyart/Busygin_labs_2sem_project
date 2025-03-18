cmake_minimum_required(VERSION 3.23)

set(project CompositePolynomial)
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        CompositePolynomial.cpp)

set(${project}_HEADERS
        CompositePolynomial.hpp)

add_subdirectory(lib)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} lib)

add_custom_target(
    clang-format
    COMMAND clang-format
    -Werror
    ${SOURCES}
    ${HEADERS}
)

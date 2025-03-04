cmake_minimum_required(VERSION 3.23)

set(project MultipliersApp)
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        MultipliersApp.cpp)

set(${project}_HEADERS
        MultipliersApp.hpp)

add_subdirectory(MyStack)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} MyStack)

add_custom_target(
    clang-format
    COMMAND clang-format
    -Werror
    ${SOURCES}
    ${HEADERS}
)

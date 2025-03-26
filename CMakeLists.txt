cmake_minimum_required(VERSION 3.23)

set(project AppInstitution)
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        AppInstitution.cpp)

set(${project}_HEADERS
        AppInstitution.hpp)

add_subdirectory(HashTableClass)
add_subdirectory(InsitutionClass)
add_subdirectory(StringClass)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} HashTableClass)
target_link_libraries(${project} InsitutionClass)
target_link_libraries(${project} StringClass)

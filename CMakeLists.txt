cmake_minimum_required(VERSION 3.20)

project(archive LANGUAGES CXX)
# Appeler le projet du même nom que le répertoire
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

# Pour intégrer des modules maison
file(GLOB_RECURSE lib_source my_lib/*.cpp)
add_library(_modules_maison STATIC ${lib_source})

# Pour intégrer les modules readline
# include_directories(/usr/include/readline)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} _modules_maison)

install(TARGETS ${PROJECT_NAME} DESTINATION "~/bin/")


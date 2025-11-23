cmake_minimum_required(VERSION 4.0)
project(GameMotor)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameMotor main.cpp src/glad.c
        main.cpp)

# Trouver et lier la bibliothèque OpenGL
find_package(glfw3 REQUIRED)
target_link_libraries(GameMotor glfw)

# Ajouter le répertoire des en-têtes include
include_directories(include)

# Sur macOS, ajouter les frameworks nécessaires
if(APPLE)
    target_link_libraries(GameMotor "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()

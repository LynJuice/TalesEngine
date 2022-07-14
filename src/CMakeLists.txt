# Sets the minimum required CMake version
cmake_minimum_required(VERSION 3.22.1)
# Creates a project with the given name and version
project(TalesEngine VERSION 0.1.0)

add_executable(${PROJECT_NAME}
main.cpp
Engine/WindowManager.hpp
Engine/Shader.hpp
Engine/Objects/GameObject.hpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(TalesEngine glfw)
find_package(glm REQUIRED)
target_link_libraries(TalesEngine glm::glm)
find_package(glad REQUIRED)
target_link_libraries(TalesEngine glad::glad)
find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
target_include_directories(TalesEngine PRIVATE ${STB_INCLUDE_DIRS})
find_package(assimp REQUIRED)
target_link_libraries(TalesEngine assimp::assimp)
find_package(nlohmann_json REQUIRED)
target_link_libraries(TalesEngine nlohmann_json::nlohmann_json)
find_package(imgui REQUIRED)
target_link_libraries(TalesEngine imgui::imgui)



include(CPack)
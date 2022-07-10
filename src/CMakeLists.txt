cmake_minimum_required(VERSION 3.22.1)
project(TalesEngine VERSION 0.1.0)
include(CTest)
enable_testing()

add_executable(TalesEngine ../src/main.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(glad_DIR "/opt/vcpkg/installed/x64-linux/share/glad")
set(assimp_DIR "/opt/vcpkg/installed/x64-linux/share/assimp")
set(nlohmann_json_DIR "/opt/vcpkg/installed/x64-linux/share/nlohmann_json")
set(STB_INCLUDE_DIRS "/opt/vcpkg/installed/x64-linux/share/stb")
set(imgui_DIR "/opt/vcpkg/installed/x64-linux/share/imgui")

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
cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)
project(TalesEngine)

#   Adds the source files to the project
file(GLOB_RECURSE SOURCE_FILES
    #Insert Source folders here
    ${CMAKE_SOURCE_DIR}/TalesEngine.cpp
    ${CMAKE_SOURCE_DIR}/src/*.cpp  
)

#   Adds the header files to the project
file(GLOB_RECURSE HEADER_FILES
    #Insert Header folders here
    ${CMAKE_SOURCE_DIR}/TalesEngine.h
    ${CMAKE_SOURCE_DIR}/src/*.h
)

# Add .lib files to the project
link_directories(${CMAKE_SOURCE_DIR}/lib)

# --------------------------------------------------- Assets ---------------------------------------------------
file(GLOB TEXTURE_FILES
	${CMAKE_SOURCE_DIR}/src/assets/textures/*
)
file(COPY ${TEXTURE_FILES} DESTINATION ${CMAKE_BINARY_DIR}/assets/textures)

file(GLOB SHADER_FILES
	${CMAKE_SOURCE_DIR}/src/assets/shaders/*.glsl
)
file(COPY ${SHADER_FILES} DESTINATION ${CMAKE_BINARY_DIR}/assets/shaders)

file(GLOB MODEL_FILES
    ${CMAKE_SOURCE_DIR}/src/assets/models/*
)
file(COPY ${MODEL_FILES} DESTINATION ${CMAKE_BINARY_DIR}/assets/models)

# --------------------------------------------------- Executable ---------------------------------------------------
# Configure assets header file
configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)

include_directories(${CMAKE_BINARY_DIR}/src ${CMAKE_BINARY_DIR}/src/assets/shaders)

# Adds the executable to the project
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

#   Adds the libraries to the project
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# --------------------------------------------------- Librarys -----------------------------------------------------

# OpenGL
find_package(OpenGL REQUIRED)

# GLM
find_package(glm REQUIRED)
message(STATUS "GLM included")

# GLAD
find_package(glad REQUIRED)
message(STATUS "GLAD included")

# GLFW
find_package(glfw3 REQUIRED)
message(STATUS "GLFW included")

# Assimp
find_package(assimp REQUIRED)
message(STATUS "Assimp included")

find_package(imgui REQUIRED)
message(STATUS "imgui included")

# STB_IMAGE
add_library(STB_IMAGE "thirdparty/stb_image.cpp" "thirdparty/stb_image.h")

# Put all libraries into a variable
set(LIBS
    glm::glm
    glad::glad
    assimp::assimp
    imgui::imgui
    glfw
    opengl32
    STB_IMAGE
)

# Define the include directories
include_directories(
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/include"
)

# Link libraries to executables
target_link_libraries(${PROJECT_NAME} ${LIBS})
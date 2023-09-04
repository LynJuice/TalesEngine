cmake_minimum_required(VERSION 3.12)
project(TalesEngine)

set(CMAKE_CXX_STANDARD 17)

# TalesEngine Source Code
file(GLOB TalesEngine_SRC "src/*.h" "src/*.cpp")
file(GLOB TalesEngine_Graphics_Src "src/Graphics/2D/*.h" "src/Graphics/2D/*.cpp" "src/Graphics/3D/*.h" "src/Graphics/3D/*.cpp" "src/Graphics/*.h" "src/Graphics/*.cpp")
file(GLOB TalesEngine_Sound_SRC "src/Sound/*.h" "src/Sound/*.cpp")
file(GLOB TalesEngine_Includes include/sndFile/sndfile.h include/glad.c include/stb_image.h )

#add the executable
add_executable(TalesEngine ${TalesEngine_Includes} ${TalesEngine_SRC} ${TalesEngine_Graphics_Src} ${TalesEngine_Sound_SRC})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TalesEngine)
include_directories(${CMAKE_SOURCE_DIR}/include)
if(WIN32)
    link_directories(${CMAKE_SOURCE_DIR}/lib)

    #copy dlls to build directory
    file(GLOB DLLS ${CMAKE_SOURCE_DIR}/lib/*.dll)
    file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR})

    #copy libs to build directory
    file(GLOB LIBS ${CMAKE_SOURCE_DIR}/lib/*.lib)
    file(COPY ${LIBS} DESTINATION ${CMAKE_BINARY_DIR})

    target_link_libraries(TalesEngine ${CMAKE_SOURCE_DIR}/lib/assimp-vc143-mt.lib)
    target_link_libraries(TalesEngine ${CMAKE_SOURCE_DIR}/lib/sndfile.lib)
    target_link_libraries(TalesEngine ${CMAKE_SOURCE_DIR}/lib/OpenAl32.lib)

    #copy resources to build directory
    file(COPY ${CMAKE_SOURCE_DIR}/resources/shaders DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${CMAKE_SOURCE_DIR}/resources/textures DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${CMAKE_SOURCE_DIR}/resources/models DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${CMAKE_SOURCE_DIR}/resources/sounds DESTINATION ${CMAKE_BINARY_DIR})
endif()

target_link_libraries(TalesEngine glfw3)
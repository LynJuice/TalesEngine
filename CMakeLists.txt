set_property(GLOBAL PROPERTY USE_FOLDERS ON)
cmake_minimum_required(VERSION 3.12)
project(TalesEngine)

set(CMAKE_CXX_STANDARD 17)

# TalesEngine Source Code
file(GLOB TalesEngine_SRC_H "src/*.h")
file(GLOB TalesEngine_SRC_CPP "src/*.cpp")

file(GLOB TalesEngine_Graphics_Src_H "src/Graphics/*.h")
file(GLOB TalesEngine_Graphics_Src_CPP "src/Graphics/*.cpp")

file(GLOB TalesEngine_Graphics_3D_Src_H "src/Graphics/3D/*.h")
file(GLOB TalesEngine_Graphics_3D_Src_CPP "src/Graphics/3D/*.cpp")

file(GLOB TalesEngine_Graphics_2D_Src_H "src/Graphics/2D/*.h")
file(GLOB TalesEngine_Graphics_2D_Src_CPP "src/Graphics/2D/*.cpp")

file(GLOB TalesEngine_Sound_SRC_H "src/Sound/*.h")
file(GLOB TalesEngine_Sound_SRC_CPP "src/Sound/*.cpp")

file(GLOB TalesEngine_Game_SRC_H "src/Game/*.h")
file(GLOB TalesEngine_Game_SRC_CPP "src/Game/*.cpp")

file(GLOB TalesEngine_Includes include/sndFile/sndfile.h include/glad.c include/stb_image.h )

source_group("Header Files\\Game" FILES ${TalesEngine_Game_SRC_H})
source_group("Source Files\\Game" FILES ${TalesEngine_Game_SRC_CPP})
source_group("Header Files\\Graphics" FILES ${TalesEngine_Graphics_Src_H})
source_group("Source Files\\Graphics" FILES ${TalesEngine_Graphics_Src_CPP})
source_group("Header Files\\Graphics\\3D" FILES ${TalesEngine_Graphics_3D_Src_H})
source_group("Source Files\\Graphics\\3D" FILES ${TalesEngine_Graphics_3D_Src_CPP})
source_group("Header Files\\Graphics\\2D" FILES ${TalesEngine_Graphics_2D_Src_H})
source_group("Source Files\\Graphics\\2D" FILES ${TalesEngine_Graphics_2D_Src_CPP})
source_group("Header Files\\Sound" FILES ${TalesEngine_Sound_SRC_H})
source_group("Source Files\\Sound" FILES ${TalesEngine_Sound_SRC_CPP})
source_group("Header Files" FILES ${TalesEngine_SRC_H})
source_group("Source Files" FILES ${TalesEngine_SRC_CPP})
source_group("Includes" FILES ${TalesEngine_Includes})


#add the executable
add_executable(TalesEngine ${TalesEngine_Includes} ${TalesEngine_SRC_H} ${TalesEngine_SRC_CPP} ${TalesEngine_Graphics_Src_H} ${TalesEngine_Graphics_Src_CPP} ${TalesEngine_Sound_SRC_H} ${TalesEngine_Sound_SRC_CPP} ${TalesEngine_Graphics_3D_Src_H} ${TalesEngine_Graphics_3D_Src_CPP} ${TalesEngine_Graphics_2D_Src_H} ${TalesEngine_Graphics_2D_Src_CPP} ${TalesEngine_Game_SRC_H} ${TalesEngine_Game_SRC_CPP})


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
    file(COPY ${CMAKE_SOURCE_DIR}/resources/scenes DESTINATION ${CMAKE_BINARY_DIR})
    endif()

target_link_libraries(TalesEngine glfw3)
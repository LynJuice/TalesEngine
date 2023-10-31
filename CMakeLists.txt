set_property(GLOBAL PROPERTY USE_FOLDERS ON)
cmake_minimum_required(VERSION 3.12)
project(TalesEngine)

set(CMAKE_CXX_STANDARD 17)

# TalesEngine Source Code
file(GLOB TalesEngine_SRC_H "src/*.hpp")
file(GLOB TalesEngine_SRC_CPP "src/*.cpp")

# TalesEngine Include Directories
file(GLOB TalesEngine_INCLUDE include/sndFile/sndfile.h include/glad.c include/stb_image.h include/vulkan/vulkan.h)


# TalesEngine Source Groups
source_group("Header Files" FILES ${TalesEngine_SRC_H})
source_group("Source Files" FILES ${TalesEngine_SRC_CPP})
source_group("Include Files" FILES ${TalesEngine_INCLUDE})

# TalesEngine Executable
add_executable(TalesEngine 
    ${TalesEngine_SRC_H} 
    ${TalesEngine_SRC_CPP}
    ${TalesEngine_INCLUDE}
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TalesEngine)
include_directories(${CMAKE_SOURCE_DIR}/include)
if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/include)

    #copy dlls to build folder
    file(GLOB DLLS ${CMAKE_SOURCE_DIR}/lib/*.dll)
    file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR})

    #copy libs to build folder
    file(GLOB LIBS ${CMAKE_SOURCE_DIR}/lib/*.lib)
    file(COPY ${LIBS} DESTINATION ${CMAKE_BINARY_DIR})

    target_link_libraries(TalesEngine ${CMAKE_SOURCE_DIR}/lib/assimp-vc143-mt.lib)
    target_link_libraries(TalesEngine ${CMAKE_SOURCE_DIR}/lib/sndfile.lib)
    target_link_libraries(TalesEngine ${CMAKE_SOURCE_DIR}/lib/OpenAl32.lib)
    target_link_libraries(TalesEngine ${CMAKE_SOURCE_DIR}/lib/vulkan-1.lib)

endif()
target_link_libraries(TalesEngine glfw3)
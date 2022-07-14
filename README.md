# TalesEngine
A custom made engine. (More of a FrameWork than an Engine)
Works Crossplatform with Windows 10/11 Linux (Untested for MacOS)

## Setup
Just clone the project install the required vcpkg packages and you are good to go!
you may need to update CmakeLists.txt file to fit you.

  

### Install needed VCPKG packages
```bash
vcpkg install glfw3
vcpkg install glm
vcpkg install glad
vcpkg install stb
vcpkg install assimp
vcpkg install nlohmann-json
vcpkg install imgui[docking-experimental,glfw-binding,opengl3-binding] # Its required to to have glfw-binding and opengl3-binding while docking-experimental is optional, but there may be errors without it.
```

## How to build

```bash
# cd into the build folder
cd /build
# Run CMake on CMakeLists.txt (you can skip this step if you didn't change the CMake file)
cmake ../src/CMakeLists.txt
# build
make
```
  

## License

[MIT](https://choosealicense.com/licenses/mit/)

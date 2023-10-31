@echo off

"C:\VulkanSDK\1.3.268.0\Bin\glslc.exe" -fshader-stage=vertex -o shaders/build/vertex.spv shaders/vertex.vert
"C:\VulkanSDK\1.3.268.0\Bin\glslc.exe" -fshader-stage=fragment -o shaders/build/fragment.spv shaders/fragment.frag
pause
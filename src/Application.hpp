#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <map>
#include <optional>


struct QueueFamilyIndices
{
    std::optional<uint32_t > graphicsFamily;

    bool isComplete()
    {
		return graphicsFamily.has_value();
    }
};

class Application
{
private:
    /* data */
public:
    void run()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    void pickPhysicalDevice();
    void createLogicalDevice();
    bool checkValidationLayerSupport();
    bool isDeviceSuitable(VkPhysicalDevice device);
    int rateDeviceSuitability(VkPhysicalDevice device);
    std::vector<const char*> getRequiredExtensions();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    GLFWwindow *window;
    VkInstance instance;
    VkDevice device;
    VkQueue graphicsQueue;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT debugMessenger;

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
    const char *title = "TalesEngine";

    const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"};

    #ifdef NDEBUG
	const bool enableValidationLayers = false;
	#else
	const bool enableValidationLayers = true;
	#endif
};

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
#include <set>
#include <cstdint>
#include <algorithm>
#include <limits>
#include <fstream>

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete()
    {
		return graphicsFamily.has_value();
    }
};

struct SwapChainSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
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
    void createSurface();
    void createSwapChain();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createImageViews();
    void createGraphicsPipeline();
    bool checkValidationLayerSupport();
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    int rateDeviceSuitability(VkPhysicalDevice device);
    std::vector<const char*> getRequiredExtensions();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);
    VkShaderModule createShaderModule(const std::vector<char>& code);

    GLFWwindow *window;
    VkInstance instance;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    VkSwapchainKHR swapChain;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT debugMessenger;

    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    static std::vector<char> readFile(const std::string &filename);

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
    const char *title = "TalesEngine";
    const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

    const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"};

    #ifdef NDEBUG
	const bool enableValidationLayers = false;
	#else
	const bool enableValidationLayers = true;
	#endif
};

#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Application.hpp"



int main()
{
    Application app;

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
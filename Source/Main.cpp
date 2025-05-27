#include <iostream>
#include <chrono>
    
#include "OutputColorizer/Colorizer.hpp"

using namespace std::chrono_literals;

using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double>;

std::int32_t main(std::int32_t argc, char** argv)
{
    std::cout << LightAquaColorizer << "Hello, ConsoleTimer"
        << YellowColorizer << '\n';

    double timeInSeconds = 5;
    double printTimeInSeconds = 1;

    try
    {
        if (argc > 1)
        {
            timeInSeconds = std::atof(argv[1]);
        }
        if (argc > 2)
        {
            printTimeInSeconds = std::atof(argv[2]);
        }
    }
    catch(std::exception& exp)
    {
        std::cerr << RedColorizer << "[Error] " << exp.what()
            << StandardColorizer << std::endl;

        return EXIT_FAILURE;
    }

    const Duration endTime{ timeInSeconds };
    const Duration printTime{ printTimeInSeconds };

    const Clock::time_point start{ Clock::now() };
    Clock::time_point lastPrintTime{ start };

    std::cout << endTime.count() << "s\n";

    while (true)
    {
        const Clock::time_point now{ Clock::now() };

        const Duration passedTime{ now - start };
        const Duration passedPrintTime{ now - lastPrintTime };

        if (passedPrintTime > printTime)
        {
            std::cout << Duration{ endTime - passedTime }
                .count() << "s\n";

            lastPrintTime = now;
        }

        if (passedTime > endTime)
        {
            break;
        }
    }

    std::cout << StandardColorizer;

    return EXIT_SUCCESS;
}
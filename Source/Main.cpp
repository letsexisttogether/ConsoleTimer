#include <cstdio>
#include <iostream>
#include <cmath>
    
#include "OutputColorizer/Colorizer.hpp"
#include "Timer/Timer.hpp"

void FocusOnWindow() noexcept;
BOOL WINAPI HandleCtrlC(const DWORD ctrlType) noexcept;

std::int32_t main(std::int32_t argc, char** argv)
{
    if (!SetConsoleCtrlHandler(HandleCtrlC, TRUE))
    {
        std::cerr << RedColorizer << "[Error] Cannot setup the CTRL handler"
            << StandardColorizer << std::endl;

        return EXIT_FAILURE;
    }

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

    Timer mainTimer{ Timer::Duration{ timeInSeconds } };
    Timer printTimer{ Timer::Duration{ printTimeInSeconds } };

    std::cout << mainTimer.GetDuration().count() << "s\n";

    while (!mainTimer.IsTimePassed())
    {
        if (printTimer.IsTimePassed())
        {
            const double truncatedTime = 
                std::ceil(mainTimer.GetTimeLeft());

            std::cout << truncatedTime << "s\n";

            printTimer.Reset();
        }

    }

    FocusOnWindow();

    std::cout << LightAquaColorizer << "Time is over\n"
        << "Press Enter to exit" << StandardColorizer;
    std::getchar();

    return EXIT_SUCCESS;
}

void FocusOnWindow() noexcept
{
    HWND consoleWindow = GetConsoleWindow();

    if (consoleWindow)
    {
        SetForegroundWindow(consoleWindow);
        SetFocus(consoleWindow);
    }
}

BOOL WINAPI HandleCtrlC(const DWORD ctrlType) noexcept
{
    if (ctrlType == CTRL_C_EVENT)
    {
        std::cout << StandardColorizer;
    }

    return FALSE;
}
#pragma once

#include <ostream>
#include <Windows.h>

class OutputColorizer
{
public:
    enum Color : std::uint8_t
    {
        BLACK,
        BLUE,
        GREEN,
        AQUA,
        RED,
        PURPLE,
        YELLOW,

        LIGHT_GRAY,
        DARK_GRAY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_AQUA,
        LIGHT_RED,
        LIGHT_PURPLE,
        LIGHT_YELLOW,

        WHITE
    };

public:
    OutputColorizer() = default;
    OutputColorizer(const OutputColorizer&) = default;
    OutputColorizer(OutputColorizer&&) = default;

    OutputColorizer(const Color color) noexcept;

    ~OutputColorizer() = default;

    OutputColorizer& operator = (const OutputColorizer&) = default;
    OutputColorizer& operator = (OutputColorizer&&) = default;

    friend std::ostream& operator << (std::ostream& stream,
        const OutputColorizer& colorizer) noexcept;

private:
    Color m_Color{ Color::LIGHT_GRAY };
};


#define DefineColorizer(name, color) \
    inline OutputColorizer name##Colorizer{ OutputColorizer::Color::color };

DefineColorizer(Standard, LIGHT_GRAY)

DefineColorizer(Black, BLACK)
DefineColorizer(Blue, BLUE)
DefineColorizer(Green, GREEN)
DefineColorizer(Aqua, AQUA)
DefineColorizer(Red, RED)
DefineColorizer(Purple, PURPLE)
DefineColorizer(Yellow, YELLOW)

DefineColorizer(LightGray, LIGHT_GRAY)
DefineColorizer(DarkGray, DARK_GRAY)
DefineColorizer(LightBlue, LIGHT_BLUE)
DefineColorizer(LightGreen, LIGHT_GREEN)
DefineColorizer(LightAqua, LIGHT_AQUA)
DefineColorizer(LightRed, LIGHT_RED)
DefineColorizer(LightPurple, LIGHT_PURPLE)
DefineColorizer(LightYellow, LIGHT_YELLOW)

DefineColorizer(White, WHITE)

#undef DefineColorizer

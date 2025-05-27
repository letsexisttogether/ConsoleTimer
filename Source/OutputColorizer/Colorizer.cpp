#include "Colorizer.hpp"


OutputColorizer::OutputColorizer(const Color color) noexcept
    : m_Color{ color }
{}

std::ostream& operator << (std::ostream& stream,
    const OutputColorizer& colorizer) noexcept
{
    HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(stdHandle, colorizer.m_Color);

    return stream;
}

#include "Timer.hpp"

Timer::Timer(const Duration duration) noexcept
    : m_Duration{ duration }
{}


void Timer::Reset() noexcept
{
    m_Start = Clock::now();
}

bool Timer::IsTimePassed() const noexcept
{
    const Clock::time_point now{ Clock::now() };

    const Duration timePassed = now - m_Start;

    return timePassed > m_Duration;
}

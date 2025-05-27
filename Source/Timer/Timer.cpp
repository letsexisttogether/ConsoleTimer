#include "Timer.hpp"

Timer::Timer(const Duration duration) noexcept
    : m_Duration{ duration }
{}

double Timer::GetTimeLeft() const noexcept
{
    const Duration timePassed = Clock::now() - m_Start;

    return Duration{ m_Duration - timePassed }.count();
}

bool Timer::IsTimePassed() const noexcept
{
    return GetTimeLeft() <= 0.0;
}

void Timer::Reset() noexcept
{
    m_Start = Clock::now();
}

Timer::Clock::time_point Timer::GetStartTime() const noexcept
{
    return m_Start;
}

Timer::Duration Timer::GetDuration() const noexcept
{
    return m_Duration;
}

#pragma once

#include <chrono>

class Timer
{
public:
    using Clock = std::chrono::high_resolution_clock;
    using Duration = std::chrono::duration<double>;

public:
    Timer() = delete;
    Timer(const Timer&) = default;
    Timer(Timer&&) = default;

    Timer(const Duration duration) noexcept;

    ~Timer() = default;

    void Reset() noexcept;

    bool IsTimePassed() const noexcept;

    Timer& operator = (const Timer&) = default;
    Timer& operator = (Timer&&) = default;

private:
    Clock::time_point m_Start{ Clock::now() }; 
    Duration m_Duration{};
};

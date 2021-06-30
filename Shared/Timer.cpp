#include "Timer.h"
#include <windows.h>
#include <mmsystem.h>

/**
    Constructor for Timer

    Note: The timer class is used to measure high accuracy deltas between frames
*/
Timer::Timer(void)
{
    if (::QueryPerformanceFrequency((::LARGE_INTEGER*)&m_PerfFrequency)) 
    { 
        m_PerfHardware = TRUE;
        ::QueryPerformanceCounter((::LARGE_INTEGER*)&m_LastTime); 
        m_TimeScale	= 1.f / m_PerfFrequency;
    } 
    else 
    { 
        m_PerfHardware = FALSE;
        m_LastTime = ::timeGetTime(); 
        m_TimeScale	= 0.001f;
    }
}

/**
    Destructor for Timer
*/
Timer::~Timer()
{
}

/**
    Tick: Updates the current time of the Timer. Can also be forced into
    updating on an interval.

    @param float frame-rate lock value
*/
void Timer::Tick(const float flLockFPS)
{
    if (m_PerfHardware) 
    {
        ::QueryPerformanceCounter((::LARGE_INTEGER*)&m_CurrentTime);
    } 
    else 
    {
        m_CurrentTime = ::timeGetTime();
    }

    m_TimeElapsed = (m_CurrentTime - m_LastTime) * m_TimeScale;

    if (flLockFPS > 0.f)
    {
        while (m_TimeElapsed < (1.f / flLockFPS))
        {
            if (m_PerfHardware) 
            {
                ::QueryPerformanceCounter((::LARGE_INTEGER*)&m_CurrentTime);
            } 
            else 
            {
                m_CurrentTime = ::timeGetTime();
            }

            m_TimeElapsed = (m_CurrentTime - m_LastTime) * m_TimeScale;
        }
    }

    m_LastTime = m_CurrentTime;
}

/**
    GetElapsedTime: Gets the current frame time delta

    @return float delta time between frames
*/
float Timer::GetElapsedTime() const
{
    return m_TimeElapsed;
}

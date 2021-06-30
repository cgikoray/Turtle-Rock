#ifndef TIMER_H
#define TIMER_H

#pragma once

class Timer
{
public:
    Timer(void);
    virtual ~Timer();

    void Tick(const float flLockFPS = 0.f);
    float GetElapsedTime() const;

private:
    Timer(const Timer& rTimer);
    Timer& operator= (const Timer& rTimer);

    bool m_PerfHardware;
    float m_TimeScale;
    float m_TimeElapsed;
    __int64 m_CurrentTime;
    __int64 m_LastTime;
    __int64 m_PerfFrequency;
};

#endif // TIMER_H
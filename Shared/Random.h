#ifndef RANDOM_H
#define RANDOM_H

#pragma once

class Random
{
public:
    Random(void);

    int GetInt(const int nMin = -10000, const int nMax = 10000) const;
    float GetFloat(const float flMin = -10000.f, const float flMax = 10000.f) const;

private:
    Random(const Random& rRandom);
    Random& operator= (const Random& rRandom);
};

#endif // RANDOM_H
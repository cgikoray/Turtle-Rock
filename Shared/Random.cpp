#include "Random.h"
#include <cstdlib>
#include <ctime>

/**
    Constructor for Random

    Note: Uses time as a seed value.
*/
Random::Random(void)
{
    ::srand((unsigned int)::time(NULL));
}

/**
    GetInt: Gets a random integer value

    @param int minimum value of the expected range
    @param int max value of the expected range

    @return random integer value
*/
int Random::GetInt(const int nMin, const int nMax) const
{
    if (nMin == nMax)
    {
        return 0;
    }

    const int range = nMax - nMin;
    const int random = ::rand() % (range + 1);	
    const int value = nMin + random;

    return value;
}

/**
    GetFloat: Gets a random floating point value

    @param float minimum value of the expected range
    @param float max value of the expected range

    @return random floating point value
*/
float Random::GetFloat(const float flMin, const float flMax) const
{
    const float range = flMax - flMin;
    const float random = ((static_cast<float>(::rand())) / RAND_MAX) * range;
    const float value = flMin + random;

    return value;
}
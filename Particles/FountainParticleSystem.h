#ifndef FOUNTAIN_PARTICLE_SYSTEM_H
#define FOUNTAIN_PARTICLE_SYSTEM_H

#pragma once

#include "ParticleSystem.h"
#include "Random.h"

class FountainParticleSystem : public ParticleSystem
{
public:
    FountainParticleSystem(void);
    virtual ~FountainParticleSystem();

    void PreUpdate(const float flElapsedTime);
    virtual void Update(const float flElapsedTime);

private:
    FountainParticleSystem(const FountainParticleSystem& rParticleSystem);
    FountainParticleSystem& operator= (const FountainParticleSystem& rParticleSystem);

    Random random;
};

#endif // FOUNTAIN_PARTICLE_SYSTEM_H
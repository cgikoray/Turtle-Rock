#ifndef MODIFIER_H
#define MODIFIER_H

#pragma once

#include "Particle.h"

class IModifier
{
public:
    IModifier(void) { }
    virtual ~IModifier() { }

    virtual void Update(Particle& rOutParticle, const float flElapsedTime) = 0;

private:
    IModifier(const IModifier& rModifier);
    IModifier& operator=(const IModifier& rModifier);
};

#endif // MODIFIER_H
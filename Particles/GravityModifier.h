#ifndef GRAVITY_MODIFIER_H
#define GRAVITY_MODIFIER_H

#pragma once

#include "IModifier.h"

class GravityModifier : public IModifier
{
public:
    GravityModifier(void);
    explicit GravityModifier(const float flGravity);

    virtual void Update(Particle& rOutParticle, const float flElapsedTime);
    
    float GetGravity() const;
    void SetGravity(const float flGravity);

private:
    GravityModifier(const GravityModifier& rModifier);
    GravityModifier& operator=(const GravityModifier& rModifier);

    float m_Gravity;
};

#endif // GRAVITY_MODIFIER_H
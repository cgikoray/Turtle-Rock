#ifndef FORCE_MODIFIER_H
#define FORCE_MODIFIER_H

#pragma once

#include "IModifier.h"
#include "Vector3.h"

class ForceModifier : public IModifier
{
public:
    ForceModifier(void);
    explicit ForceModifier(const Vector3& rForce);

    virtual void Update(Particle& rOutParticle, const float flElapsedTime);

    Vector3& GetForce();
    const Vector3& GetForce() const;
    void SetForce(const Vector3& rForce);

private:
    ForceModifier(const ForceModifier& rModifier);
    ForceModifier& operator=(const ForceModifier& rModifier);

    Vector3 m_Force;
};

#endif // FORCE_MODIFIER_H
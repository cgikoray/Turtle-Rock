#ifndef PLANE_COLLISION_MODIFIER_H
#define PLANE_COLLISION_MODIFIER_H

#pragma once

#include "IModifier.h"
#include "Plane3.h"

class PlaneCollisionModifier : public IModifier
{
public:
    PlaneCollisionModifier(void);
    explicit PlaneCollisionModifier(const Plane3& rPlane);

    virtual void Update(Particle& rOutParticle, const float flElapsedTime);

    Plane3& GetPlane3();
    const Plane3& GetPlane3() const;
    void SetPlane3(const Plane3& rPlane);

private:
    PlaneCollisionModifier(const PlaneCollisionModifier& rModifier);
    PlaneCollisionModifier& operator=(const PlaneCollisionModifier& rModifier);

    Plane3 m_Plane;
};

#endif // PLANE_COLLISION_MODIFIER_H
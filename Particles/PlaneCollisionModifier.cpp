#include "PlaneCollisionModifier.h"


/**
    Default constructor for PlaneCollisionModifier
*/
PlaneCollisionModifier::PlaneCollisionModifier(void)
:   m_Plane()
{
}

/**
    Destructor for PlaneCollisionModifier
*/
PlaneCollisionModifier::PlaneCollisionModifier(const Plane3& rPlane)
:   m_Plane(rPlane)
{
}

/**
    Update: Runs a pretest against the provided Plane3 obstacle of our particle.
    The tests looks for a Ray/Plane intersection test, which will modify the resulting
    velocity and end-of-frame position with a potential reflection off of the plane
    surface.

    @param Particle reference of the particle we are affecting
    @param float elapsed time of the simulation
*/
void PlaneCollisionModifier::Update(Particle& rOutParticle, const float flElapsedTime)
{
    // Construct a Ray3 that represents the previous position of the particle with 
    // the next position given the time elapsed in the simulation.
    const Vector3 testNextPosition = rOutParticle.GetPosition() + (rOutParticle.GetVelocity() * flElapsedTime);

    Vector3 direction = testNextPosition;
    direction.Normalize();
    
    const Ray3 ray(rOutParticle.GetPrevPosition(), direction);

    // Intersection test against the ray and plane. Store the resulting distance of
    // that collision and the point of intersection.

    float collisionDistance;
    if(m_Plane.Intersect(ray, collisionDistance))
    {
        // If the intersection succeeds, calculate the reflection vector
        const Vector3 reflect = Vector3::Reflect(direction, m_Plane.GetNormal());

        // Find the distance left to move after intersection.
        const float reflectionLength = Vector3::Distance(rOutParticle.GetPrevPosition(), testNextPosition) - collisionDistance;

        // Set the new position and velocity
        const Vector3 trueNextPosition = rOutParticle.GetPrevPosition() + (direction * collisionDistance) + (reflect * reflectionLength);
        rOutParticle.SetPosition(trueNextPosition);
        rOutParticle.SetVelocity(reflect);
    }
}

/* Getter and Setters for PlaneCollisionModifier */

Plane3& PlaneCollisionModifier::GetPlane3()
{
    return m_Plane;
}

const Plane3& PlaneCollisionModifier::GetPlane3() const
{
    return m_Plane;
}

void PlaneCollisionModifier::SetPlane3(const Plane3& rPlane)
{
    m_Plane = rPlane;
}

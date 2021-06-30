#include "ForceModifier.h"

/**
    Default constructor for ForceModifier
*/
ForceModifier::ForceModifier(void)
:   m_Force()
{
}

/**
    Destructor for ForceModifier
*/
ForceModifier::ForceModifier(const Vector3& rForce)
:   m_Force(rForce)
{
}

/**
    Update: Affects the velocity of our particle by adding a force vector 

    @param Particle reference of the particle we are affecting
    @param float elapsed time of the simulation
*/
void ForceModifier::Update(Particle& rOutParticle, const float flElapsedTime)
{
    rOutParticle.SetVelocity(rOutParticle.GetVelocity() + m_Force);
}

/* Getter and Setters for ForceModifier */

Vector3& ForceModifier::GetForce()
{
    return m_Force;
}

const Vector3& ForceModifier::GetForce() const
{
    return m_Force;
}

void ForceModifier::SetForce(const Vector3& rForce)
{
    m_Force = rForce;
}
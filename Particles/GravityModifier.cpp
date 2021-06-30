#include "GravityModifier.h"

/**
    Default constructor for GravityModifier
*/
GravityModifier::GravityModifier(void)
:   m_Gravity(0.f)
{
}

/**
    Destructor for GravityModifier
*/
GravityModifier::GravityModifier(const float flGravity)
:   m_Gravity(flGravity)
{
}

/**
    Update: Affects the velocity of our particle by offsetting its Y
    component with a simulated gravity drop-off

    @param Particle reference of the particle we are affecting
    @param float elapsed time of the simulation
*/
void GravityModifier::Update(Particle& rOutParticle, const float flElapsedTime)
{
    Vector3& velocity = rOutParticle.GetVelocity();
    velocity.SetY(velocity.GetY() - m_Gravity);
}

/* Getter and Setters for GravityModifier */

float GravityModifier::GetGravity() const
{
    return m_Gravity;
}

void GravityModifier::SetGravity(const float flGravity)
{
    m_Gravity = flGravity;
}
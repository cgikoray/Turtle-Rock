#include "Particle.h"

/**
    Default Constructor for Particle
*/
Particle::Particle(void)
:   m_Position(),
    m_PrevPosition(),
    m_Velocity(),   
    m_Alive(false), 
    m_Age(0.f)
{
}

/**
    Copy constructor for Particle

    @param Particle reference to be copied from
*/
Particle::Particle(const Particle& rParticle)
:   m_Position(rParticle.m_Position),
    m_PrevPosition(rParticle.m_PrevPosition),
    m_Velocity(rParticle.m_Velocity),
    m_Age(rParticle.m_Age),
    m_Alive(rParticle.m_Alive)
{
}

/**
    Operator =: Sets the current Particle object equal to another

    @param Particle reference to be copied from
*/
Particle& Particle::operator=(const Particle& rParticle)
{
    m_Position = rParticle.m_Position;
    m_PrevPosition = rParticle.m_PrevPosition;
    m_Velocity = rParticle.m_Velocity;
    m_Age = rParticle.m_Age;
    m_Alive = rParticle.m_Alive;

    return *this;
}
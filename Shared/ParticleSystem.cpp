#include "ParticleSystem.h"
#include "Particle.h"
#include "IModifier.h"

/**
    Default Constructor for ParticleSystem
*/
ParticleSystem::ParticleSystem(void)
:   m_Active(false),
    m_MaxNumParticles(0),
    m_ReleaseTimer(0.f),
    m_ReleaseInterval(0.f),
    m_NumToRelease(0),
    m_LifeCycle(0.f),
    m_Position(),
    m_Velocity(),
    m_VelocityFactor(0.f)
{
}

/**
    Destructor for ParticleSystem
*/
ParticleSystem::~ParticleSystem()
{
    m_Particles.clear();
    m_Modifiers.clear();
}

/**
    Initialize: Constructs the particle objects for the particle system
*/
void ParticleSystem::Initialize()
{
    for (unsigned long i = 0; i < m_MaxNumParticles; ++i)
    {
        Particle* particle = new Particle();
        m_Particles.push_back(particle);
    }

    Reset();
}

/**
    Reset: Brings all particles in the particle system back to their default 
    state.
*/
void ParticleSystem::Reset()
{
    m_ReleaseTimer = 0.f;

    for(unsigned long i = 0; i < m_Particles.size(); i++)
    {
        if(NULL != m_Particles[i])
        {
            m_Particles[i]->SetAlive(false);
            m_Particles[i]->SetAge(0.f);
            m_Particles[i]->SetVelocity(m_Velocity);
            m_Particles[i]->SetPosition(m_Position);
        }
    }
}

/**
    UpdateModifiers: Iterates through the modifiers of a given particle and 
    invokes them.

    @param Particle pointer to the particle we are acting on
    @param float elapsed time for the simulation
*/
void ParticleSystem::UpdateModifiers(Particle* pParticle, const float flElapsedTime)
{
    for(unsigned int i = 0; i < m_Modifiers.size(); ++i)
    {
        if(NULL != m_Modifiers[i])
        {
            m_Modifiers[i]->Update(*pParticle, flElapsedTime);
        }
    }
}

/**
    AddModifier: Dynamically adds a modifier to the particle system

    @param IModifier pointer to the modifier we are adding
*/
void ParticleSystem::AddModifier(IModifier* pModifier)
{
    if(NULL != pModifier)
    {
        m_Modifiers.push_back(pModifier);
    }
}

/**
    RemoveModifiers: Removes all modifiers in the particle system
*/
void ParticleSystem::RemoveModifiers()
{
    m_Modifiers.clear();
}

/* Getter and Setters for ParticleSystem */

bool ParticleSystem::GetActive() const
{
    return m_Active;
}

void ParticleSystem::SetActive(const bool bActive)
{
    m_Active = bActive;
}

unsigned long ParticleSystem::GetMaxParticles() const
{
    return m_MaxNumParticles;
}

void ParticleSystem::SetMaxParticles(const unsigned long lMaxParticles)
{
    m_MaxNumParticles = lMaxParticles;
}

float ParticleSystem::GetReleaseInterval() const
{
    return m_ReleaseInterval;
}

void ParticleSystem::SetReleaseInterval(const float flReleaseInterval)
{
    m_ReleaseInterval = flReleaseInterval;
}

unsigned long ParticleSystem::GetNumToRelease() const
{
    return m_NumToRelease;
}

void ParticleSystem::SetNumToRelease(const unsigned long lNumToRelease)
{
    m_NumToRelease = lNumToRelease;
}

float ParticleSystem::GetLifeCycle() const
{
    return m_LifeCycle;
}

void ParticleSystem::SetLifeCycle(const float fLifeCycle)
{
    m_LifeCycle = fLifeCycle;
}

Vector3	ParticleSystem::GetPosition()
{
    return m_Position;
}

const Vector3& ParticleSystem::GetPosition() const
{
    return m_Position;
}

void ParticleSystem::SetPosition (const Vector3& rPosition)
{
    m_Position = rPosition;
}

Vector3	ParticleSystem::GetParticleVelocity()
{
    return m_Velocity;
}

const Vector3& ParticleSystem::GetParticleVelocity() const
{
    return m_Velocity;
}

void ParticleSystem::SetParticleVelocity (const Vector3& rVelocity)
{
    m_Velocity = rVelocity;
}

float ParticleSystem::GetVelocityFactor() const
{
    return m_VelocityFactor;
}

void ParticleSystem::SetVelocityFactor(const float flVelocityFactor)
{
    m_VelocityFactor = flVelocityFactor;
}
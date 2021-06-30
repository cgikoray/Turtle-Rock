#include "FountainParticleSystem.h"
#include "Particle.h"

/**
    Default constructor for FountainParticleSystem
*/
FountainParticleSystem::FountainParticleSystem(void)
{
}

/**
    Destructor for FountainParticleSystem
*/
FountainParticleSystem::~FountainParticleSystem()
{
}

/**
    PreUpdate: Keeps track of incremented time intervals and spawns
    new particles when appropriate.

    @param float elapsed time of the simulation
*/
void FountainParticleSystem::PreUpdate(const float flElapsedTime)
{
    if (m_ReleaseTimer < m_ReleaseInterval)
    {
        m_ReleaseTimer += flElapsedTime;
    }

    if (m_ReleaseTimer > m_ReleaseInterval )
    {
        // Reset the timer
        m_ReleaseTimer = 0.f;
        unsigned long active = 0;

        for (unsigned long i = 0; i < m_Particles.size(); ++i)
        {
            Particle* particle = m_Particles[i];

            if (!particle->GetAlive() && active < m_NumToRelease)
            {
                // Set particle properties
                particle->SetAlive(true);
                particle->SetAge(random.GetFloat(0.f, m_LifeCycle)); // Random lifetime
                particle->SetPrevPosition(m_Position);
                particle->SetPosition(m_Position);
                particle->SetVelocity(m_Velocity);

                ++active;
            }
        }
    }
}

/**
    Update: Updates the particle system simulation.

    @param float elapsed time of the simulation
*/
void FountainParticleSystem::Update(const float flElapsedTime)
{
    if(!m_Active)
    {
        return;
    }

    PreUpdate(flElapsedTime);

    for (unsigned long i = 0; i < m_Particles.size(); ++i)
    {
        Particle* particle = m_Particles[i];

        if (particle->GetAge() > m_LifeCycle)
        {
            // Kill the particle if it has reached it's lifetime
            particle->SetAlive(false);
        }

        if (particle->GetAlive())
        {
            particle->SetAge(particle->GetAge() + flElapsedTime);
            particle->SetPrevPosition(particle->GetPosition());

            // Iterates through modifiers of THIS particle
            UpdateModifiers(particle, flElapsedTime);

            particle->SetVelocity(particle->GetVelocity() * flElapsedTime);
            particle->SetPosition(particle->GetPosition() + (particle->GetVelocity() * flElapsedTime));
        }
    }
}
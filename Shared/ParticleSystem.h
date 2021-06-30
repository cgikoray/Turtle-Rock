#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#pragma once

#include "Vector3.h"
#include <vector>

class Particle;
class IModifier;

class ParticleSystem
{
public:
    ParticleSystem(void);
    virtual ~ParticleSystem();

    virtual void Initialize();
    virtual void Reset();
    virtual void Update(const float flElapsedTime) = 0;

    virtual void UpdateModifiers(Particle* pParticle, const float flElapsedTime);
    virtual void AddModifier(IModifier* pModifier);
    virtual void RemoveModifiers();

    bool GetActive() const;
    void SetActive(const bool bActive);

    unsigned long GetMaxParticles() const;
    void SetMaxParticles(const unsigned long lMaxParticles);

    float GetReleaseInterval() const;
    void SetReleaseInterval(const float flReleaseInterval);

    unsigned long GetNumToRelease() const;
    void SetNumToRelease(const unsigned long lNumToRelease);

    float GetLifeCycle() const;
    void SetLifeCycle(const float fLifeCycle);

    Vector3	GetPosition();
    const Vector3& GetPosition() const;
    void SetPosition (const Vector3& rPosition);
    
    Vector3	GetParticleVelocity();
    const Vector3& GetParticleVelocity() const;
    void SetParticleVelocity (const Vector3& rVelocity);

    float GetVelocityFactor() const;
    void SetVelocityFactor(const float flVelocityFactor);

protected:
    bool m_Active;
    unsigned long m_MaxNumParticles;

    float m_ReleaseTimer;
    float m_ReleaseInterval;
    unsigned long m_NumToRelease;
    float m_LifeCycle;

    Vector3 m_Position;
    Vector3	m_Velocity;
    float m_VelocityFactor;

    std::vector<Particle*> m_Particles;
    std::vector<IModifier*> m_Modifiers;

private:
    ParticleSystem(const ParticleSystem& rParticleSystem);
    ParticleSystem& operator= (const ParticleSystem& rParticleSystem);
};

#endif // PARTICLE_SYSTEM_H
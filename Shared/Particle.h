#ifndef PARTICLE_H
#define PARTICLE_H

#pragma once

#include "Vector3.h"

class Particle
{
public:
    Particle(void);
    Particle(const Particle& rParticle);
    Particle& operator=(const Particle& rParticle);
    
    inline Vector3& GetPosition();
    inline const Vector3& GetPosition() const;
    inline void SetPosition(const Vector3& rPosition);

    inline Vector3& GetPrevPosition();
    inline const Vector3& GetPrevPosition() const;
    inline void SetPrevPosition(const Vector3& rPrevPosition);

    inline Vector3& GetVelocity();
    inline const Vector3& GetVelocity() const;
    inline void SetVelocity(const Vector3& rVelocity);

    inline float GetAge() const;
    inline void SetAge(const float flAge);

    inline bool GetAlive() const;
    inline void SetAlive(const bool bAlive);

private:
    Vector3	m_Position;
    Vector3	m_PrevPosition;
    Vector3	m_Velocity;
    float m_Age;
    bool m_Alive;
};

#include "Particle.inl"
#endif // PARTICLE_H
/* Getter and Setters for Particle */

inline Vector3& Particle::GetPosition()
{
    return m_Position;
}

inline const Vector3& Particle::GetPosition() const
{
    return m_Position;
}

inline void Particle::SetPosition(const Vector3& rPosition)
{
    m_Position = rPosition;
}

inline Vector3& Particle::GetPrevPosition()
{
    return m_PrevPosition;
}

inline const Vector3& Particle::GetPrevPosition() const
{
    return m_PrevPosition;
}

inline void Particle::SetPrevPosition(const Vector3& rPrevPosition)
{
    m_PrevPosition = rPrevPosition;
}

inline Vector3& Particle::GetVelocity()
{
    return m_Velocity;
}

inline const Vector3& Particle::GetVelocity() const
{
    return m_Velocity;
}

inline void Particle::SetVelocity(const Vector3& rVelocity)
{
    m_Velocity = rVelocity;
}

inline float Particle::GetAge() const
{
    return m_Age;
}

inline void Particle::SetAge(const float flAge)
{
    m_Age = flAge;
}

inline bool Particle::GetAlive() const
{
    return m_Alive;
}

inline void Particle::SetAlive(const bool bAlive)
{
    m_Alive = bAlive;
}
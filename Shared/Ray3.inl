/* Getter and Setters for Ray3 */

inline Vector3 Ray3::GetOrigin()
{
    return m_Origin;
}

inline const Vector3& Ray3::GetOrigin() const
{
    return m_Origin;
}

inline void Ray3::SetOrigin(const Vector3& rOrigin)
{
    m_Origin = rOrigin;
}

inline Vector3 Ray3::GetDirection()
{
    return m_Direction;
}

inline const Vector3& Ray3::GetDirection() const
{
    return m_Direction;
}

inline void Ray3::SetDirection(const Vector3& rDirection)
{
    m_Direction = rDirection;
}
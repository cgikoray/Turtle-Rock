/* Getter and Setters for Vector3 */

inline Vector3 Plane3::GetNormal()
{
    return m_Normal;
}

inline const Vector3& Plane3::GetNormal() const
{
    return m_Normal;
}

inline void Plane3::SetNormal(const Vector3& rNormal)
{
    m_Normal = rNormal;
}

inline float Plane3::GetConstant() const
{
    return m_Constant;
}

inline void Plane3::SetConstant(const float flConstant)
{
    m_Constant = flConstant;
}

/**
    DistanceTo: Calculates the distance of a vector to the plane

    @param Vector3 reference to a vector outside the plane

    @return float distance from the vector to the plane
*/
inline float Plane3::DistanceTo(const Vector3& rPoint) const
{
    return (m_Normal.DotProduct(rPoint) - m_Constant);
}

/**
    Intersect: Executes an intersection test for a Ray3 against the plane

    @param Ray3 reference to a Ray3 being test against the plane
    @param float reference to the distance of the origin of the Ray3 to the
    resulting intersection point

    @return bool if an intersection occurred.
*/
inline bool Plane3::Intersect(const Ray3& rRay, float& rOutDistance) const
{
    Vector3 pointOnPlane = m_Normal * m_Constant;
    float dotNormalDirection = m_Normal.DotProduct(rRay.GetDirection());

    if(dotNormalDirection == 0.f)
    {
        return false;
    }

    rOutDistance = m_Normal.DotProduct(pointOnPlane - rRay.GetOrigin()) / dotNormalDirection;
    return true;
}
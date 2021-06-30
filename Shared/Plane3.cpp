#include "Plane3.h"

/**
    Default constructor for Plane3
*/
Plane3::Plane3(void)
:   m_Normal(),
    m_Constant(0.f)
{
}

/**
    Constructor for Plane3

    @param Vector3 reference to the plane normal
    @param float distance along its normal from the origin
*/
Plane3::Plane3(const Vector3& rNormal, const float flConstant)
:   m_Normal(rNormal),
    m_Constant(flConstant)
{
}

/**
    Constructor for Plane3

    @param Vector3 reference to the plane normal
    @param Vector3 reference to a point inside the plane
*/
Plane3::Plane3(const Vector3& rNormal, const Vector3& rPoint)
:   m_Normal(rNormal)
{
    m_Constant = m_Normal.DotProduct(rPoint);
}

/**
    Constructor for Plane3

    @param Vector3 reference point inside the plane
    @param Vector3 reference point inside the plane
    @param Vector3 reference point inside the plane
*/
Plane3::Plane3(const Vector3& rPoint1, const Vector3& rPoint2, const Vector3& rPoint3)
{
    const Vector3& edge1 = rPoint2 - rPoint1;
    const Vector3& edge2 = rPoint3 - rPoint1;
    
    m_Normal = edge1.CrossProduct(edge2);
    m_Normal.Normalize();
    m_Constant = m_Normal.DotProduct(rPoint1);
}

/**
    Copy constructor for Plane3

    @param Plane3 reference to be copied from
*/
Plane3::Plane3(const Plane3& rPlane)
:   m_Normal(rPlane.m_Normal),
    m_Constant(rPlane.m_Constant)
{
}

/**
    Operator =: for Plane3

    @param Plane3 reference to be copied from
*/
Plane3& Plane3::operator=(const Plane3& rPlane)
{
    m_Normal = rPlane.m_Normal;
    m_Constant = rPlane.m_Constant;

    return *this;
}
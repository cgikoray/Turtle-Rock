#include "Ray3.h"

/**
    Default constructor for Ray3
*/
Ray3::Ray3(void) 
:   m_Origin(), 
    m_Direction()
{
}

/**
    Constructor for Ray3

    @param Vector3 reference for the origin point
    @param Vector3 reference for the direction vector (should be normalized)
*/
Ray3::Ray3(const Vector3& rOrigin, const Vector3& rDirection)
:   m_Origin(rOrigin), 
    m_Direction(rDirection)
{
}

/**
    Copy constructor for Ray3

    @param Ray3 reference to be copied from
*/
Ray3::Ray3(const Ray3& rRay)
:   m_Origin(rRay.m_Origin),
    m_Direction(rRay.m_Direction)
{
}

/**
    Operator =: for Ray3

    @param Ray3 reference to be copied from
*/
Ray3& Ray3::operator=(const Ray3& rRay)
{
    m_Origin = rRay.m_Direction;
    m_Direction = rRay.m_Direction;

    return *this;
}
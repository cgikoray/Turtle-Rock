#ifndef PLANE3_H
#define PLANE3_H

#pragma once

#include "Ray3.h"

class Plane3
{
public:
    Plane3(void);
    Plane3(const Vector3& rNormal, const float flConstant);
    Plane3(const Vector3& rNormal, const Vector3& rPoint);
    Plane3(const Vector3& rPoint1, const Vector3& rPoint2, const Vector3& rPoint3);
    Plane3(const Plane3& rPlane);
    Plane3& operator=(const Plane3& rPlane);

    inline Vector3 GetNormal();
    inline const Vector3& GetNormal() const;
    inline void SetNormal(const Vector3& rNormal);

    inline float GetConstant() const;
    inline void SetConstant(const float flConstant);

    inline float DistanceTo(const Vector3& rPoint) const;
    inline bool Intersect(const Ray3& rRay, float& rOutDistance) const;

private:
    Vector3 m_Normal;
    float m_Constant;
};

#include "Plane3.inl"
#endif // PLANE3_H
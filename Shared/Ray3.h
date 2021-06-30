#ifndef RAY3_H
#define RAY3_H

#pragma once

#include "Vector3.h"

class Ray3
{
public:
    Ray3(void);
    Ray3(const Vector3& rOrigin, const Vector3& rDirection);
    Ray3(const Ray3& rRay);
    Ray3& operator=(const Ray3& rRay);

    inline Vector3 GetOrigin();
    inline const Vector3& GetOrigin() const;
    inline void SetOrigin(const Vector3& rOrigin);

    inline Vector3 GetDirection();
    inline const Vector3& GetDirection() const;
    inline void SetDirection(const Vector3& rDirection);

private:
    Vector3 m_Origin;
    Vector3 m_Direction;
};

#include "Ray3.inl"
#endif // RAY3_H
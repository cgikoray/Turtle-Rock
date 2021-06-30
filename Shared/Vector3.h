#ifndef VECTOR3_H
#define VECTOR3_H

#pragma once

class Vector3
{
public:
  Vector3(void);
  explicit Vector3(float flVal);
  Vector3(const float flX, const float flY, const float flZ);
  Vector3(const Vector3& rVector);

  inline float GetX() const;
  inline float GetY() const;
  inline float GetZ() const;

  inline void SetX(const float flX);
  inline void SetY(const float flY);
  inline void SetZ(const float flZ);

  inline float Length() const;
  inline float DotProduct(const Vector3& rVector) const;
  inline float Normalize();
  inline Vector3 CrossProduct(const Vector3& rVector) const;

  static inline Vector3 Reflect(const Vector3& rIncident, const Vector3& rNormal);
  static inline float SquaredDistance(const Vector3& rVector1, const Vector3& rVector2);
  static inline float Distance(const Vector3& rVector1, const Vector3& rVector2);

  inline bool operator==(const Vector3& rVector) const;
  inline bool operator!=(const Vector3& rVector) const;
  inline float operator[](size_t nIndex) const;

  inline Vector3& operator=(const Vector3& rVector);
  inline Vector3 operator+(const Vector3& rVector) const;
  inline Vector3 operator-(const Vector3& rVector) const;
  inline Vector3 operator*(const float flScalar) const;
  inline Vector3 operator/(const float flScalar) const;
  inline Vector3 operator-() const;

  inline Vector3& operator+=(const Vector3& rVector);
  inline Vector3& operator-=(const Vector3& rVector);
  inline Vector3& operator*=(const float flScalar);
  inline Vector3& operator/=(const float flScalar);

  static const unsigned int m_Dimensions = 3;

private:
  union
  {
    struct
    {
      float m_X;
      float m_Y;
      float m_Z;
    };

    float m_Values[3];
  };
};

#include "Vector3.inl"
#endif // VECTOR3_H
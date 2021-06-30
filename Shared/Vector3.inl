#include <math.h>
#include <float.h>

/* Getter and Setters for Vector3 */

inline float Vector3::GetX() const
{
  return m_X;
}

inline float Vector3::GetY() const
{
  return m_Y;
}

inline float Vector3::GetZ() const
{
  return m_Z;
}

void Vector3::SetX(const float flX)
{
  m_X = flX;
}

void Vector3::SetY(const float flY)
{
  m_Y = flY;
}

void Vector3::SetZ(const float flZ)
{
  m_Z = flZ;
}

/**
  Length: Calculates the length of the Vector3

  @return float length of the Vector3
  */
inline float Vector3::Length() const
{
  return ::sqrtf
    (
    m_X * m_X + 
    m_Y * m_Y + 
    m_Z * m_Z
    );
}

/**
  DotProduct: Calculates dot product of the Vector3 against
  another Vector3

  @param Vector3 reference to be calculated against

  @return float scalar value describing the relationship of the angle
  between the two Vector3's
  */
inline float Vector3::DotProduct(const Vector3& rVector) const
{
  return 
    (
    m_X * rVector.m_X + 
    m_Y * rVector.m_Y + 
    m_Z * rVector.m_Z
    );
}

/**
  Normalize: normalized the component of the Vector3

  @return float length of the resulting Vector3
  */
inline float Vector3::Normalize()
{
  float length = Length();

  if (length > FLT_EPSILON)
  {
    const float inverseLength = 1.f / length;
    m_X *= inverseLength;
    m_Y *= inverseLength;
    m_Z *= inverseLength;
  }
  else
  {
    length = 0.f;
    m_X = 0.f;
    m_Y = 0.f;
    m_Z = 0.f;
  }

  return length;
}

/**
  CrossProduct: Calculates cross product of the Vector3 against
  another Vector3

  @param Vector3 reference to be calculated against

  @return Vector3 reference which is orthogonal to the two Vector3's
  being calculated against one another.
  */
inline Vector3 Vector3::CrossProduct(const Vector3& rVector) const
{
  return Vector3
    (
    m_Y * rVector.m_Z - m_Z * rVector.m_Y,
    m_Z * rVector.m_X - m_X * rVector.m_Z,
    m_X * rVector.m_Y - m_Y * rVector.m_X
    );
}

/**
  Reflect: Calculate the resulting reflection of a Vector3 given another Vector3

  @param Vector3 reference to the incident Vector3
  @param Vector3 reference to the normal, or Vector3 being reflected against

  @return Vector3 result from the reflection
  */
inline Vector3 Vector3::Reflect(const Vector3& rIncident, const Vector3& rNormal)
{
  return Vector3((rNormal * rIncident.DotProduct(rNormal) * 2.f) - rIncident);
}

/**
  Distance: Finds the squared distance between two Vector3's

  @param Vector3 reference to used in the distance calculation
  @param Vector3 reference to used in the distance calculation

  @return float squared distance
  */
inline float Vector3::SquaredDistance(const Vector3& rVector1, const Vector3& rVector2)
{
  const float dx = rVector1.m_X - rVector2.m_X;
  const float dy = rVector1.m_Y - rVector2.m_Y;
  const float dz = rVector1.m_Z - rVector2.m_Z;

  return dx * dx + dy * dy + dz * dz;
}

/**
  Distance: Finds the distance between two Vector3's

  @param Vector3 reference to used in the distance calculation
  @param Vector3 reference to used in the distance calculation

  @return float distance
  */
inline float Vector3::Distance(const Vector3& rVector1, const Vector3& rVector2)
{
  return ::sqrtf(SquaredDistance(rVector1, rVector2));
}

/* Operators for Vector3 */

inline bool Vector3::operator==(const Vector3& rVector) const
{
  return
    (
    m_X == rVector.m_X &&
    m_Y == rVector.m_Y &&
    m_Z == rVector.m_Z
    );
}

inline bool Vector3::operator!=(const Vector3& rVector) const
{
  return
    (
    m_X != rVector.m_X ||
    m_Y != rVector.m_Y ||
    m_Z != rVector.m_Z
    );
}

inline float Vector3::operator[](size_t nIndex) const
{
  return m_Values[nIndex];
}

inline Vector3& Vector3::operator=(const Vector3& rVector)
{
  m_X = rVector.m_X;
  m_Y = rVector.m_Y;
  m_Z = rVector.m_Z;

  return *this;
}

inline Vector3 Vector3::operator+(const Vector3& rVector) const
{
  return Vector3
    (
    m_X + rVector.m_X,
    m_Y + rVector.m_Y,
    m_Z + rVector.m_Z
    );
}

inline Vector3 Vector3::operator-(const Vector3& rVector) const
{
  return Vector3
    (
    m_X - rVector.m_X,
    m_Y - rVector.m_Y,
    m_Z - rVector.m_Z
    );
}

inline Vector3 Vector3::operator*(float flScalar) const
{
  return Vector3
    (
    flScalar * m_X,
    flScalar * m_Y,
    flScalar * m_Z
    );
}

inline Vector3 Vector3::operator/(float flScalar) const
{
  Vector3 result;

  if (flScalar != 0.f)
  {
    const float inverseScalar = 1.f / flScalar;
    result.m_X = inverseScalar * m_X;
    result.m_Y = inverseScalar * m_Y;
    result.m_Z = inverseScalar * m_Z;
  }
  else
  {
    result.m_X = FLT_MAX;
    result.m_Y = FLT_MAX;
    result.m_Z = FLT_MAX;
  }

  return result;
}

inline Vector3 Vector3::operator-() const
{
  return Vector3
    (
    -m_X,
    -m_Y,
    -m_Z
    );
}

inline Vector3& Vector3::operator+=(const Vector3& rVector)
{
  m_X += rVector.m_X;
  m_Y += rVector.m_Y;
  m_Z += rVector.m_Z;

  return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& rVector)
{
  m_X -= rVector.m_X;
  m_Y -= rVector.m_Y;
  m_Z -= rVector.m_Z;

  return *this;
}

inline Vector3& Vector3::operator*=(float flScalar)
{
  m_X *= flScalar;
  m_Y *= flScalar;
  m_Z *= flScalar;

  return *this;
}

inline Vector3& Vector3::operator/=(float flScalar)
{
  if (flScalar != 0.f)
  {
    float inverseScalar = 1.f / flScalar;
    m_X *= inverseScalar;
    m_Y *= inverseScalar;
    m_Z *= inverseScalar;
  }
  else
  {
    m_X *= FLT_MAX;
    m_Y *= FLT_MAX;
    m_Z *= FLT_MAX;
  }

  return *this;
}
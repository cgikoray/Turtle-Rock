#include "Vector3.h"

/**
  Default constructor for Vector3
  */
Vector3::Vector3(void)
: m_X(0.f),
  m_Y(0.f),
  m_Z(0.f)
{
}

/**
  Single value constructor for Vector3
  */
Vector3::Vector3(float flVal)
: m_X(flVal),
  m_Y(flVal),
  m_Z(flVal)
{
}

/**
  Constructor for Vector3

  @param float x value
  @param float y value
  @param float z value
  */
Vector3::Vector3(const float flX, const float flY, const float flZ)
: m_X(flX),
  m_Y(flY),
  m_Z(flZ)
{
}

/**
  Copy constructor for Vector3

  @param Vector3 reference to be copied
  */
Vector3::Vector3(const Vector3& rVector)
: m_X(rVector.m_X),
  m_Y(rVector.m_Y),
  m_Z(rVector.m_Z)
{
}
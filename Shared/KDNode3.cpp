#include "KDNode3.h"

/**
    Default constructor for KDNode3
*/
KDNode3::KDNode3(void)
:   m_Vector(), 
    m_LeftNode(0), 
    m_RightNode(0)
{
}

/**
    Constructor for KDNode3

    @param Vector3 reference to be set
*/
KDNode3::KDNode3(const Vector3& rVector)
:   m_Vector(rVector), 
    m_LeftNode(0), 
    m_RightNode(0)
{
}

/**
    Constructor for KDNode3

    @param Vector3 reference to be set
    @param KDNode3 pointer for the left linked node
    @param KDNode3 pointer for the right linked node
*/
KDNode3::KDNode3(const Vector3& rVector, KDNode3* const pLeftNode, KDNode3* const pRightNode)
:   m_Vector(rVector), 
    m_LeftNode(pLeftNode), 
    m_RightNode(pRightNode)
{
}

/**
    Copy constructor for KDNode3

    @param Vector3 reference to be copied from
*/
KDNode3::KDNode3(const KDNode3& rNode)
:   m_Vector(rNode.m_Vector), 
    m_LeftNode(rNode.m_LeftNode), 
    m_RightNode(rNode.m_RightNode)
{
}

/**
    Operator =: for KDNode3

    @param KDNode3 reference to be copied from
*/
KDNode3& KDNode3::operator=(const KDNode3& rNode)
{
    m_Vector = rNode.m_Vector;
    m_LeftNode = rNode.m_LeftNode;
    m_RightNode = rNode.m_RightNode;

    return *this;
}

/* Getter and Setters for KDNode3 */

Vector3 KDNode3::GetVector()
{
    return m_Vector;
}

const Vector3& KDNode3::GetVector() const
{
    return m_Vector;
}

void KDNode3::SetVector(const Vector3& rVector)
{
    m_Vector = rVector;
}

KDNode3* KDNode3::GetLeftNode()
{
    return m_LeftNode;
}

KDNode3* const KDNode3::GetLeftNode() const
{
    return m_LeftNode;
}

void KDNode3::SetLeftNode(KDNode3* pNode)
{
    m_LeftNode = pNode;
}

KDNode3* KDNode3::GetRightNode()
{
    return m_RightNode;
}

KDNode3* const KDNode3::GetRightNode() const
{
    return m_RightNode;
}

void KDNode3::SetRightNode(KDNode3* const pNode)
{
    m_RightNode = pNode;
}
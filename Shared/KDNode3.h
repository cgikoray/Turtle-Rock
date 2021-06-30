#ifndef KD_NODE3_H
#define KD_NODE3_H

#pragma once

#include "Vector3.h"

class KDNode3
{
public:
    KDNode3(void);
    explicit KDNode3(const Vector3& rVector);
    KDNode3(const Vector3& rVector, KDNode3* const pLeftNode, KDNode3* const pRightNode);

    KDNode3(const KDNode3& rNode);
    KDNode3& operator=(const KDNode3& rNode);

    Vector3 GetVector();
    const Vector3& GetVector() const;
    void SetVector(const Vector3& rVector);

    KDNode3* GetLeftNode();
    KDNode3* const GetLeftNode() const;
    void SetLeftNode(KDNode3* const pNode);

    KDNode3* GetRightNode();
    KDNode3* const GetRightNode() const;
    void SetRightNode(KDNode3* const pNode);

private:
    Vector3 m_Vector;

    KDNode3* m_LeftNode;
    KDNode3* m_RightNode;
};

#endif // KD_NODE3_H
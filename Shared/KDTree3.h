#ifndef KD_TREE3_H
#define KD_TREE3_H

#pragma once

#include "Vector3.h"
#include <vector>

class KDNode3;

struct KDTreeQueryResult
{
    Vector3 m_ClosestVector;
    float m_Distance;
    unsigned int m_NodesVisited;
};

class KDTree3
{
public:
    explicit KDTree3(const std::vector<Vector3>& rVectors);
    virtual ~KDTree3();

    KDTreeQueryResult FindNearestVector(const Vector3& pTestVector);

private:
    KDTree3();
    KDTree3(const KDTree3& rTree);
    KDTree3& operator=(const KDTree3& rTree);

    KDNode3* BuildKDTree(KDNode3* pRoot, const unsigned int nLength, const unsigned int nIndex);
    void FindNearestNode(KDNode3* pRoot, const KDNode3& pTestNode, unsigned int nIndex, KDNode3& pClosestNode, float& pClosestDistance);
    float Distance(const KDNode3& pNode1, const KDNode3& pNode2) const;
    void SwapVector(KDNode3& pNode1, KDNode3& pNode2) const;
    KDNode3* FindMedian(KDNode3* pStart, KDNode3* pEnd, const unsigned int nIndex) const;

    KDTreeQueryResult m_Result;
    KDNode3* m_Nodes;
    KDNode3* m_Root;
};

#endif // KD_TREE3_H
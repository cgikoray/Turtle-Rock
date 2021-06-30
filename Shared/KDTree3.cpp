#include "KDTree3.h"
#include "KDNode3.h"

/**
    Constructor for KDTree3

    @param vector of Vector3 references, representing the dataset
    of Vector3's to be constructed into a kD tree
*/
KDTree3::KDTree3(const std::vector<Vector3>& rVectors)
:   m_Nodes(new KDNode3[rVectors.size()]), 
    m_Root(NULL)
{
    m_Result.m_NodesVisited = 0;
    m_Result.m_Distance = 0;

    if(!rVectors.empty())
    {
        const unsigned int vectorSize = rVectors.size();

        for(unsigned int i = 0; i < vectorSize; ++i)
        {
            m_Nodes[i].SetVector(rVectors[i]);
        }

        m_Root = BuildKDTree(m_Nodes, vectorSize, 0);
    }
}

/**
    Destructor for KDTree3
*/
KDTree3::~KDTree3()
{
    delete[] m_Nodes;
}

/**
    FindNearestVector: Finds the nearest Vector3 in the KDTree3 to the provided 
    Vector3. A KDTreeQueryResult is constructed to provide information about the
    search traversal.

    @param Vector3 reference to the test Vector3

    @return KDTreeQueryResult containing the closest Vector3 and auxiliary information
    about the search traversal.
*/
KDTreeQueryResult KDTree3::FindNearestVector(const Vector3& pTestVector)
{
    m_Result.m_NodesVisited = 0;
    m_Result.m_Distance = FLT_MAX;

    if(NULL != m_Root)
    {
        const KDNode3 testNode(pTestVector);
        KDNode3 closestNode;

        FindNearestNode(m_Root, testNode, 0, closestNode, m_Result.m_Distance);

        m_Result.m_ClosestVector = closestNode.GetVector();
        m_Result.m_Distance = ::sqrtf(m_Result.m_Distance);
    }

    return m_Result;
}

/**
    BuildKDTree: Recursively constructs the KDTree3 of our dataset

    @param KDNode3 pointer to the starting root of our tree generation
    @param int length of KDNode3's to iterate over during tree construction
    @param int index representing the axis (given our dimensions) where we generate a node generation

    @return KDNode3 pointer representing the median of our tree generation
*/
KDNode3* KDTree3::BuildKDTree(KDNode3* pRoot, const unsigned int nLength, unsigned int nIndex)
{
    KDNode3* median = NULL;

    if(nLength == 0)
    {
        return NULL;
    }

    if((median = FindMedian(pRoot, pRoot + nLength, nIndex)))
    {
        nIndex = (nIndex + 1) % Vector3::m_Dimensions;

        // Generate a new tree from our root, to the median
        median->SetLeftNode(BuildKDTree(pRoot, median - pRoot, nIndex));

        // Generate a new tree from our median, to the end of the list of the dataset
        median->SetRightNode(BuildKDTree(median + 1, pRoot + nLength - (median + 1), nIndex));
    }

    return median;
}

/**
    FindNearestNode: Recursively finds the nearest node in the KDTree3 given our test node

    @param KDNode3 pointer to the starting root of our tree
    @param KDNode3 reference to the node being tested against
    @param int index representing the axis (given our dimensions) for traversal through the children nodes
    @param KDNode3 reference to the closest node near our test node
    @param float reference to the distance between the test node and the resulting closest node
*/
void KDTree3::FindNearestNode(KDNode3* pRoot, const KDNode3& pTestNode, unsigned int nIndex, KDNode3& pClosestNode, float& pClosestDistance)
{
    if(NULL == pRoot)
    {
        return;
    }

    // Store the squared distance
    float distanceSquared = Distance(*pRoot, pTestNode);
    float difference = pRoot->GetVector()[nIndex] - pTestNode.GetVector()[nIndex];
    float differenceSquared = difference * difference;

    // Increment the number of nodes visited
    ++m_Result.m_NodesVisited;

    if(distanceSquared <= pClosestDistance)
    {
        pClosestDistance = distanceSquared;
        pClosestNode = *pRoot;
    }

    // We can't reach a distance any closer than 0
    if(pClosestDistance == 0.f)
    {
        return;
    }

    // Reset the axis so that we don't start checking dimensions that do not exist
    if(++nIndex >= Vector3::m_Dimensions)
    {
        nIndex = 0;
    }

    FindNearestNode(difference > 0.f ? pRoot->GetLeftNode() : pRoot->GetRightNode(), pTestNode, nIndex, pClosestNode, pClosestDistance);

    if(differenceSquared >= pClosestDistance)
    {
        return;
    }

    FindNearestNode(difference > 0.f ? pRoot->GetRightNode() : pRoot->GetLeftNode(), pTestNode, nIndex, pClosestNode, pClosestDistance);
}

/**
    Distance: Finds the squared distance between two KDNode3's

    @param KDNode3 reference to used in the distance calculation
    @param KDNode3 reference to used in the distance calculation

    @return float squared distance
*/
float KDTree3::Distance(const KDNode3& pNode1, const KDNode3& pNode2) const
{
    return Vector3::SquaredDistance(pNode1.GetVector(), pNode2.GetVector());
}

/**
    SwapVector: Swaps the Vector3 values of two KDNode3's

    @param KDNode3 reference to be swapped
    @param KDNode3 reference to be swapped
*/
void KDTree3::SwapVector(KDNode3& pNode1, KDNode3& pNode2) const
{
    Vector3 stored = pNode1.GetVector();
    pNode1.SetVector(pNode2.GetVector());
    pNode2.SetVector(stored);
}

/**
    FindMedian: Finds the median node given a starting KDNode3 and end KDNode3

    @param KDNode3 pointer to begin on during the traversal
    @param KDNode3 pointer to end on during the traversal
    @param int index representing the current axis (given our dimensions) of traversal

    @return KDNode3 pointer median KDNode3
*/
KDNode3* KDTree3::FindMedian(KDNode3* pStart, KDNode3* pEnd, unsigned int nIndex) const
{
    if(pEnd <= pStart)
    {
        return NULL;
    }

    if(pEnd == pStart + 1)
    {
        return pStart;
    }

    KDNode3* current = NULL;
    KDNode3* storage = NULL;
    
    // Store the middle KDNode3
    KDNode3* middle = pStart + (pEnd - pStart) / 2;

    float pivot = 0.f;

    while(true)
    {
        pivot = middle->GetVector()[nIndex];

        SwapVector(*middle, *(pEnd - 1));
        for(storage = current = pStart; current < pEnd; ++current)
        {
            if(current->GetVector()[nIndex] < pivot)
            {
                if(current != storage)
                {
                    SwapVector(*current, *storage);
                }
                ++storage;
            }
        }
        SwapVector(*storage, *(pEnd - 1));

        if(storage->GetVector()[nIndex] == middle->GetVector()[nIndex])
        {
            return middle;
        }

        if(storage > middle)
        {
            pEnd = storage;
        }
        else
        {
            pStart = storage;
        }
    }
}
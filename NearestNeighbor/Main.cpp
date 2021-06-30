#include "KDTree3.h"
#include "KDNode3.h"
#include "Random.h"
#include <iostream>

/*_______________________________________________________________________

  This program solves the Nearest Neighbor Search problem for 3D vectors
  in space by utilizing a three dimensional KD Tree implementation to do
  spatial partitioning of a volume defined by the inserted vectors.
_______________________________________________________________________*/

namespace
{
    const unsigned int count = 1000000;
}

int main()
{
    std::cout << "Nearest Neighbor Search Test\n\n";
    std::cout << "Inserting " << count << " randomly placed Vectors in space\n\n";

    const Random random;
    std::vector<Vector3> vectors;

    for(unsigned int i = 0; i < count; ++i)
    {
        vectors.push_back(Vector3(random.GetFloat(), random.GetFloat(), random.GetFloat()));
    }
   
    KDTree3 kdtree(vectors);

    std::cout << "KD Tree constructed, click Enter to find the nearest neighbor: ";
    std::cin.get();

    while(true)
    {
        const Vector3 test(random.GetFloat(), random.GetFloat(), random.GetFloat());
        const KDTreeQueryResult& result = kdtree.FindNearestVector(test);

        std::cout << "\nSearching (" 
            << test.GetX() << ", "
            << test.GetY() << ", "
            << test.GetZ() << ")\n";

        std::cout << "Found ("
            << result.m_ClosestVector.GetX() << ", "
            << result.m_ClosestVector.GetY() << ", "
            << result.m_ClosestVector.GetZ() << ")\n";

        std::cout << "Distance: " << result.m_Distance << '\n'
            << "Nodes Visited: " << result.m_NodesVisited << '\n';

        std::cout << "\nPress Enter: ";
        std::cin.get();
    }

    vectors.clear();
    return 0;
}
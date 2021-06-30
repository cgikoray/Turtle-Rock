#include "Vector3.h"
#include <iostream>

/*_______________________________________________________________________

  This program calculates the reflection of a given incident vector from
  a normal vector (from a plane for example) and prints it.
_______________________________________________________________________*/

namespace {
void PrintVector3(const Vector3& rVector) {
  std::cout << "(" << rVector.GetX() << ", "
            << rVector.GetY() << ", "
            << rVector.GetZ() << ")\n";
}
}

int main() {
  Vector3 incident, normal, result;
  std::cout << "Vector Reflection Tests"
            << "\n\nResults are printed in order:"
            << "\n1) Incident Vector"
            << "\n2) Normal Vector"
            << "\n3) Result Vector\n\n";
  /**
      Test Case 1
      Visualization can be verified at the provided link below:
      http://www.bodurov.com/VectorVisualizer/?vectors=0/0/0/5/5/0v0/0/0/0/1/0v0/0/0/-5/5/0
  */
  incident = Vector3(5.f, 5.f, 0.f);
  normal = Vector3(0.f, 1.f, 0.f);
  result = Vector3::Reflect(incident, normal);
  result *= -1;
  PrintVector3(incident);
  PrintVector3(normal);
  PrintVector3(result);
  std::cout << '\n';
  /**
      Test Case 2
      Visualization can be verified at the provided link below:
      http://www.bodurov.com/VectorVisualizer/?vectors=0/0/0/1/-1/-1v0/0/0/2/2/2v0/0/0/-9/-7/-7
  */
  incident = Vector3(1.f, -1.f, -1.f);
  normal = Vector3(1.f, 0.f, 0.f);
  result = Vector3::Reflect(incident, normal);
  PrintVector3(incident);
  PrintVector3(normal);
  PrintVector3(result);
  std::cout<< "\nPress Enter to exit: ";
  std::cin.get();
  return 0;
}
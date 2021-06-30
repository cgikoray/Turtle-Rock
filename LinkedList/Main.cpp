#include "LinkedList.h"
#include "Random.h"

/*_______________________________________________________________________

  This program inserts a 1000 random floating point values into a 
  templatized LinkedList data structure. It then prints the lists
  unsorted, sorts the list using an internal merge-sort implementation,
  and then prints the sorted list.
_______________________________________________________________________*/

namespace 
{
    const unsigned int count = 1000;
}

int main()
{
    LinkedList<int>* list = new LinkedList<int>();
    list->Print();

    std::cout<< "\nPrinting unsorted Linked List: \n";
    const Random random;
    for(unsigned int i = 0; i < count; ++i)
    {
        list->PushBack(random.GetInt());
    }
    list->Print();

    std::cout<< "\nPrinting sorted Linked List: \n";
    list->Sort();
    list->Print();

    delete list;

    std::cout<< "\nPress Enter to exit: ";
    std::cin.get();

    return 0;
}
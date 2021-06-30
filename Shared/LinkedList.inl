#include <iostream>

/**
    Default constructor for LinkedList
*/
template <typename T>
LinkedList<T>::LinkedList(void) 
:   m_head(NULL)
{
}

/**
    Destructor for LinkedList
*/
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (NULL != m_head)
    {
        ListNode<T>* temp = m_head;
        m_head = m_head->GetNextNode();
        delete temp;
        temp = NULL;
    }
}

/**
    PushBack: Inserts a ListNode with data to the end of the 
    LinkedList

    @param T templatized data to be stored
*/
template <typename T>
void LinkedList<T>::PushBack(const T& tData)
{
    ListNode<T>* node = new ListNode<T>();
    node->SetData(tData);
    node->SetNextNode(NULL);

    if(NULL == m_head)
    {
        m_head = node;
    }
    else
    {
        ListNode<T>* temp = m_head;

        while(NULL != temp->GetNextNode())
        {
            temp = temp->GetNextNode();
        }
        temp->SetNextNode(node);
    }
}

/**
    Print: Prints the LinkedList using std::cout
*/
template <typename T>
void LinkedList<T>::Print() const
{
    if(NULL == m_head)
    {
        std::cout << "LinkedList is empty." << std::endl;
    }
    else
    {
        ListNode<T>* temp = m_head;

        do
        {
            std::cout << temp->GetData() << " -> ";
            temp = temp->GetNextNode();
        }
        while(NULL != temp);

        std::cout << "NULL" << std::endl;
    }
}

/**
    Sort: Sorts the LinkedList

    Note: Sort uses an internal MergeSort algorithm for sorting the nodes. The
    poor random access speed of linked list data structures makes using commonly
    picked algorithms such as QuickSort unfavorable.
*/
template <typename T>
void LinkedList<T>::Sort()
{
    m_head = MergeSort(m_head);
}

/**
    MergeSort: Recursively divides the list into N sublists. Then repeatedly
    merges the lists until it is sorted.

    @param ListNode pointer to the starting link

    @return ListNode pointer to the resulting merged sublist
*/
template <typename T>
ListNode<T>* LinkedList<T>::MergeSort(ListNode<T>* pNode) const
{
    if(NULL == pNode || NULL == pNode->GetNextNode())
    {
        return pNode;
    }

    ListNode<T>* node = pNode;
    ListNode<T>* next = pNode->GetNextNode();

    while((NULL != next) && (NULL != next->GetNextNode()))
    {
        pNode = pNode->GetNextNode();
        next = (next->GetNextNode())->GetNextNode();
    }

    next = pNode->GetNextNode();
    pNode->SetNextNode(NULL);

    return Merge(MergeSort(node), MergeSort(next));
}

/**
    Merge: Merges the left and right node sublists

    @param ListNode pointer to first sublist
    @param ListNode pointer to second sublist

    @return ListNode pointer to the resulting merged sublist
*/
template <typename T>
ListNode<T>* LinkedList<T>::Merge(ListNode<T>* pFirstNode, ListNode<T>* pSecondNode) const
{
    ListNode<T> head;
    ListNode<T>* node = &head;

    while((NULL != pFirstNode) && (NULL != pSecondNode))
    {
        if(pFirstNode->GetData() <= pSecondNode->GetData())
        {
            node->SetNextNode(pFirstNode);
            node = pFirstNode;
            pFirstNode = pFirstNode->GetNextNode();
        }
        else
        {
            node->SetNextNode(pSecondNode);
            node = pSecondNode;
            pSecondNode = pSecondNode->GetNextNode();
        }
    }

    node->SetNextNode(NULL == pFirstNode ? pSecondNode : pFirstNode);
    return head.GetNextNode();
}
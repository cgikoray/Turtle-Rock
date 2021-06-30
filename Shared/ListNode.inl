/**
    Default constructor for KDNode3
*/
template <typename T>
ListNode<T>::ListNode(void) 
:   m_Data(0), 
    m_Next(0)
{
}

/* Getter and Setters for ListNode */

template <typename T>
void ListNode<T>::SetData(const T& tData)
{
    m_Data = tData;
}

template <typename T>
T& ListNode<T>::GetData()
{
    return m_Data;
}

template <typename T>
const T& ListNode<T>::GetData() const
{
    return m_Data;
}

template <typename T>
void ListNode<T>::SetNextNode(ListNode<T>* const pNext)
{
    m_Next = pNext;
}

template <typename T>
ListNode<T>* ListNode<T>::GetNextNode()
{
    return m_Next;
}

template <typename T>
ListNode<T>* const ListNode<T>::GetNextNode() const
{
    return m_Next;
}
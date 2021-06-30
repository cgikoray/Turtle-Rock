#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma once

#include "ListNode.h"

template <typename T>
class LinkedList
{
public:
    LinkedList(void);
    virtual ~LinkedList();

    void PushBack(const T& tData);
    void Print() const;
    void Sort();

private:
    LinkedList(const LinkedList& rList);
    LinkedList& operator=(const LinkedList& rList);

    ListNode<T>* MergeSort(ListNode<T>* pNode) const;
    ListNode<T>* Merge(ListNode<T>* pFirstNode, ListNode<T>* pSecondNode) const;

    ListNode<T>* m_head;
};

#include "LinkedList.inl"
#endif // LINKED_LIST_H
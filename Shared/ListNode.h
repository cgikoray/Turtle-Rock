#ifndef LIST_NODE_H
#define LIST_NODE_H

#pragma once

template <typename T>
class ListNode
{
public:
    ListNode(void);

    void SetData(const T& tData);
    T& GetData();
    const T& GetData() const;

    void SetNextNode(ListNode<T>* const pNext);
    ListNode<T>* GetNextNode();
    ListNode<T>* const GetNextNode() const;

private:
    ListNode(const ListNode& rNode);
    ListNode& operator=(const ListNode& rNode);

    T m_Data;
    ListNode<T>* m_Next;
};

#include "ListNode.inl"
#endif // LIST_NODE_H
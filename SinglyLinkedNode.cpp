// Vedant Mathur
// CS 10B Professor Farrell
// Programming Assignment 4 - SinglyLinkedList
// SinglyLinkedNode.cpp

#include "SinglyLinkedNode.h"

template <typename T>
SinglyLinkedNode<T>::SinglyLinkedNode(T itemToStore, std::shared_ptr<SinglyLinkedNode<T>> nextNode)
{
    element = itemToStore;
    next = nextNode;
}

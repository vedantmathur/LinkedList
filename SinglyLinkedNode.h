// Vedant Mathur
// CS 10B Professor Farrell
// Programming Assignment 4 - SinglyLinkedList
// SinglyLinkedNode.h

#pragma once
#include <memory>

template<typename T>
class SinglyLinkedNode
{
public:
    T element;
    std::shared_ptr<SinglyLinkedNode<T>> next;
    
    // Constructor
    SinglyLinkedNode(T itemToStore, std::shared_ptr<SinglyLinkedNode<T>> nextNode);
};

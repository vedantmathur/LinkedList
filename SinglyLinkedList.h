// Vedant Mathur
// CS 10B Professor Farrell
// Programming Assignment 4 - SinglyLinkedList
// SinglyLinkedList.h

#pragma once
#include "SinglyLinkedNode.h"
#include "SinglyLinkedNode.cpp"
#include <memory>

template<typename T>
class SinglyLinkedList
{
public:
    // First node pointer
    std::shared_ptr<SinglyLinkedNode<T>> head;
    
    // Inline constructor function
    inline SinglyLinkedList() {head = nullptr;}
    
    // No need for a destructor. Shared Pointers automagically delete any unused pointers
    
    // A display function I made just for debugging purposes.
    void display();
    
    // Pushes an element to the back of the list, replacing head
    void push_back(const T& element);
    // Pushes an element to the top of the list, replacing tail
    void push_front(const T& element);
    // Inserts an element at a position
    bool insert(const T& element, unsigned position);
    // Removes an element at a position
    bool erase(unsigned position);
    // Returns the size of the LinkedList
    unsigned size() const;
    // Removes the back
    void pop_back();
    // Removes the front
    void pop_front();
    // Gets an element at a position
    T& get_element(unsigned position) const;
    // Gets the front element
    T& get_front() const;
    // Gets the back element
    T& get_back() const;
    
};

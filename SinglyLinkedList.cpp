// Vedant Mathur
// CS 10B Professor Farrell
// Programming Assignment 4 - SinglyLinkedList
// SinglyLinkedList.cpp

#include "SinglyLinkedList.h"
#include <iostream>

const int ZERO = 0, ONE  = 1;

// Displaying the Linkedlist
template <typename T>
void SinglyLinkedList<T>::display()
{
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    if (nodeToSee == nullptr) return; // Failsafe
    
    do {
        std::cout << nodeToSee->element << std::endl;
        nodeToSee = nodeToSee->next;
    } while (nodeToSee != nullptr);
}

// Push to the end of the list
template <typename T>
void SinglyLinkedList<T>::push_back(const T& element)
{
    // Need to account for head being null
    if (head == nullptr) {
        head = std::make_shared<SinglyLinkedNode<T>>(SinglyLinkedNode<T>(element, nullptr));
        return;
    }
    
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    while (nodeToSee->next != nullptr) { // Traverse to the end first
        nodeToSee = nodeToSee->next;
    }
    
    SinglyLinkedNode<T> tempEle(element, nullptr);
    nodeToSee->next = std::make_shared<SinglyLinkedNode<T>>(tempEle);
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& element)
{
    if (head == nullptr) { // Failsafe
        head = std::make_shared<SinglyLinkedNode<T>>(SinglyLinkedNode<T>(element, nullptr));
        return;
    }
    
    // Make a new head with the old head as the next.
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    head = std::make_shared<SinglyLinkedNode<T>>(SinglyLinkedNode<T>(element, head));
    
}


template <typename T>
bool SinglyLinkedList<T>::insert(const T& element, unsigned position)
{
    if (position > size()) return false; // Failsafe
    
    if (position == ZERO) { // Failsafe
        head = std::make_shared<SinglyLinkedNode<T>>(SinglyLinkedNode<T>(element, head));
        return true;
    }
    
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    while (--position > ZERO) {
        nodeToSee = nodeToSee->next;
    } // Traverse to node before the position
    
    nodeToSee->next = std::make_shared<SinglyLinkedNode<T>>(SinglyLinkedNode<T>(element, nodeToSee->next));
    return true;
    
}

template <typename T>
bool SinglyLinkedList<T>::erase(unsigned position)
{
    if (position >= size()) return false;
    if (position == ZERO)
    {
        head = head->next;
        return true;
    } // Failsafes
    
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    while (--position > ZERO) {
        nodeToSee = nodeToSee->next;
    } // Traverse to the node before the node you want to erase
    
    nodeToSee->next = nodeToSee->next->next;
    return true;
}

template <typename T>
unsigned SinglyLinkedList<T>::size() const
{
    if (head == nullptr) return ZERO;
    
    unsigned size = ZERO;
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    
    // Count the nodes
    while (nodeToSee != nullptr) {
        size++;
        nodeToSee = nodeToSee->next;
    }
    
    return size;
}

template <typename T>
void SinglyLinkedList<T>::pop_front()
{
    if (head == nullptr) return;
    head = head->next;
    // Losing track of head is okay, shared_ptr takes care of this stuff
}

template <typename T>
void SinglyLinkedList<T>::pop_back()
{
    if (head == nullptr) return; // If head doesn't even exist
    if (head->next == nullptr) head = nullptr; // If head is the only one
        
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    // Kill the next node if the node after that is nullptr
    while (nodeToSee != nullptr && nodeToSee->next->next != nullptr ) {
        nodeToSee = nodeToSee->next;
    }
    // Put it in the back
    nodeToSee->next = nullptr;
}

template <typename T>
T& SinglyLinkedList<T>::get_element(unsigned position) const
{
    if (head == nullptr) throw std::invalid_argument( "HEAD IS NULL" );
    std::shared_ptr<SinglyLinkedNode<T>> nodeToSee = head;
    while (position > ZERO) { // Traverse through list
        nodeToSee = nodeToSee->next;
        position--;
    }
    
    return nodeToSee->element;
}

template <typename T>
T& SinglyLinkedList<T>::get_front() const
{
    if (head == nullptr) throw std::invalid_argument( "HEAD IS NULL" );
    return head->element;
}

template <typename T>
T& SinglyLinkedList<T>::get_back() const
{
    if (head == nullptr) throw std::invalid_argument( "HEAD IS NULL" );
    return get_element(size() - ONE);
}

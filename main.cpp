// Vedant Mathur
// CS 10B Professor Farrell
// Programming Assignment 4 - SinglyLinkedList
// main.cpp

#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "SinglyLinkedList.cpp"

struct Point {
    int x, y;
};

using namespace std;
int main() {

    SinglyLinkedList<char>* listO = new SinglyLinkedList<char>();
    SinglyLinkedList<Point>* listP = new SinglyLinkedList<Point>();
    
    listO->push_front('a');
    listO->push_front('r');
    listO->push_back('m');
    listO->display();
    cout << endl;
    
    Point a;
    Point b;
    listP->push_back(a);
    listP->push_front(b);
    listP->pop_back();
    listP->pop_front();
    
    cout << listO->get_back() << endl;
    cout << listO->get_front() << endl;
    
    listO->insert('6', 1);
    cout << listO->size() << endl;
    
    listO->erase(1);
    listO->get_element(1);
    
    
    return EXIT_SUCCESS;
}

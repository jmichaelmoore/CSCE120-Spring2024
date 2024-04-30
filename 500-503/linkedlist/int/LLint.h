#ifndef LLINT_H
#define LLINT_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LLint {
    Node* head;
    Node* tail;
    void printRecursive(Node* n, std::ostream& os = std::cout);
    
  public:
    LLint() : head(nullptr), tail(nullptr) {}

    void insertFront(const int& val);
    void insertBack(const int& val);

    void insertAfter(const int& valToInsert, const int& valToFind);
    void insertBefore(const int& valToInsert, const int& valToFind);

    void print(std::ostream& = std::cout) const;
    void printReverse(std::ostream& = std::cout);
};

std::ostream& operator<<(std::ostream&, const LLint&);

#endif
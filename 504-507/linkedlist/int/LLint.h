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
  public:
    LLint() : head(nullptr), tail(nullptr) {}

    void insertFront(const int& val);
    void insertBack(const int& val);

    void print(std::ostream& = std::cout) const;
};

std::ostream& operator<<(std::ostream&, const LLint&);

#endif
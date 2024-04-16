#include "LLint.h"

using std::cout, std::endl;

void LLint::insertFront(const int& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if (tail==nullptr) {
        tail = newNode;
    }
}

void LLint::insertBack(const int& data) {
    Node* newNode = new Node(data); // newNode->next is set to nullptr in its constructor
    if (tail == nullptr) { // empty list
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LLint::print(std::ostream& os) const {
    Node* cur = head;
    if (cur == nullptr) {
        os << "Empty List!" << endl;
    }
    while (cur != nullptr) {
        os << cur->data << endl;
        cur = cur->next;
    }
}
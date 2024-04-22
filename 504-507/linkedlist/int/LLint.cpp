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

void LLint::insertAfter(const int& valToInsert, const int& valToFind) {
    Node* newNode = new Node(valToInsert);
    if (head==nullptr) {
        head = tail = newNode;
    }
    else {
        Node* cur = head;
        while (cur != nullptr && cur->data != valToFind) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cur = tail;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        if (cur == tail) {
            tail = newNode;
        }
    }
}

void LLint::insertBefore(const int& valToInsert, const int& valToFind) {
    Node* newNode = new Node(valToInsert);
    if (head==nullptr) {
        head = tail = newNode;
    }
    else {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur != nullptr && cur->data != valToFind) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) {
            cur = head;
            prev = nullptr;
        }
        newNode->next = cur;
        if (prev == nullptr) {
            head = newNode;
        }
        else {
            prev->next = newNode;
        }
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

void LLint::clear() {
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
    // head is nullptr when loop exits
    tail = nullptr;
}
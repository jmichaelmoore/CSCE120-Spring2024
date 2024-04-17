#include <iostream>
#include "LLstr.h"

using std::cout, std::endl;

void LLstr::insertFront(const char& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { // empty list
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void LLstr::insertBack(const char& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { // empty list
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void LLstr::print(std::ostream& os) const {
    Node* cur = head;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->next;
    }
}

void LLstr::printReverse(std::ostream& os) const {
    Node* cur = tail;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->prev;
    }
}

LLstr::LLstr(const std::string& src) : head(nullptr), tail(nullptr) { // copy std::string
    for (size_t i=0; i<src.size(); ++i) {
        insertBack(src.at(i));
    }
}

LLstr::LLstr(const char* src) : head(nullptr), tail(nullptr) { // copy c-string
    size_t index = 0;
    while (src[index] != '\0') {
        insertBack(src[index]);
        index++;
    }
}

std::ostream& operator<<(std::ostream& os, const LLstr& src) {
    src.print(os);
    return os;
}

Node* LLstr::find(const char& c) {
    Node* cur = head;
    while (cur != nullptr && cur->letter != c) {
        cur = cur->next;
    }
    return cur;
}

bool LLstr::hasChar(const char& c) {
    return find(c) != nullptr;
}

void LLstr::insertAfter(const char& valToAdd, const char& valToFind) {
    Node* newNode = new Node(valToAdd);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        Node* cur = find(valToFind);
        if (cur == nullptr) {
            cur = tail;
        }
        newNode->next = cur->next;
        newNode->prev = cur;
        if (cur->next = nullptr) { // new tail
            tail = newNode;
        }
        else {
            cur->next->prev = newNode;
        }
        cur->next = newNode;
    }
}
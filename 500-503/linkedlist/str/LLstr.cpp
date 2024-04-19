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

Node* LLstr::find(const int& val) {
    Node* cur = head;
    while (cur != nullptr && cur->letter != val) {
        cur = cur->next;
    }
    return cur;
}

bool LLstr::hasChar(const char& val) {
    return find(val) != nullptr;
}


void LLstr::insertAfter(const char& valToAdd, const char& valToFind) {
    Node* newNode = new Node(valToAdd);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        Node* cur = head;
        while (cur != nullptr && cur->letter != valToFind) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cur = tail;
        }
        newNode->next = cur->next;
        newNode->prev = cur;
        if (cur == tail) { // if cur->next == nullptr
            tail = newNode;
        }
        else {
            cur->next->prev = newNode;
        }
        cur->next = newNode;
    }
}

void LLstr::insertBefore(const char& valToAdd, const char& valToFind) {
    Node* newNode = new Node(valToAdd);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        Node* cur = head;
        while (cur != nullptr && cur->letter != valToFind) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cur = head;
        }
        newNode->next = cur;
        newNode->prev = cur->prev;
        if (cur == head) { // cur->prev == nullptr
            head = newNode;
        }
        else {
            cur->prev->next = newNode;
        }
        cur->prev = newNode;
    }
}

void LLstr::remove(const char& c) {
    Node* cur = head;
    while (cur && cur->letter != c) {
        cur = cur->next;
    }
    if (cur != nullptr) {
        if (cur->prev == nullptr) { // removing head
            head = cur->next;
        }
        else {
            cur->prev->next = cur->next;
        }
        if (cur->next == nullptr) {
            tail = cur->prev;
        }
        else {
            cur->next->prev = cur->prev;
        }
    }
    delete cur;
}
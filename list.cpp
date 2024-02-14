#include "list.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Node::Node(int val) : data(val), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::add_value(int value, int position) {
    if (position < 0)
        throw "Position must be non-negative";

    Node* newNode = new Node(value);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == nullptr)
        throw "Position out of bounds";

    newNode->next = current->next;
    current->next = newNode;
}

int LinkedList::remove_value(int position) {
    if (position < 0)
        throw "Position must be non-negative";

    if (head == nullptr)
        throw "List is empty";

    Node* temp = nullptr;

    if (position == 0) {
        temp = head;
        head = head->next;
    } else {
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current == nullptr || current->next == nullptr)
            throw "Position out of bounds";

        temp = current->next;
        current->next = current->next->next;
    }

    int removedValue = temp->data;
    delete temp;
    return removedValue;
}

int LinkedList::get_value(int position) {
    if (position < 0)
        throw "Position must be non-negative";

    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }

    if (current == nullptr)
        throw "Position out of bounds";

    return current->data;
}

int LinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

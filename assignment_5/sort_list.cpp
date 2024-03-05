#include "list.hpp"
#include <iostream>

SortedLinkedList::SortedLinkedList():head(nullptr){}

SortedLinkedList::~SortedLinkedList()
{
    Node* current = head;
    
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void SortedLinkedList::insert(int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr || value < head->data)
    {
        newNode->next = head;
        head = newNode;
    }

    else
    {
        Node* current = head;

        while (current->next != nullptr && current->next->data < value)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

bool SortedLinkedList::search(int value)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SortedLinkedList::display()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

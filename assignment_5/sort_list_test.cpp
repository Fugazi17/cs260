#include <iostream>
#include "list.hpp"

using std::cout;
using std::endl;

int main() {
    SortedLinkedList list;

    cout << "creating list" << endl;

    list.insert(5);
    list.display();

    list.insert(3);
    list.display();

    list.insert(8);
    list.display();

    list.insert(1);
    list.display();

    list.insert(7);
    list.display();

    cout << "Sorted Linked List: ";
    list.display();

    cout << "Searching for 3: " << (list.search(3) ? "Found" : "Not found") << std::endl;
    cout << "Searching for 6: " << (list.search(6) ? "Found" : "Not found") << std::endl;

    return 0;
}

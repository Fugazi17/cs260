#include "list.hpp"
#include <iostream>

using std::cout;
using std::endl;

void testAdd() {
    LinkedList myList;

    // Add 5 at position 0
    myList.add_value(5, 0);  

    // Add 10 at position 1
    myList.add_value(10, 1); 

    // Add 7 at position 1
    myList.add_value(7, 1);  

    // Verify the content of the list
    cout << "Test Add: ";
    for (int i = 0; i < myList.size(); ++i) {
        cout << myList.get_value(i) << " ";
    }
    cout << endl;
}

void testRemove() {
    LinkedList myList;
    myList.add_value(5, 0);
    myList.add_value(10, 1);
    myList.add_value(7, 1);
    
    // Remove value at position 1
    int removedValue = myList.remove_value(1); 

    // Verify the content of the list after removal
    cout << "Test Remove: ";
    for (int i = 0; i < myList.size(); ++i) {
        cout << myList.get_value(i) << " ";
    }
    cout << "(Removed: " << removedValue << ")" << endl;
}

void testGet() {
    LinkedList myList;
    myList.add_value(5, 0);
    myList.add_value(10, 1);
    myList.add_value(7, 1);

    // Verify the value at position 1
    cout << "Test Get: Value at position 1: " << myList.get_value(1) << endl;
}

int main() {
    testAdd();
    testRemove();
    testGet();

    return 0;
}

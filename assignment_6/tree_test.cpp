#include "root.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{

    cout << "building tree: " << endl;

    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.add(1);
    tree.add(4);
    tree.add(6);
    tree.add(8);


    cout << "In-order traversal: ";
    tree.inOrderTraversal();
    cout << endl;

    tree.remove(7);

    cout << "In-order traversal after removing 7: ";
    tree.inOrderTraversal();
    cout << endl;

    return 0;
}

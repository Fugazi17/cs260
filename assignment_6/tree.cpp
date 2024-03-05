#include "root.hpp"
#include <iostream>

using std::cout;

BST::BST():root(nullptr){}

BST::~BST()
{
    // Perform post-order traversal to delete all nodes
    while (root != nullptr)
    {
        remove(root->val);
    }
}

void BST::add(int value)
{
    root = add(root, value);
}

TreeNode* BST::add(TreeNode* root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value <= root->val)
    {
        root->left = add(root->left, value);
    }

    else
    {
        root->right = add(root->right, value);
    }

    return root;
}

void BST::remove(int value)
{
    root = remove(root, value);
}

TreeNode* BST::remove(TreeNode* root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (value < root->val)
    {
        root->left = remove(root->left, value);
    }
    
    else if (value > root->val)
    {
        root->right = remove(root->right, value);
    }
    
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        
        else if (root->right == nullptr)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = remove(root->right, temp->val);
    }
    return root;
}

TreeNode* BST::findMin(TreeNode* node)
{
    TreeNode* current = node;

    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

void BST::inOrderTraversal()
{
    inOrderTraversal(root);
}

void BST::inOrderTraversal(TreeNode* root)
{
    if (root != nullptr) 
    {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

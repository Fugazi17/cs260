class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr){}
};

class BST
{
private:
    TreeNode* root;

    TreeNode* add(TreeNode* root, int value);
    TreeNode* findMin(TreeNode* node);
    TreeNode* remove(TreeNode* root, int value);
    void inOrderTraversal(TreeNode* root);

public:
    BST();
    ~BST();

    void add(int value);
    void remove(int value);
    void inOrderTraversal();
};
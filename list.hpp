struct Node {
    int data;
    Node* next;
    Node(int val);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void add_value(int value, int position);
    int remove_value(int position);
    int get_value(int position);
    int size();
};

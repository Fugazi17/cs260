class SortedLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    SortedLinkedList();
    ~SortedLinkedList();

    void insert(int value);
    bool search(int value);
    void display();
};
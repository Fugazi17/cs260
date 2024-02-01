class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    bool is_empty();
    void enqueue(int value);
    int dequeue();
    int peek();
};
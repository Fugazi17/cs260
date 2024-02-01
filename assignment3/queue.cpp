#include "queue.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


Node::Node(int value) : data(value), next(nullptr) {}
Queue::Queue() : front(nullptr), rear(nullptr) {}


int main() {
    Queue myQueue;

    while(true) {
        int input = 0;
        cout << "please pick an option: " << endl;
        cout << "   enter 1 to add to the back of the queue. (enqueue)" << endl;
        cout << "   enter 2 to remove from the front of the queue. (dequeue)" << endl;
        cout << "   enter 3 to peek at the front of the queue. (peek)" << endl;
        cout << "   enter 4 to end program" << endl;
        cin >> input;

        if(input == 1) {
            int value;
            cout << endl << "what value did you want to add to the queue" << endl << endl;
            cin >> value;
            myQueue.enqueue(value);
            continue;
            }

        else if(input == 2) {
            myQueue.dequeue();
            continue;
            }

        else if(input == 3) {
            myQueue.peek();
            continue;
            }

        else if(input == 4) {
            cout << "good bye";
            break;
            }

        continue;
    }

    return 0;
}

bool Queue::is_empty() {
    return front == nullptr;
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);

    if (is_empty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (is_empty()) {
        cout << endl << "Queue is empty. Cannot dequeue." << endl;
        return 0;
    }

    int value = front->data;
    Node* temp = front;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }

    cout << "Dequeue: " << value << endl;
    delete temp;
    return 0;
}

int Queue::peek() {
    if (is_empty()) {
        cout << endl << "Queue is empty. Cannot peek." << endl;
        return 0;
    }

    cout << "Front element: " << front->data << endl;
    return 0;
}

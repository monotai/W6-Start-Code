#include "Node.h"

class Queue {
private:
    Node* front;     // Pointer to the front of the queue
    Node* rear;      // Pointer to the rear of the queue
    int length;      // Keeps track of the queue size
public:
    Queue() {       // Constructor
        // your code here
        this->front = nullptr;
        this->rear = nullptr;
        this->length = 0;
    }
    ~Queue() {      // Destructor to free memory
        while (!isEmpty()) {
            dequeue();   // Deallocate all nodes
        }
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        this->length++;
    }
    // Dequeue the front element from the queue
    void dequeue() {
        // your code here
        Node* node = front;
        front = node->next;
        delete node;
        this->length--;
    }
    // Peek the front element without removing it
    int peek() {
        // your code here
        return front->data;
    }
    // Check if the queue is empty
    bool isEmpty() {
        // your code here
        if(front == nullptr) {
        return true;
       }
       return false;
    }
    // Get the current length of the queue
    int size() {
        return length;
    }

    // Convert the queue to a string representation
    std::string toString() {
      // your code here
        std::string result = "Result: [";
        Node* node = front;
        while(node != nullptr) {
            result = result + std::to_string(node->data) + ",";
            node = node->next;
        }
        result.pop_back();
        result = result + "]";
        return result;
    }

};

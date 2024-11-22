#include "Node.h"
#include <string.h>

class Stack {
    private:
    Node* top;     // Pointer to the top of the stack
    int length;      // Keeps track of the stack size

    public:
    Stack() {       // Constructor
        // your code here
        this->top = nullptr;
        this->length = 0;
    }

    ~Stack() {      // Destructor to free memory
        while (!isEmpty()) {
            pop();   // Deallocate all nodes
        }
    }

    // Push an element onto the stack
    void push(int value) {
       // your code here
       Node* newNode = new Node(value);
       newNode->next = top;
       top = newNode;
       this->length++;
    }

    // Pop the top element from the stack
    void pop() {
        // your code here
        Node* node = top;
        top = node->next;
        delete node;
        this->length--;
    }

    // Peek the top element without removing it
    int peek() {
        // your code here
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
       // your code here
       if(top == nullptr) {
        return true;
       }
       return false;
    }

    // Get the current length of the stack
    int size() {
        return length;
    }
    // Convert the stack to a string representation
    std::string toString() {
       // your code here
        std::string result = "Result: [";
        Node* node = top;
        while(node != nullptr) {
            result = result + std::to_string(node->data) + ",";
            node = node->next;
        }
        result.pop_back();
        result = result + "]";
        return result;
    }
};

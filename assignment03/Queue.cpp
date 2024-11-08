#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef> // for size_t
#include <stdexcept> // for exception handling
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;  // Points to the front of the queue
    Node* tail;  // Points to the back of the queue
    size_t count; // Tracks the number of elements in the queue

public:
    // Constructor
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    // Destructor
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    // Adds an item to the back of the queue
    void push(const T& item) {
        Node* newNode = new Node(item);

        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode;
        }

        tail = newNode;
        ++count;
    }

    // Removes the front item from the queue
    void pop() {
    if (empty()) {
        throw runtime_error("Queue is empty. Cannot pop.");
    }

    Node* temp = head;
    head = head->next;

    if (head) {
        head->prev = nullptr; // Update the previous pointer to null
    } else {
        tail = nullptr;  // If the queue becomes empty, reset tail to nullptr
    }

    delete temp;  // Delete the old front node
    --count;
}

    // Returns the front item without removing it
    T& front() {
        if (empty()) {
            throw runtime_error("Queue is empty. No front element.");
        }
        return head->data;
    }

    // Returns the number of items in the queue
    size_t size() const {
        return count;
    }

    // Checks if the queue is empty
    bool empty() const {
        return count == 0;
    }

};

#endif // QUEUE_H

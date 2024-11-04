#ifndef QUEUE_H
#define QUEUE_H
#include "Function.h"

template <typename T>
class Queue {
private:
    // Node structure for doubly linked list
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
    Queue();
    ~Queue();

    // Adds an item to the back of the queue
    void push(const T& item);

    // Removes the front item from the queue
    void pop();

    // Returns the front item without removing it
    T front();
    const T& front() const;

    // Returns the number of items in the queue
    size_t size() const;

    // Checks if the queue is empty
    bool empty() const;
};
#endif QUEUE_H
#include "Queue.h"

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& item) {
    Node* newNode = new Node(item);

    if (tail) {
        tail->next = newNode;
        newNode->prev = tail;
    }
    else {
        head = newNode;
    }

    tail = newNode;
    ++count;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        ("Queue is empty. Cannot pop.");
    }

    Node* temp = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete temp;
    --count;
}

template <typename T>
T Queue<T>::front() {
    if (empty()) {
        ("Queue is empty. No front element.");
    }
    return head->data;
}

template <typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        ("Queue is empty. No front element.");
    }
    return head->data;
}

template <typename T>
size_t Queue<T>::size() const {
    return count;
}

template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

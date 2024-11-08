#include "Function.h"

void move_to_rear(Queue<int>& listNums) {
    // If the queue is empty, throw an exception
    if (listNums.empty()) {
        throw runtime_error("Queue is empty. Cannot move element to the rear.");
    }
    // If the queue has only one element, no need to move anything
    else if (listNums.size() == 1) {
        return;  // Only one element, no move needed
    }
    else {
        // Pop the front element and then push it to the rear
        int temp = listNums.front();  // Get the front element (don't pop yet), use templated type
        listNums.pop();             // Remove the front element
        listNums.push(temp);        // Add it to the back of the queue
    }
};

int linear_search(KW::vector<int>& items, int target, size_t pos)
{
    if (pos == items.size())
        return -1;

    int last_occurrence = linear_search(items, target, pos + 1);

    if(last_occurrence != -1)
        return last_occurrence;

    else if (items[pos] == target)
        return pos;

    else
        return -1;
};

void insertion_sort(Queue<int>& queue) {
    int i, j, key, frontElement;
    KW::vector <int> vec;

    // Load vector with queue elements
    while (!queue.empty()) {
        frontElement = queue.front();
        vec.push_back(frontElement);
        queue.pop();
    }
    //run vector insertion 
    bool insertionNeeded = false;
    for (j = 1; j < vec.size(); j++) {
        key = vec[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--) {
            if (key < vec[i]) {
                vec[i + 1] = vec[i]; // larger values move right
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded)
            vec[i + 1] = key; //Put key into its proper location
    }

    // move sorted vector to queue
    for (i = 0; i < vec.size(); i++) {
        queue.push(vec[i]);
    }
};


// assignment03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Function.h"
#include <vector>
using namespace std; 

int main()
{
    // Seed for random number generation
    srand((time(0)));

    // Create a vector of Queue<int>
    vector<Queue<int>> queues;

    // Generate 10 random numbers and store each in a Queue
    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 100; // generate a random number between 0 and 99
        Queue<int> queue;
        queue.push(randomNumber); // push the random number into the queue
        queues.push_back(queue); // add the queue to the vector
    }

    // Display the contents of each queue
    for (size_t i = 0; i < queues.size(); ++i) {
        cout << "Queue " << i + 1 << " Front Element: " << queues[i].front() << endl;
    }

    return 0;
}


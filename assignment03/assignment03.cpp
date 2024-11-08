#include <iostream>
#include "Function.h"
#include <cstdlib>
#include <ctime>  


void print(Queue<int>& queue) 
{
    size_t originalSize = queue.size(); 

    for (size_t i = 0; i < originalSize; ++i) {
        try {
            // Access the front element
            int frontElement = queue.front();

            // Display the front element
            cout << frontElement << " ";

            // Remove the front element and push it back to maintain the order
            queue.pop();
            queue.push(frontElement);
        }
        catch (const runtime_error& e) {
            // Catch and display any runtime error (e.g., queue is empty)
            cout << "Error: " << e.what() << endl;
        }
    }
    cout << "\n" << endl;
}

int main() {
    // Seed for random number generation
    srand((time(0)));

    // Create a Queue and vector
    Queue<int> listNums;
    KW::vector<int> myVec;


    // Generate 10 random numbers and store each in the Queue
    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 6;  // generate a random number between 0 and 6
        listNums.push(randomNumber);      // Add to the queue
        myVec.push_back(randomNumber); // Add elements to each Vector in the array
    }

    // Display the contents of ListNums without altering its order
    cout << "Contents of ListNums:\n\nCurrent Size: " << listNums.size() << "\n" << endl;
    print(listNums);

    // Exception handling when calling move_to_rear
    try {
        move_to_rear(listNums);  // Call the function to move the front element to the rear
    }
    catch (const runtime_error& e) {
        // Catch and display the runtime error
        cout << "\nError: " << e.what() << endl;
    }
    catch (const exception& e) {
        // Catch and display any other unexpected exceptions
        cout << "\nAn unexpected error occurred: " << e.what() << endl;
    }

    // ------Display the updated contents after move_to_rear------
    cout << "Updated contents after moving front to rear:\n\n";
    print(listNums);

    //-----VECTOR-------
    cout << "Vector: " << endl;
    try {
        for (int i = 0; i < myVec.size(); ++i) {
            cout << " " << myVec[i];
        }
        cout << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    int target = rand() % 6;
    int last_Occur = 0;
    last_Occur = linear_search(myVec,target, last_Occur);
    if (last_Occur != -1) {
        cout << "\nLast occurrence of target " << target << " is at index " << last_Occur << "\n" << endl;
    }
    else {
        cout << "\nTarget not found" << endl;
    }

    //Insertions sort 
    insertion_sort (listNums);
    cout << "Inserstion Sort" << endl;
    print(listNums);

    return 0;
}

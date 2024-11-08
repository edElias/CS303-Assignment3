#pragma once
#include "Queue.cpp"
#include "Vector.cpp"
using namespace std;

void move_to_rear(Queue<int>& listNums);
int linear_search(KW::vector<int>& items, int target, size_t pos_first);
void insertion_sort (Queue<int>& queue);
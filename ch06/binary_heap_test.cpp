//
// Created by seineo on 2020/1/11.
//

#include "binary_heap.h"
#include <iostream>

using namespace std;

int main() {
    try {
        PriorityQueue pq1(4);
    } catch (const runtime_error &error) {
        cout << "Size < MinSize : " << error.what() << endl;
    }
    PriorityQueue pq(10);
    cout << boolalpha << "Empty : " << pq.IsEmpty() << "\tFull : " << pq.IsFull() << endl;
    try {
        for (int i = 0; i != 15; ++i) {
            pq.Insert(i);
        }
    } catch (const runtime_error &error) {
        cout << "Insert : " << error.what() << endl;
    }
    cout << boolalpha << "Full : " << pq.IsFull() << endl;
    cout << "FindMin : " << pq.FindMin() << endl;
    while (!pq.IsEmpty()) {
        cout << "DeleteMin : " << pq.DeleteMin() << endl;
    }
    try {
        cout << "When empty DeleteMin : " << pq.DeleteMin() << endl;
    } catch (const runtime_error &error) {
        cout << error.what() << endl;
    }
    try {
        cout << "When empty FindMin : " << pq.FindMin() << endl;
    } catch (const runtime_error &error) {
        cout << error.what() << endl;
    }
    return 0;
}


//output :
//Size < MinSize : Size is too small
//Empty : true	Full : false
//Insert : Priority queue is full
//Full : true
//FindMin : 0
//DeleteMin : 0
//DeleteMin : 1
//DeleteMin : 2
//DeleteMin : 3
//DeleteMin : 4
//DeleteMin : 5
//DeleteMin : 6
//DeleteMin : 7
//DeleteMin : 8
//DeleteMin : 9
//When empty DeleteMin : priority queue is empty
//When empty FindMin : priority queue is empty

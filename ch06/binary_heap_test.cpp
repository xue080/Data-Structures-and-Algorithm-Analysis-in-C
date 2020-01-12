//
// Created by seineo on 2020/1/11.
//

#include "binary_heap.h"
#include <iostream>

using namespace std;

int main() {
    try {
        PriorityQueue pq1(4);
    } catch (const logic_error &error) {
        cout << "pq1 Size < MinSize : " << error.what() << endl;
    }
    PriorityQueue pq(6);
    cout << boolalpha << "pq Empty : " << pq.IsEmpty() << "\t pq Full : " << pq.IsFull() << endl;

    try {
        for (int i = 0; i != 6; ++i) {
            pq.Insert(i);
        }
    } catch (const logic_error &error) {
        cout << "pq Insert : " << error.what() << endl;
    }
    PriorityQueue pq2(pq);
    cout << boolalpha << "pq Full : " << pq.IsFull() << endl;

    cout << "pq FindMin : " << pq.FindMin() << endl;
    while (!pq.IsEmpty()) {
        cout << "pq DeleteMin : " << pq.DeleteMin() << endl;
    }
    try {
        cout << "pq When empty DeleteMin : " << pq.DeleteMin() << endl;
    } catch (const logic_error &error) {
        cout << error.what() << endl;
    }
    try {
        cout << "pq When empty FindMin : " << pq.FindMin() << endl;
    } catch (const logic_error &error) {
        cout << error.what() << endl;
    }

    pq2.DecreaseKey(2, 10);
    cout << "pq2 FindMin : " << pq2.FindMin() << endl;
    pq2.IncreaseKey(1, 20);
    cout << "pq2 FindMin : " << pq2.FindMin() << endl;
    pq2.Delete(3);
    while (!pq2.IsEmpty()) {
        cout << "pq2 DeleteMin : " << pq2.DeleteMin() << endl;
    }

    PriorityQueue pq3(5);
    try {
        pq3.BuildHeap(6);
    } catch (const logic_error &error) {
        cout << "pq3 : " << error.what() << endl;
    }
    pq3.BuildHeap(3);
    while (!pq3.IsEmpty()) {
        cout << "pq3 DeleteMin : " << pq3.DeleteMin() << endl;
    }
    return 0;
}

//input(When build heap) :
//2 1 3

//output :
//pq1 Size < MinSize : Size is too small
//pq Empty : true	 pq Full : false
//pq Full : true
//pq FindMin : 0
//pq DeleteMin : 0
//pq DeleteMin : 1
//pq DeleteMin : 2
//pq DeleteMin : 3
//pq DeleteMin : 4
//pq DeleteMin : 5
//pq When empty DeleteMin : Priority queue is empty
//pq When empty FindMin : Priority queue is empty
//pq2 FindMin : -9
//pq2 FindMin : 0
//pq2 DeleteMin : 0
//pq2 DeleteMin : 3
//pq2 DeleteMin : 4
//pq2 DeleteMin : 5
//pq2 DeleteMin : 11
//pq3 : Size is too big
//pq3 DeleteMin : 1
//pq3 DeleteMin : 2
//pq3 DeleteMin : 3
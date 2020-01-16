//
// Created by seineo on 2020/1/15.
//

#include <iostream>
#include "leftist_heap.h"

using namespace std;

int main() {
    int n, num;
    PriorityQueue pq;
    cout << "pq Empty : " << boolalpha << pq.IsEmpty() << endl;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        cin >> num;
        pq.Insert(num);
    }
    PriorityQueue pq2(pq);
    cout << "pq FindMin : " << pq.FindMin() << endl;
    while (!pq.IsEmpty()) {
        cout << "pq DeleteMin : " << pq.DeleteMin() << endl;
    }
    try {
        cout << "pq FindMin : " << pq.FindMin() << endl;
    } catch (const logic_error &error) {
        cout << error.what() << endl;
    }
    try {
        cout << "pq DeleteMin : " << pq.DeleteMin() << endl;
    } catch (const logic_error &error) {
        cout << error.what() << endl;
    }
    PriorityQueue pq3 = pq;
    cout << "pq3 Empty : " << pq3.IsEmpty() << endl;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        cin >> num;
        pq3.Insert(num);
    }
    pq2.Merge(pq3);
    while (!pq2.IsEmpty()) {
        cout << "After merge, pq2 DeleteMin : " << pq2.DeleteMin() << endl;
    }
    return 0;
}

//input :
//5
//2 3 1 5 4
//3
//7 0 6

//output :
//pq Empty : true
//pq FindMin : 1
//pq DeleteMin : 1
//pq DeleteMin : 2
//pq DeleteMin : 3
//pq DeleteMin : 4
//pq DeleteMin : 5
//pq FindMin : Priority queue is empty
//pq DeleteMin : Priority queue is empty
//pq3 Empty : true
//After merge, pq2 DeleteMin : 0
//After merge, pq2 DeleteMin : 1
//After merge, pq2 DeleteMin : 2
//After merge, pq2 DeleteMin : 3
//After merge, pq2 DeleteMin : 4
//After merge, pq2 DeleteMin : 5
//After merge, pq2 DeleteMin : 6
//After merge, pq2 DeleteMin : 7

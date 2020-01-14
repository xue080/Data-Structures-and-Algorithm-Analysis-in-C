//
// Created by seineo on 2020/1/14.
//

#include <iostream>
#include <vector>

using namespace std;

#define MinData -99999999

vector<int> heap;

void PercolateDown(int i, int k) {
    int child;
    int temp = heap[i];
    for (; i * 2 <= k; i = child) {
        child = i * 2;
        if (child != k && heap[child + 1] < heap[child]) {
            child++;
        }
        if (temp > heap[child]) {
            heap[i] = heap[child];
        } else {
            break;
        }
    }
    heap[i] = temp;
}

void Insert(int x, int k) {
    int i;
    heap[1] = x;   //equal to delete min and insert x
    PercolateDown(1, k);
}

void BuildHeap(int k) {
    for (int i = k / 2; i > 0; --i) {
        PercolateDown(i, k);
    }
}

int Select(int N, int k) {
    int data;
    heap.resize(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> heap[i];
    }
    heap[0] = MinData;
    BuildHeap(k);  //min heap
    for (int i = 0; i != N - k; ++i) {
        cin >> data;
        if (data > heap[1]) {
            Insert(data, k);
        }
    }
    return heap[1];
}

int main() {
    int N, k;
    cin >> N >> k;
    cout << Select(N, k) << endl;
    return 0;
}

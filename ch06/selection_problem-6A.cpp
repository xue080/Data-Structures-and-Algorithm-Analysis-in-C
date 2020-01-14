//
// Created by seineo on 2020/1/14.
//

#include <iostream>
#include <vector>

using namespace std;

#define MaxData 99999999

vector<int> heap;
int N;

void PercolateDown(int i) {
    int child;
    int temp = heap[i];
    for (; i * 2 <= N; i = child) {
        child = i * 2;
        if (child != N && heap[child + 1] > heap[child]) {
            child++;
        }
        if (temp < heap[child]) {
            heap[i] = heap[child];
        } else {
            break;
        }
    }
    heap[i] = temp;
}

int DeleteMax() {
    int max = heap[1];
    swap(heap[1], heap[N--]);
    PercolateDown(1);
    return max;
}

void BuildHeap() {
    for (int i = N / 2; i > 0; --i) {
        PercolateDown(i);
    }
}

int Select(int k) {
    int max;
    BuildHeap();
    for (int i = 0; i != k; ++i) {
        max = DeleteMax();
    }
    return max;
}

int main() {
    int k;
    cin >> N >> k;
    heap.resize(N + 1);
    heap[0] = MaxData;
    for (int i = 1; i <= N; ++i) {
        cin >> heap[i];
    }
    cout << Select(k) << endl;
    return 0;
}

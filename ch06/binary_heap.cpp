//
// Created by seineo on 2020/1/11.
//

#include "binary_heap.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

PriorityQueue::PriorityQueue(int max_size) {
    if (max_size < MinSize) {
        throw std::logic_error("Size is too small");
    }
    priority_queue = new HeapStruct(max_size);
}

PriorityQueue::PriorityQueue(const PriorityQueue &pq) {
    priority_queue = new HeapStruct(pq.priority_queue->capacity, pq.priority_queue->size);
    std::copy(pq.priority_queue->elems, pq.priority_queue->elems + pq.priority_queue->capacity + 1,
              priority_queue->elems);
}

PriorityQueue &PriorityQueue::operator=(PriorityQueue pq) {
    std::swap(priority_queue, pq.priority_queue);
    return *this;
}

PriorityQueue::~PriorityQueue() {
    if (priority_queue != nullptr) {
        delete priority_queue;
        priority_queue = nullptr;
    }
}

void PriorityQueue::MakeEmpty() {
    priority_queue->size = 0;
}

void PriorityQueue::PercolateUp(int i, Elemtype x) {
    for (; priority_queue->elems[i / 2] > x; i /= 2) {
        priority_queue->elems[i] = priority_queue->elems[i / 2];
    }
    priority_queue->elems[i] = x;
}

void PriorityQueue::PercolateDown(int i) {
    Elemtype last_elem = priority_queue->elems[i];
    int child;
    for (; i * 2 <= priority_queue->size; i = child) {
        child = i * 2;
        if (child != priority_queue->size && priority_queue->elems[child + 1] < priority_queue->elems[child]) {
            child++;
        }
        if (last_elem > priority_queue->elems[child]) {
            priority_queue->elems[i] = priority_queue->elems[child];
        } else {
            break;
        }
    }
    priority_queue->elems[i] = last_elem;
}

void PriorityQueue::Insert(Elemtype x) {
    if (IsFull()) {
        throw std::logic_error("Priority queue is full");
    }
    PercolateUp(++priority_queue->size, x);
}

Elemtype PriorityQueue::DeleteMin() {
    if (IsEmpty()) {
        throw std::logic_error("Priority queue is empty");
    }
    Elemtype min_elem;
    min_elem = priority_queue->elems[1];
    std::swap(priority_queue->elems[1], priority_queue->elems[priority_queue->size--]); //note that size--
    PercolateDown(1);    //let the last element be the first, then percolate down
    return min_elem;
}

Elemtype PriorityQueue::FindMin() const {
    if (IsEmpty()) {
        throw std::logic_error("Priority queue is empty");
    }
    return priority_queue->elems[1];
}

void PriorityQueue::DecreaseKey(int pos, int range) {
    if (range < 0) {
        throw std::logic_error("range is less than 0");
    }
    Elemtype x = priority_queue->elems[pos] - range;
    PercolateUp(pos, x);
}

void PriorityQueue::IncreaseKey(int pos, int range) {
    if (range < 0) {
        throw std::logic_error("range is less than 0");
    }
    priority_queue->elems[pos] += range;
    PercolateDown(pos);
}

void PriorityQueue::Delete(int pos) {
    DecreaseKey(pos, 99999999);   //make the element minimum
    DeleteMin();   //then delete it
}

void PriorityQueue::BuildHeap(int n) {
    if (n > priority_queue->capacity) {
        throw std::logic_error("Size is too big");
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> priority_queue->elems[i];
        priority_queue->size++;
    }
    for (int i = n / 2; i > 0; --i) {
        PercolateDown(i);
    }
}
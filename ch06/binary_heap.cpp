//
// Created by seineo on 2020/1/11.
//

#include <stdexcept>
#include "binary_heap.h"
#include <algorithm>

PriorityQueue::PriorityQueue(int max_size) {
    if (max_size < MinSize) {
        throw std::runtime_error("Size is too small");
    }
    priority_queue = new HeapStruct(max_size);
}

PriorityQueue::PriorityQueue(const PriorityQueue &pq) {
    priority_queue = new HeapStruct(pq.priority_queue->capacity);
    std::copy(pq.priority_queue->elems, pq.priority_queue->elems + pq.priority_queue->capacity, priority_queue->elems);
}

PriorityQueue &PriorityQueue::operator=(PriorityQueue pq) {
    std::swap(priority_queue, pq.priority_queue);
    return *this;
}

PriorityQueue::~PriorityQueue() {
    MakeEmpty();
}

void PriorityQueue::MakeEmpty() {
    if (priority_queue != nullptr) {
        delete priority_queue;
        priority_queue = nullptr;
    }
}

void PriorityQueue::Insert(Elemtype x) {
    if (IsFull()) {
        throw std::runtime_error("Priority queue is full");
        return;
    }
    int i;
    for (i = ++priority_queue->size; priority_queue->elems[i / 2] > x; i /= 2) {  //percolate up
        priority_queue->elems[i] = priority_queue->elems[i / 2];
    }
    priority_queue->elems[i] = x;
}

Elemtype PriorityQueue::DeleteMin() {
    if (IsEmpty()) {
        throw std::runtime_error("priority queue is empty");
        return priority_queue->elems[0];
    }
    int i, child;
    Elemtype min_elem, last_elem;
    min_elem = priority_queue->elems[1];
    last_elem = priority_queue->elems[priority_queue->size--];
    for (i = 1; i * 2 < priority_queue->size; i = child) {
        child = i * 2;
        if (child != priority_queue->size && priority_queue->elems[child + 1] < priority_queue->elems[child]) {
            child++;    //find smaller child
        }
        if (last_elem > priority_queue->elems[child]) {   //percolate down one level
            priority_queue->elems[i] = priority_queue->elems[child];
        } else {
            break;
        }
    }
    priority_queue->elems[i] = last_elem;
    return min_elem;
}

Elemtype PriorityQueue::FindMin() const {
    if(IsEmpty()) {
        throw std::runtime_error("priority queue is empty");
        return priority_queue->elems[0];
    }
    return priority_queue->elems[1];
}

//
// Created by seineo on 2020/1/11.
//

#ifndef DS_BINARY_HEAP_H
#define DS_BINARY_HEAP_H

#define Elemtype int
#define MinSize 5
#define MinData -99999999

struct HeapStruct {
    HeapStruct(int max_size):capacity(max_size),size(0) {
        elems = new Elemtype[max_size + 1];
        elems[0] = MinData;   //elems[0] is a sentinel
    }
    ~HeapStruct() {
        delete [] elems;
    }
    int capacity;
    int size;
    Elemtype *elems;
};

class PriorityQueue {
public:
    PriorityQueue(int max);

    PriorityQueue(const PriorityQueue & pq);

    PriorityQueue &operator=(PriorityQueue pq);

    ~PriorityQueue();

    bool IsEmpty() const { return priority_queue->size == 0; }

    bool IsFull() const { return priority_queue->size == priority_queue->capacity; }

    void Insert(Elemtype x);

    Elemtype DeleteMin();

    Elemtype FindMin() const;

    void MakeEmpty();

private:
    HeapStruct *priority_queue;
};

#endif //DS_BINARY_HEAP_H


//
// Created by seineo on 2020/1/11.
//

#ifndef DS_BINARY_HEAP_H
#define DS_BINARY_HEAP_H

#define Elemtype int
#define MinSize 5
#define MinData -99999999

struct HeapStruct {
    HeapStruct(int max_size,int cur_size = 0) : capacity(max_size), size(cur_size) {
        elems = new Elemtype[max_size + 1]();
        elems[0] = MinData;   //elems[0] is a sentinel
    }

    ~HeapStruct() {
        delete[] elems;
    }

    int capacity;
    int size;
    Elemtype *elems;
};

class PriorityQueue {
public:
    PriorityQueue(int max);

    PriorityQueue(const PriorityQueue &pq);

    PriorityQueue &operator=(PriorityQueue pq);

    ~PriorityQueue();

    bool IsEmpty() const { return priority_queue->size == 0; }

    bool IsFull() const { return priority_queue->size == priority_queue->capacity; }

    void Insert(Elemtype x);

    Elemtype DeleteMin();

    Elemtype FindMin() const;

    void MakeEmpty();

    void DecreaseKey(int pos, int range);

    void IncreaseKey(int pos, int range);

    void Delete(int pos);

    void BuildHeap(int n);

private:
    HeapStruct *priority_queue;

    void PercolateUp(int i, Elemtype x);

    void PercolateDown(int i);
};

#endif //DS_BINARY_HEAP_H

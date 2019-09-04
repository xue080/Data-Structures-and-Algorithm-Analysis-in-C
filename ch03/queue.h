//To simplify matters,
//we assume that the elements in the queue are integers.

#ifndef _QUEUE_H
#define _QUEUE_H

struct QueueRecord {
	QueueRecord() :capacity(0), front(1), rear(0), size(0), array(nullptr) {}
	QueueRecord(int max) :capacity(max) { front = 1; rear = 0; size = 0; array = new int[capacity]; }

	int capacity;
	int front;
	int rear;
	int size;
	int *array;
};

class Queue {
public:
	Queue(int); 
	Queue(const Queue&);
	Queue& operator=(Queue);
	~Queue();

	bool IsEmpty() const { return queue->size == 0; }
	bool IsFull() const { return queue->size == queue->capacity; }
	void MakeEmpty();
	void Enqueue(int x);
	void Dequeue();
	int Front() const { return queue->array[queue->front]; }
	int FrontAndDequeue();
private:
	int Succ(int);  //private factory function

	QueueRecord* queue;
};

#endif // !_QUEUE_H

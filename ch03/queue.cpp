#include"Queue.h"
#include<stdexcept>
#include<algorithm>

Queue::Queue(int max)
{
	queue = new QueueRecord(max);
}

Queue::Queue(const Queue &q)
{
	queue = new QueueRecord(q.queue->capacity);
	queue->front = q.queue->front;
	queue->rear = q.queue->rear;
	queue->size = q.queue->size;
	std::copy(q.queue->array, q.queue->array + q.queue->capacity, queue->array);
}

Queue& Queue::operator=(Queue q)
{
	using std::swap;
	swap(queue, q.queue);
	return *this;
}

Queue::~Queue()
{
	delete queue->array;
	delete queue;
}

void Queue::MakeEmpty()
{
	queue->size = 0;
	queue->front = 1;
	queue->rear = 0;
}

int Queue::Succ(int position)
{
	if (++position == queue->capacity)
		position = 0;
	return position;
}

void Queue::Enqueue(int x)
{
	if (IsFull())
		throw std::runtime_error("Full queue");
	queue->rear = Succ(queue->rear);
	queue->array[queue->rear] = x;
	queue->size++;
}

void Queue::Dequeue()
{
	queue->front = Succ(queue->front);
	queue->size--;
}

int Queue::Front() const
{
	if (!IsEmpty())
		return queue->array[queue->front];
	throw std::runtime_error("Empty queue");
	return 0;
}

int Queue::FrontAndDequeue()
{
	int value = Front();
	Dequeue();
	return value;
}

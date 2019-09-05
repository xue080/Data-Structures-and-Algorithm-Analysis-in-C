#include"queue_list.h"
#include<algorithm>
#include<stdexcept>

Queue::Queue(const Queue& q):size(q.size)
{
	Node* to_copy = q.head;
	Node* p = head;
	while (to_copy->next) {
		p->next = new Node(to_copy->next->data);
		to_copy = to_copy->next;
		p = p->next;
	}
	if (!q.IsEmpty()) {
		front = head->next;
		rear = p;
	}
	else
		front = rear = nullptr;
}

Queue& Queue::operator=(Queue q)
{
	std::swap(head, q.head);
	std::swap(front, q.front);
	std::swap(rear, q.rear);
	std::swap(size, q.size);
	return *this;
}

Queue::~Queue()
{
	MakeEmpty();
	delete head;
}

void Queue::MakeEmpty()
{
	Node* p = head;
	while (p->next) {
		Node* the_next = p->next->next;
		delete p->next;
		p->next = the_next;
	}
	front = rear = nullptr;
	size = 0;
}

void Queue::Enqueue(int x)
{
	Node* p = new Node(x);
	if (IsEmpty()) {
		head->next = front = rear = p;
	} else {
		rear->next = p;
		rear = rear->next;
	}
	size++;
}

void Queue::Dequeue()
{
	if (IsEmpty())
		throw std::runtime_error("Empty queue");
	if (front == rear) {
		delete front;
		head->next = front = rear = nullptr;
	} else {
		Node* the_next = front->next;
		delete front;
		head->next = front = the_next;
	}
	size--;
}

int Queue::Front() const
{
	if (!IsEmpty())
		return front->data;
	throw std::runtime_error("Empty queue");
	return 0;
}

int Queue::FrontAndDequeue()
{
	int value = Front();
	Dequeue();
	return value;
}

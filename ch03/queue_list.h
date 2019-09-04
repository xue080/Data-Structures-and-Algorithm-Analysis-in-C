#ifndef _QUEUE_LIST_H
#define _QUEUE_LIST_H

#include<iostream>

struct Node
{
	Node() :data(0), next(nullptr) {}
	Node(int element) :data(element), next(nullptr) {}

	int data;
	Node* next;
};

class Queue {
	friend std::istream& operator>>(std::istream&, Queue&);
	friend std::ostream& operator<<(std::ostream&, const Queue&);
public:
	Queue() :size(0) {}
	Queue(const Queue&);
	Queue& operator=(Queue);
	~Queue();

	bool IsEmpty() const { return size == 0; }
	void MakeEmpty();
	void Enqueue(int x);
	void Dequeue();
	int Front() const;
	int FrontAndDequeue();

private:
	Node* head = new Node;
	int size;
};

#endif // !_QUEUE_LIST_H

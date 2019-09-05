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
public:
	Queue() :front(nullptr), rear(nullptr), size(0) {}
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
	Node* front;
	Node* rear;
	int size;
};

#endif // !_QUEUE_LIST_H

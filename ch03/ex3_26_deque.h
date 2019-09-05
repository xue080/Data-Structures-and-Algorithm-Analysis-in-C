#ifndef _DEQUE_H
#define _DEQUE_H

struct Node
{
	Node() :data(0), pre(nullptr), next(nullptr) {}
	Node(int element) :data(element), pre(nullptr), next(nullptr) {}

	int data;
	Node* pre;
	Node* next;
};

class Deque {
public:
	Deque() :front(nullptr), rear(nullptr), size(0) {}
	Deque(const Deque&);
	Deque& operator=(Deque);
	~Deque();

	bool IsEmpty() const { return size == 0; }
	void MakeEmpty();
	void Push(int);
	int Pop();
	void Inject(int);
	int Eject();

private:
	Node* head = new Node;
	Node* front;
	Node* rear;
	int size;
};

#endif // !_DEQUE_H

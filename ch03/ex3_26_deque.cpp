#include"deque.h"
#include<stdexcept>
#include<algorithm>

Deque::Deque(const Deque& d):size(d.size)
{
	Node* to_copy = d.head;
	Node* p = head;
	while (to_copy->next) {
		Node* temp = p;
		p->next = new Node(to_copy->next->data);
		to_copy = to_copy->next;
		p = p->next;
		p->pre = temp;
	}
	if (!d.IsEmpty()) {
		front = head->next;
		rear = p;
	}
	else
		front = rear = nullptr;
}

Deque& Deque::operator=(Deque d)
{
	std::swap(head, d.head);
	std::swap(front, d.front);
	std::swap(rear, d.rear);
	std::swap(size, d.size);
	return *this;
}

Deque::~Deque()
{
	MakeEmpty();
	delete head;
}

void Deque::MakeEmpty()
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

void Deque::Push(int x)
{
	Node* p = new Node(x);
	if (IsEmpty()) {
		head->next = front = rear = p;
		p->pre = head;
	} else {
		Node* the_next = front;
		head->next = front = p;
		p->next = the_next;
		p->pre = head;
		the_next->pre = p;
	}
	size++;
}

int Deque::Pop()
{
	if (!IsEmpty()) {
		int value = front->data;
		if (front == rear) {
			delete front;
			head->next = front = rear = nullptr;
		} else {
			Node* the_next = front->next;
			delete front;
			head->next = front = the_next;
			the_next->pre = head;
		}
		size--;
		return value;
	} else {
		throw std::runtime_error("Empty deque");
		return 0;
	}
	
}

void Deque::Inject(int x)
{
	Node* p = new Node(x);
	if (IsEmpty()) {
		head->next = front = rear = p;
		p->pre = head;
	} else {
		Node* temp = rear;
		rear->next = p;
		rear = rear->next;
		p->pre = temp;
	}
	size++;
}

int Deque::Eject()
{
	if (!IsEmpty()) {
		int value = rear->data;
		if (front == rear) {
			delete rear;
			head->next = front = rear = nullptr;
		}
		else {
			Node* the_pre = rear->pre;
			delete rear;
			rear = the_pre;
			rear->next = nullptr;
		}
		size--;
		return value;
	} else {
		throw std::runtime_error("Empty deque");
		return 0;
	}
}

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
}

Queue& Queue::operator=(Queue q)
{
	std::swap(head, q.head);
	std::swap(size, q.size);
	return *this;
}

Queue::~Queue()
{
	MakeEmpty();
}

void Queue::MakeEmpty()
{
	Node* p = head;
	while (p->next) {
		Node* the_next = p->next->next;
		delete p->next;
		p->next = the_next;
	}
	size = 0;
}

void Queue::Enqueue(int x)
{
	Node* p = head;
	while (p->next)
		p = p->next;
	p->next = new Node(x);
	size++;
}

void Queue::Dequeue()
{
	if (IsEmpty())
		throw std::runtime_error("Empty queue");
	Node* p = head;
	Node* the_next = p->next->next;
	delete p->next;
	p->next = the_next;
	size--;
}

int Queue::Front() const
{
	if (!IsEmpty())
		return head->next->data;
	throw std::runtime_error("Empty queue");
	return 0;
}

int Queue::FrontAndDequeue()
{
	int value = Front();
	Dequeue();
	return value;
}

std::istream& operator>>(std::istream &is, Queue &q)
{
	int x;
	size_t cnt = 0;
	while (is >> x) {
		cnt++;
		q.Enqueue(x);
	}
	q.size = cnt;
	return is;
}

std::ostream& operator<<(std::ostream &os, const Queue &q)
{
	Node* p = q.head;
	while (p->next) {
		os << p->next->data << " ";
		p = p->next;
	}
	return os;
}

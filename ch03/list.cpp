#include"List.h"
#include<algorithm>

LinkedList::LinkedList(const LinkedList &source)
{
	Node* to_copy = source.head;
	Node* dest = head;
	while (to_copy->next) {
		dest->next = new Node(to_copy->next->data);
		to_copy = to_copy->next;
		dest = dest->next;
	}
	count = source.count;
}

LinkedList& LinkedList::operator=(LinkedList source)
{
	std::swap(head, source.head);
	std::swap(count, source.count);
	return *this;
}

LinkedList::~LinkedList()
{
	DeleteList();
}

Node* LinkedList::Find(int x)
{
	Node* p = First();
	while (p != nullptr && p->data != x)
		p = p->next;
	return p;
}
Node* LinkedList::Find(int x, Node* p)
{
	if (p != nullptr && p->data != x)
		Find(x, p->next);
	return p;
}

Node* LinkedList::FindPrevious(int x)
{
	Node* p = head;
	while (p->next != nullptr && p->next->data != x)
		p = p->next;
	return p;
}

void LinkedList::Insert(int x, Node* p)
{
	Node* obj = new Node(x);
	Node* next_p = p->next;
	p->next = obj;
	obj->next = next_p;
	count++;
}

void LinkedList::Delete(int x)
{
	Node* previous_p = FindPrevious(x);
	if (!IsLast(previous_p)) {  //x is not found if false 
		Node* p = previous_p->next;
		previous_p->next = p->next;
		delete p;
		count--;
	}
}

void LinkedList::DeleteList()
{
	Node* p = head->next;
	head->next = nullptr;  //very important!!!
	while (p) {
		Node* temp = p->next;
		delete p;
		p = temp;
	}
	count = 0;
}

LinkedList& LinkedList::MakeEmpty()
{
	DeleteList();
	return *this;
}

std::istream& operator>>(std::istream &is, LinkedList &list)
{
	int x;
	size_t cnt = 0;
	Node* p = list.head;
	while (is >> x) {
		cnt++;
		list.Insert(x, p);
		p = p->next;
	}
	list.count = cnt;
	return is;
}

std::ostream& operator<<(std::ostream &os, const LinkedList &list)
{
	Node* p = list.head;
	while (p->next) {
		os << p->next->data << " ";
		p = p->next;
	}
	os << std::endl;
	os << "count = " << list.count;
	return os;
}

void LinkedList::Reverse()
{
	Node* pre = nullptr;
	Node* cur = First();
	Node* the_next = cur->next;
	while (cur) {
		cur->next = pre;
		pre = cur;
		cur = the_next;
		if(the_next)
			the_next = the_next->next;
	}
	head->next = pre;
}

void LinkedList::RemoveDup()
{
	for (Node* p = First(); !IsLast(p); p = p->next) {
		Node* q = p->next;
		while (q) {
			if (q->data == p->data) {
				Node* temp = q->next;
				delete q;
				q = temp;
				p->next = temp;  //need update p->next, otherwise it's a dangling pointer
				count--;    //update the number of elements
			}
			else
				q = q->next;
		}
	}
}

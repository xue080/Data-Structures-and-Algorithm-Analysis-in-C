#include"List.h"

Position Node::Find(int x)
{
	Position p = next;
	while (p != NULL && p->element != x)
		p = p->next;
	return p;
}

Position Node::FindPrevious(int x)
{
	Position p = this;
	while (p->next != NULL && p->next->element != x)
		p = p->next;
	return p;
}

void Node::Insert(int x, Position p)
{
	Position new_p = new Node;   //if fail to allocate storage, it will throw std::bad_alloc exception
	new_p->next = p->next;
	new_p->element = x;
	p->next = new_p;
}

void Node::Delete(int x)
{
	Position previous_p = FindPrevious(x);
	if (!IsLast(previous_p)) {
		Position p = previous_p->next;
		previous_p->next = p->next;
		delete p;
	}
}

void Node::DeleteList()
{
	while (next != NULL) {
		Position temp = next->next;
		delete next;
		next = temp;
	}
}

List Node::MakeEmpty()
{
	DeleteList();
	return this;
}

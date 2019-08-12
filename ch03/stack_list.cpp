#include"stack_list.h"

Stack::Stack(const Stack &stack)
{
	Node* to_copy = stack.head;
	Node* dest = head;
	while (to_copy->next) {
		dest->next = new Node(to_copy->next->data);
		to_copy = to_copy->next;
		dest = dest->next;
	}
}

Stack& Stack::operator=(Stack stack)
{
	std::swap(head, stack.head);
	return *this;
}

Stack::~Stack()
{
	MakeEmpty();
}

int Stack::Top() const
{
	if (!IsEmpty())
		return head->next->data;
	throw std::runtime_error("Empty Stack");
	return 0;
}

void Stack::Push(int item)
{
	Node* the_next = head->next;
	Node* p = new Node(item);
	head->next = p;
	p->next = the_next;
}

void Stack::Pop()
{
	if (IsEmpty()) {
		throw std::runtime_error("Empty Stack");
	} else {
		Node* first = head->next;
		head->next = head->next->next;
		delete first;
	}
}

void Stack::MakeEmpty()
{
	while(!IsEmpty()) {
		Pop();
	}
}

std::istream& operator>>(std::istream &is, Stack &stack)
{	
	int item;
	while (is >> item) {
		stack.Push(item);
	}
	return is;
}

std::ostream& operator<<(std::ostream &os, Stack stack) 
{
	while (!stack.IsEmpty()) {
		os << stack.Top() << " ";
		stack.Pop();
	}
	return os;
}

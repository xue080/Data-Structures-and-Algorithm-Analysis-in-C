#ifndef _STACK_LIST_H
#define _STACK_LIST_H

#include<iostream>

class Node {
public:
	Node() :data(0), next(nullptr) {}
	Node(int item) :data(item), next(nullptr) {}
	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete;

	int data;
	Node* next;
};

class Stack {
	friend std::istream& operator>>(std::istream&, Stack&);      // I/O is just for test
	friend std::ostream& operator<<(std::ostream&, Stack);
public:
	Stack() = default;
	Stack(const Stack&);
	Stack& operator=(Stack);
	~Stack();

	bool IsEmpty() const { return head->next == nullptr; }
	void MakeEmpty();
	void Push(int);
	int Top() const;
	void Pop();

private:
	Node* head = new Node;   //dummy node
};


#endif // !_STACK_LIST_H

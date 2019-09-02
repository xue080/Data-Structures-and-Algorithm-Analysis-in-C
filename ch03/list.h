//To simplify matters,
//we assume that the elements in the list are integers.

#ifndef _LIST_H
#define _LIST_H

#include<iostream>

struct Node {        
	Node() :data(0), deleted(false), next(nullptr) {}
	Node(int item) :data(item), deleted(false), next(nullptr) {}
			//Not to copy single node. Let the class 'LinkedList' do the job.
	Node(const Node&) = delete;  
	Node& operator=(const Node&) = delete;

	int data;
	bool deleted;  //for lazy deletion
	Node* next;
};

class LinkedList {
	friend std::istream& operator>>(std::istream&, LinkedList&);
	friend std::ostream& operator<<(std::ostream&, const LinkedList&);
public: 
	LinkedList() : count(0), de_count(0), no_de_count(0) {}
	LinkedList(const LinkedList&);    //with rule of 3
	LinkedList& operator=(LinkedList);
	~LinkedList();
	
	bool IsEmpty() const { return head->next == nullptr; }
	bool IsLast(Node *p) const { return p->next == nullptr; }
	size_t Size() const { return count; }
	Node* Header() { return head; }
	Node* First() const { return head->next; }
	Node* Advance(const Node *p) const { return p->next; }  //return next Node*
	int Restrieve(Node *p) const { return p->data; }

	void Reverse();
	void RemoveDup();
	Node* Find(int);   //return nullptr if not found
	Node* Find(int, Node*);
	Node* FindPrevious(int); //return the last element if not found
	void Insert(int, Node*); //insert an element after designated Node
	void LazyDelete(int);
	void Delete(int);
	void DeleteList();
	LinkedList& MakeEmpty();

private: 
	Node* head = new Node;   //note that it's a dummy node(also called header) !!!
	size_t count;  //the number of Nodes
	size_t de_count;   //the number of being deleted for lazy deletion
	size_t no_de_count;  //the number of not being deleted for lazy deletion
};

#endif // !_LIST_H

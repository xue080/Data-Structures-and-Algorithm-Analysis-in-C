#ifndef _LIST_H
#define _LIST_H

#include<cstddef>

class Node;
using PtrToNode = Node*;
using  List = PtrToNode;
using  Position = PtrToNode;

class Node {
public:
	List MakeEmpty();
	bool IsEmpty() const { return next == NULL; }
	bool IsLast(Position p) const { return p->next == NULL; }
	Position Find(int);
	void Delete(int);
	Position FindPrevious(int);
	void Insert(int, Position);
	void DeleteList();
	Position Header() { return this; }
	Position First() const { return next; };
	int Retrieve(Position p) const { return p->element; };
private:
	int element;
	Position next;
};

#endif // !_LIST_H

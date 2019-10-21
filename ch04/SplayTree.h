#ifndef _SPLAYTREE_H
#define _SPLAYTREE_H

#include<iostream>

#define ElemType int

using Position = struct SplayNode*;
using Tree = Position;

struct SplayNode {
	SplayNode() :data(0), parent(nullptr), left(nullptr), right(nullptr) {}
	SplayNode(Position par, ElemType elem) :
		data(elem), parent(par), left(nullptr), right(nullptr) {}

	ElemType data;
	Position parent;  //point to parent node
	Tree left;    //point to right subtree
	Tree right;   //point to right subtree
};

class SplayTree {
	friend std::istream& operator>>(std::istream&, SplayTree&);
	friend std::ostream& operator<<(std::ostream&, const SplayTree&);
public:
	SplayTree() :root(nullptr) {}
	SplayTree(const SplayTree&);
	SplayTree& operator=(SplayTree);
	~SplayTree();

	bool IsEmpty() const { return root == nullptr; }
	void MakeEmpty();
	bool Find(ElemType);
	ElemType Min();
	ElemType Max();
	Tree Insert(ElemType);
	void Delete(ElemType);
private:
	Tree root;

	//all factory functions below
	void Copy(Tree, Tree&, Position);  //for copy constructor
	void Print(std::ostream&, const Tree&) const;  //for operator<<

	void SingleRotateWithLeft(Position);   
	void SingleRotateWithRight(Position);
	void ZigZagRotateWithLeft(Position);
	void ZigZagRotateWithRight(Position);
	void ZigZigRotateWithLeft(Position);
	void ZigZigRotateWithRight(Position);

	void MakeEmpty(Tree&);
	void Splay(Position);
	Position Find(ElemType, Tree);
	Position FindMin(Tree);
	Position FindMax(Tree);
	Tree Insert(ElemType, Tree&, Position);
};

#endif // !_SPLAYTREE_H
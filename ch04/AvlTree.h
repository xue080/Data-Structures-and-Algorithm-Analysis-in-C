//To simplify matters,
//we assume that the elements in the tree are integers.

#ifndef _AVLTREE_H
#define _AVLTREE_H

#include<iostream>

using Position = struct AvlNode*;
using Tree = struct AvlNode*;

struct AvlNode {
	AvlNode() :data(0), left(nullptr), right(nullptr), height(0) {}
	AvlNode(int elem) :data(elem), left(nullptr), right(nullptr), height(0) {}

	int data;
	Tree left;   //point to left subtree
	Tree right;  //point to right subtree
	int height;
};

class AvlTree {
	friend std::istream& operator>>(std::istream&, AvlTree&);
	friend std::ostream& operator<<(std::ostream&, const AvlTree&);
public:
	AvlTree() :root(nullptr) {}
	AvlTree(const AvlTree&);   //the rule of three
	AvlTree& operator=(AvlTree);
	~AvlTree(); 

	bool IsEmpty() const { return root == nullptr; }
	int Height(Position p) const { return p ? p->height : -1; }
	void MakeEmpty();
	Position Find(int);
	int Min();
	int Max();
	Tree Insert(int);
	Tree Delete(int);
	int Retrieve(Position);
	Tree GenMinTree(int);
private:
	Tree root;
	//all factory functions below
	void Copy(Tree, Tree&);  //for copy constructor
	void Print(std::ostream&, const Tree&) const;
	//for Insert and Delete operation, return new root after rotation   
	Position SingleRotateWithLeft(Position);  
	Position SingleRotateWithRight(Position);
	Position DoubleRotateWithLeft(Position);
	Position DoubleRotateWithRight(Position);

	void MakeEmpty(Tree&);
	Position Find(int,Tree);
	Position FindMin(Tree);
	Position FindMax(Tree);
	Tree Insert(int,Tree);
	Tree Delete(int,Tree);
	Tree GenMinTree(int, int&);
};

#endif // !_AVLTREE_H
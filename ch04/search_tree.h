#ifndef _SEARCH_TREE_H
#define _SEARCH_TREE_H

#include<iostream>

using Position = struct TreeNode*;
using Tree = struct TreeNode*;

struct TreeNode {
	TreeNode() :data(0), left(nullptr), right(nullptr) {}
	TreeNode(int elem) :data(elem), left(nullptr), right(nullptr) {}

	int data;
	TreeNode* left;   //point to left subtree
	TreeNode* right;  //point to right subtree
};

class SearchTree {
	friend std::istream& operator>>(std::istream&, SearchTree&);
	friend std::ostream& operator<<(std::ostream&, const SearchTree&);
public:
	SearchTree() :root(nullptr) {}
	SearchTree(const SearchTree&);   //the rule of three
	SearchTree& operator=(SearchTree);
	~SearchTree();

	bool IsEmpty() const { return root == nullptr; }
	void MakeEmpty();
	Position Find(int);
	int Min();     //raise error if empty
	int Max();     //raise error if empty
	Tree Insert(int);  //returns a pointer to the root of the new tree
	Tree Delete(int);  //returns a pointer to the root of the new tree
	int Retrieve(Position);
	void MakeRandomSearchTree(int N);
	void PerfectTree(int);
	void PrintRange(int, int);
private:
	Tree root;   //point to the root of the search tree

	//factory functions
	void Copy(Tree,Tree&);  //used for copy constructor
	void MakeEmpty(Tree&);  
	Position Find(int, Tree);
	Position FindMin(Tree);  
	Position FindMax(Tree);
	Tree Insert(int, Tree);
	Tree Delete(int, Tree);
	void Print(std::ostream&, const Tree&) const;  //used for operator<<

	Tree MakeRandomSearchTree(int lower, int upper);
	Tree PerfectTree(int lower, int upper);
	void PrintRange(Tree, int, int);
};

#endif // !_SEARCH_TREE_H
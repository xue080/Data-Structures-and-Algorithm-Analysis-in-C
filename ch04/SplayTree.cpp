#include"SplayTree.h"
#include<stdexcept>

void SplayTree::Copy(Tree to_copy, Tree& dest, Position parent)
{
	if (to_copy) {
		dest = new SplayNode(parent, to_copy->data);
		Copy(to_copy->left, dest->left, dest);
		Copy(to_copy->right, dest->right, dest);
	} else {
        dest = nullptr;    //without this line, when to_copy is nullptr, dest is undefined
    }
}

SplayTree::SplayTree(const SplayTree& t)
{
	Copy(t.root, root, nullptr);
}

SplayTree& SplayTree::operator=(SplayTree t)
{
	std::swap(root, t.root);
	return *this;
}

void SplayTree::MakeEmpty(Tree& root)
{
	if (root) {
		MakeEmpty(root->left);
		MakeEmpty(root->right);
		delete root;
		root = nullptr;
	}
}

void SplayTree::MakeEmpty()
{
	MakeEmpty(root);
}

SplayTree::~SplayTree()
{
	MakeEmpty(root);
}

void SplayTree::SingleRotateWithLeft(Position node)
{
	Position parent = node->parent;
	Position grandparent = parent->parent;
	parent->left = node->right;
	if (node->right)      //remember to update parent pointer
		node->right->parent = parent;
	node->right = parent;
	parent->parent = node;
	node->parent = grandparent;
	if (grandparent) {
		if (grandparent->left == parent) 
			grandparent->left = node;
		else
			grandparent->right = node;
	}
	else {
		root = node;
		node->parent = nullptr;
	}
}

void SplayTree::SingleRotateWithRight(Position node)
{
	Position parent = node->parent;
	Position grandparent = parent->parent;
	parent->right = node->left;
	if (node->left)
		node->left->parent = parent;
	node->left = parent;
	parent->parent = node;
	node->parent = grandparent;
	if (grandparent) {
		if (grandparent->left == parent) 
			grandparent->left = node;
		else 
			grandparent->right = node;
	} else {
		root = node;
		node->parent = nullptr;
	}
}

void SplayTree::ZigZagRotateWithLeft(Position node)
{
	SingleRotateWithRight(node);
	SingleRotateWithLeft(node);
}

void SplayTree::ZigZagRotateWithRight(Position node)
{
	SingleRotateWithLeft(node);
	SingleRotateWithRight(node);
}

void SplayTree::ZigZigRotateWithLeft(Position node)
{
	SingleRotateWithLeft(node->parent);
	SingleRotateWithLeft(node);
}

void SplayTree::ZigZigRotateWithRight(Position node)
{
	SingleRotateWithRight(node->parent);
	SingleRotateWithRight(node);
}

void SplayTree::Splay(Position node)   
{
	while (root->left != node && root->right != node && root != node) {  //rotate until node is root
		Position parent = node->parent;                                 //or root's child
		Position grandparent = parent->parent;
		bool left1 = (grandparent->left == parent ? true : false);
		bool left2 = (parent->left == node ? true : false);
		if (left1 && left2)
			ZigZigRotateWithLeft(node);
		else if (left1 && !left2) 
			ZigZagRotateWithLeft(node);
		else if (!left1&& left2)
			ZigZagRotateWithRight(node);
		else
			ZigZigRotateWithRight(node);     
	}
	if (root->left == node)
		SingleRotateWithLeft(node);
	else if(root->right == node)
		SingleRotateWithRight(node);
}

Position SplayTree::Find(ElemType x, Tree t)    //return the position of the target element
{
	if (t == nullptr)
		return nullptr;
	else if (x < t->data)
		return Find(x, t->left);
	else if (x > t->data)
		return Find(x, t->right);
	else
		return t;
}

bool SplayTree::Find(ElemType x)
{
	Position node = Find(x, root);
	if (node == nullptr)
		return false;
	else if (node == root)
		return true;
	else {
		Splay(node);
		return true;
	}
}

Position SplayTree::FindMin(Tree t)
{
	if (t == nullptr)
		return nullptr;
	else if (t->left == nullptr) 
		return t;
	else
		return FindMin(t->left);
}

ElemType SplayTree::Min()
{
	if (!IsEmpty()) {
		Splay(FindMin(root));
		return root->data;
	}
	throw std::runtime_error("Empty SplayTree");
	return 0;
}

Position SplayTree::FindMax(Tree t)
{
	if (t == nullptr)
		return nullptr;
	else if (t->right == nullptr)
		return t;
	else
		return FindMax(t->right);
}

ElemType SplayTree::Max()
{
	if (!IsEmpty()) {
		Splay(FindMax(root));
		return root->data;
	}
	throw std::runtime_error("Empty SplayTree");
	return 0;
}

Tree SplayTree::Insert(ElemType x, Tree& root, Position parent)
{
	if (root == nullptr)
		root = new SplayNode(parent, x);
	else if (x < root->data)
		root->left = Insert(x, root->left, root);
	else if (x > root->data)
		root->right = Insert(x, root->right, root);
	return root;
}

Tree SplayTree::Insert(ElemType x)
{
	root = Insert(x, root, nullptr);
	return root;
}

void SplayTree::Delete(ElemType x)
{	
	if (Find(x)) {   //then root->data == x
		Position left = root->left;
		Position right = root->right;
		delete root;
		root = left;     //replace it with maximum in left subtree
		left->parent = right->parent = nullptr;
		Splay(FindMax(left));
		left->right = right;  
		right->parent = left;
	}
}

std::istream& operator>>(std::istream& is, SplayTree& t)
{
	int elem;
	while (is >> elem)
		t.Insert(elem);
	return is;
}

std::ostream& operator<<(std::ostream& os, const SplayTree& t)
{
	t.Print(os, t.root);
	return os;
}

void SplayTree::Print(std::ostream& os, const Tree& root) const
{
	if (root) {
		os << root->data << " ";
		Print(os, root->left);
		Print(os, root->right);
	}
}

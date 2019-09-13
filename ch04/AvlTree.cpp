#include"AvlTree.h"
#include<stdexcept>
#include<algorithm>

AvlTree::AvlTree(const AvlTree& t)
{
	Copy(t.root, root);
}

AvlTree& AvlTree::operator=(AvlTree t)
{
	std::swap(root, t.root);
	return *this;
}

AvlTree::~AvlTree()
{
	MakeEmpty();
}

void AvlTree::Copy(Tree to_copy, Tree& dest)
{
	if (to_copy) {
		dest = new AvlNode(to_copy->data);
		Copy(to_copy->left, dest->left);
		Copy(to_copy->right, dest->right);
	}
}

void AvlTree::MakeEmpty()
{
	MakeEmpty(root);
}

void AvlTree::MakeEmpty(Tree& root)
{
	if (root) {
		MakeEmpty(root->left);
		MakeEmpty(root->right);
		delete root;
		root = nullptr;
	}

}

Position AvlTree::Find(int x)
{
	return Find(x, root);
}

Position AvlTree::Find(int x, Tree root)
{
	if (root == nullptr)
		return nullptr;
	else if (x < root->data)
		return Find(x, root->left);
	else if (x > root->data)
		return Find(x, root->right);
	else
		return root;
}

int AvlTree::Max()
{
	if(!IsEmpty())
		return FindMax(root)->data;
	throw std::runtime_error("Empty AvlTree");
	return 0; 
}

Position AvlTree::FindMax(Tree root)
{
	if (root == nullptr)
		return nullptr;
	else if (root->right == nullptr)
		return root;
	else
		return FindMax(root->right);
}

int AvlTree::Min()
{
	if (!IsEmpty())
		return FindMin(root)->data;
	throw std::runtime_error("Empty AvlTree");
	return 0;
}

Position AvlTree::FindMin(Tree root)
{
	if (root == nullptr)
		return nullptr;
	else if (root->left == nullptr)
		return root;
	else
		return FindMin(root->left);
}

Tree AvlTree::Insert(int x)
{
	root = Insert(x, root);
	return root;
}

Tree AvlTree::Insert(int x, Tree root)
{
	if (root == nullptr)
		root = new AvlNode(x);
	else if (x < root->data) {
		root->left = Insert(x, root->left);
		if (Height(root->left) - Height(root->right) == 2) {
			if (x < root->left->data)
				root = SingleRotateWithLeft(root);
			else
				root = DoubleRatateWithLeft(root);
		}
	}
	else if (x > root->data) {
		root->right = Insert(x, root->right);
		if (Height(root->right) - Height(root->left) == 2) {
			if (x > root->right->data)
				root = SingleRotateWithRight(root);
			else
				root = DoubleRatateWithRight(root);
		}
	}
	//else x is in the tree already, we'll do nothing
	//we still need update the height of root,
	//because we just update it when not balanced above
	root->height = std::max(Height(root->left), Height(root->right)) + 1; 
	return root;
}

Position AvlTree::SingleRotateWithLeft(Position k2)
{
	Position k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = std::max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = std::max(Height(k1->left), Height(k2)) + 1;
	return k1;   
}

Position AvlTree::SingleRotateWithRight(Position k2)
{
	Position k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = std::max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = std::max(Height(k2), Height(k1->right)) + 1;
	return k1;
}

Position AvlTree::DoubleRatateWithLeft(Position k3)
{
	k3->left = SingleRotateWithRight(k3->left);
	return SingleRotateWithLeft(k3);
}

Position AvlTree::DoubleRatateWithRight(Position k3)
{
	k3->right = SingleRotateWithLeft(k3->right);
	return SingleRotateWithRight(k3);
}

Tree AvlTree::Delete(int x)
{
	root = Delete(x, root);
	return root;
}

Tree AvlTree::Delete(int x, Tree root)
{
	if (root == nullptr)
		throw std::runtime_error("Data not found");
	else if (x < root->data) {
		root->left = Delete(x, root->left);
		if (Height(root->right) - Height(root->left) == 2) {
			if (x < root->left->data)
				root = DoubleRatateWithLeft(root);
			else
				root = SingleRotateWithLeft(root);
		}
	}
	else if (x > root->data) {
		root->right = Delete(x, root->right);
		if (Height(root->left) - Height(root->right) == 2) {
			if (x > root->right->data)
				root = DoubleRatateWithRight(root);
			else
				root = SingleRotateWithRight(root);
		}
	}
	//if x is equal to root->data, then this is the	node to be deleted
	else if (root->left && root->right) {  //have two children
		Position temp = FindMin(root->right);
		root->data = temp->data;
		root->right = Delete(root->data, root->right);
	}
	else {   //have one or zero child 
		Position temp = root;
		if (root->left == nullptr)
			root = root->right;
		else if (root->right == nullptr)
			root = root->left;
		delete temp;
	}
	if(root)
		root->height = std::max(Height(root->left), Height(root->right)) + 1;
	return root;
}

int AvlTree::Retrieve(Position p)
{
	if (p)
		return p->data;
	throw std::runtime_error("Null pointer");
	return 0;
}

std::istream& operator>>(std::istream& is, AvlTree& t)
{
	int elem;
	while (is >> elem)
		t.Insert(elem);
	return is;
}

std::ostream& operator<<(std::ostream& os, const AvlTree& t)
{
	t.Print(os,t.root);
	return os;
}

void AvlTree::Print(std::ostream& os, const Tree& root) const
{
	if (root) {
		os << root->data << " ";
		Print(os, root->left);
		Print(os, root->right);
	}
}
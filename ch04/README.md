# Chapter 4: Trees

## 4.3 : Implementation of Binary Search Tree

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree_test.cpp)

## 4.4 : Implementation of AVL Tree

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree_test.cpp)

***

## Exercise 4.1

**a. Root node**  
A

**b. Leaves nodes**   
G H I L M K

## Exercise 4.2

There are too many nodes, so just give an example of node `E`.

**a. Parent node**  
B 

**b. Children**  
I J 

**c. Sibling(s)**   
D 

**d. Depth**  
2

**e. Height**  
2

## Exercise 4.3

4

## Exercise 4.4

There are N nodes. Each node has two pointers to its children, so 2N pointers in total. In addition to the root, each root has one incoming pointer from its parent, which accounts for N - 1. As was mentioned above, the rest N + 1 pointers are nullptr.   

## Exercise 4.5

For each level of the binary tree, if its height is H, the max number of its nodes is 2^H. Sum all the nodes of the tree up—— 2^0 + 2^1 + ... + 2^H. It is a geometric progression, the result of which is 2^(H+1) - 1.

## Exercise 4.6

Let A = the number of all nodes, B = the number of full nodes, C = the number of nodes that have one child, L = the number of leaves. Obviously, A = B + C + L. Further, because each node but the root has one incoming pointer from its parent, 2B + C = A - 1. Subtracting yields L = B + 1.

##  Exercise 4.7

This can be shown by induction.  
(1)base case : In a tree with no nodes, the sum is zero, and in a one-node tree, the root is a leaf at depth zero, so the claim is true.  
(2)hypothesis : Suppose the theorem is true for all trees with at most *k* nodes.  
(3)for k + 1 nodes : The tree consists of an *i* nodes left subtree and a *k - i* nodes right subtree. So the sum for the left subtree leaves is at most one. Because all leaves are one deeper with respect to the original tree than with respect to the subtree, the sum is at most 1/2 with respect to the root. It's the same for leaves in the right subtree.
The equality is true if and only if there are no nodes with one child.

## Exercise 4.8

Prefix expression : - * * a b + c d e   
Infix expression : ((a * b) * (c + d)) - e  
Postfix expression : a b * c d + * e -

## Exercise 4.9

**a. The result of inserting nodes**  
![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_09_1.png?raw=true)

**b. The result of deleting root**  
![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_09_2.png?raw=true)

## Exercise 4.10 ~ 4.11

[4.3 Implementation](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/tree/master/ch04#43--implementation-of-binary-search-tree)

## Exercise 4.12

**a. Random insert**  
Repeatedly generate random integers until an unused one is found. If there are N elements already in the tree, then M - N are not, and the probability of finding one of these if (M - N) / M. So the expected number of trials is M / (M - N), which is α / (α - 1).

**b. Random delete**  
It is similar to question a. The probability of finding one is N / M. So the expected number of  trails is M / N, which is α.

**c. A good choice of α**  
From question a and b, we can learn that the whole running time of these two operations is α + α / (α - 1). Let the differentiation of it equals 0, then we can get α = 2.

## Exercise 4.13

**a. Replace with the largest node in left subtree**  

```c++
/*...*/
else if (root->left && root->right) {
	Position temp = FindMax(root->left);
	root->data = temp->data;
	root->left = Delete(root->data, root->left);
}
/*...*/
```

**b. Alternately**

```c++
/*...*/
else if (root->left && root->right) {
	Position temp;
	bool flag = true;
	if (flag) {
		temp = FindMax(root->left);
		root->data = temp->data;
		root->left = Delete(root->data, root->left);
		flag = false;
	} else {
		temp = FindMin(root->right);
		root->data = temp->data;
		root->right = Delete(root->data, root->right);
		flag = true;
	}
}
/*...*/
```

**c. Randomly**  

```c++
//Need include the headers <ctime> and <random>

/*...*/
int random_num(int min,int max)
{
	static std::default_random_engine e(time(NULL));
	static std::uniform_int_distribution<unsigned> u(min,max);
	return u(e);
}

else if (root->left && root->right) {
    Position temp;
    int choice = random_num(0,1);
    if(choice) {
        temp = FindMax(root->left);
		root->data = temp->data;
		root->left = Delete(root->data, root->left);
    } else {
        temp = FindMin(root->right);
		root->data = temp->data;
		root->right = Delete(root->data, root->right);
    }
}
/*...*/
```

Strategy b seems to give the most balance, and a takes the least CPU time.

## Exercise 4.14

The answer is in the book. `Section 4.3.6. Average-Case Analysis`

## Exercise 4.15

**a. Precise expression**  
N(0) = 1, N(1) = 2, N(H) = N(H-1) + N(H-2) + 1

**b. For height 15**  
N(H) = F(H+2) - 1

## Exercise 4.16

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_16.png?raw=true)

## Exercise 4.17

Can be verified by induction.

## Exercise 4.18 

[Check AVL Tree cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/README.md#44--implementation-of-avl-tree)

## Exercise 4.19

```c++
Tree AvlTree::Insert(int x, Tree root)
{
	Tree temp = root;
	std::stack<Tree> trees;  //use stack to collect the nodes on the path
	while (temp) {
		trees.push(temp);
		if (x < temp->data)
			temp = temp->left;
		else if (x > temp->data)
			temp = temp->right;
	}
	temp = new AvlNode(x);   //the place to insert
	Tree son = temp;  
	while (!trees.empty()) {  
		Tree father = trees.top();  
		if (son->data < father->data)   //each time connect the father node with its child node
			father->left = son;
		else
			father->right = son;
		if (son == father->left) {  //插在了左边
			if (Height(father->left) - Height(father->right) == 2) {
				if (x < father->left->data)
					father = SingleRotateWithLeft(father);
				else
					father = DoubleRatateWithLeft(father);
			}
		} else {  //插在右边
			if (Height(father->right) - Height(father->left) == 2) {
				if (x > father->right->data)
					father = SingleRotateWithRight(father);
				else
					father = DoubleRatateWithRight(father);
			}
		}
		father->height = std::max(Height(father->left), Height(father->right)) + 1;
		son = father;
		trees.pop();
	}
	return son;
}
```

## Exercise 4.20

[Check AVL Tree cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/README.md#44--implementation-of-avl-tree)

## Exercise 4.21

**a. The number of bits required per node**  
log log N

**b. The smallest AVL tree that overflows an 8-bit height counter**  
Let log log N = 8, then log N = 256, which means the height of the smallest AVL tree is 256. 

## Exercise 4.22

Just give the implementation of `DoubleRotateWithLeft ` . The another is mirror image of it.

```c++
Position AvlTree::DoubleRotateWithLeft(Position k3)
{
	Position k2 = k3->left;
	Position k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k3->left = k1->right;
	k1->right = k3;
	k2->height = std::max(Height(k2->left), Height(k2->right)) + 1;
	k3->height = std::max(Height(k3->left), Height(k3->right)) + 1;
	k1->height = std::max(Height(k2), Height(k3)) + 1;
	return k1;
}

```



## Exercise 4.23

After accessing 3 :

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_23_1.png?raw=true)

After accessing 9 :

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_23_2.png?raw=true)

After accessing 1 :

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_23_3.png?raw=true)

After accessing 5 :

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_23_4.png?raw=true)

## Exercise 4.24

After deleting 6 :

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex4_24.png?raw=true)

## Exercise 4.25

a. 523776

b. 262166, 133114, 68216, 36836, 21181, 13873

## Exercise 4.28

**a. The number of nodes in T**  

```c++
int CountNodes(TreeNode* T)
{
    if(T == nullptr)
        return 0;
    else
        return 1 + CountNodes(T->left) + CountNodes(T->right);
}
```

**b. The number of leaves in T**

```c++
int CountLeaves(TreeNode* T)
{
    if(T == nullptr)
        return 0;
    else if(T->left == nullptr && T->right == nullptr)
        return 1;
    else
        return CountLeaves(T->left) + CountLeaves(T->right);
}
```

**c. The number of full nodes in T**

```c++
int CountFullNodes(TreeNOde* T)
{
    if(T == nullptr)
        return 0;
    else if(T->left && T->right)
        return 1 + CountFullNodes(T->left) + CountFullNodes(T->right);
    else 
        return CountFullNodes(T->left) + CountFullNodes(T->right);
}
```

## Exercise 4.29

```c++
//Make it a member function of class SearchTree
//Need include headers <random> and <ctime>
int RandomInt(int lower, int upper)
{
	std::default_random_engine e(time(NULL));
	std::uniform_int_distribution<unsigned> u(lower, upper);
	return u(e);
}

Tree SearchTree::MakeRandomSearchTree(int lower, int upper)
{
	Tree root = nullptr;
	int value;
	if (lower <= upper) {
		value = RandomInt(lower, upper);
		root = new TreeNode(value);
		root->left = MakeRandomSearchTree(lower, value - 1);
		root->right = MakeRandomSearchTree(value + 1, upper);
	}
	return root;
}

SearchTree SearchTree::MakeRandomSearchTree(int N)
{
	root = MakeRandomSearchTree(1, N);
	return *this;
}

//in test.cpp:
//	SearchTree t;
//	int N;
//	cin >> N;
//	t.MakeRandomSearchTree(N);
//	cout << t << std::endl;
```

The running time is O(log N).


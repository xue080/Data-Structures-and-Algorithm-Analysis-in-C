# Chapter 4: Trees

## 4.3 : Implementation of Binary Search Tree

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree_test.cpp)

## 4.4 : Implementation of AVL Tree

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree_test.cpp)

***

## Exercise 4.1

**a. root node  **  
A

**b. leaves nodes**   
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

Let A = the number of all nodes, B = the number of full nodes, C = the number of nodes that have one child, L = the number of leaves. Obviously, A = B + C + L. Further, because each node but the root has one incoming pointer from its parent, 2B + C = A. Subtracting yields L - F = 1.

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


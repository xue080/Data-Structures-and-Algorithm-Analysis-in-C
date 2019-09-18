# Chapter 4: Trees

## 4.3 : Implementation of Binary Search Tree

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/search_tree_test.cpp)

## 4.4 : Implementation of AVL Tree

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch04/AvlTree_test.cpp)

***

## Exercise 4.1

a. A
b. G H I L M K

## Exercise 4.2

There are too many nodes, so just give an example of node E as follows.

a. B
b. I J
c. D
d. 2
e. 2

## Exercise 4.3

4

## Exercise 4.4

There are N nodes. Each node has two pointers to its children, so 2N pointers in total. In addition to the root, each root has one incoming pointer from its parent, which accounts for N - 1. As was mentioned above, the rest N + 1 pointers are nullptr.




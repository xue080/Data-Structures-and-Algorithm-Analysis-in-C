# Chapter 3: Lists, Stacks and Queues

## 3.2.2 Exercise : Implementation of List

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/list.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/list.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/list_test.cpp)

## 3.2.7 Exercise : The Polynomial ADT 
Array Version : [hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/polynomial_array.h)  [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/polynomial_array.cpp)  [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/polynomial_array_test.cpp)  
List Version : [hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/polynomial_list.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/polynomial_list.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/polynomial_list_test.cpp)

## 3.3.1 Exercise : Implementation of Stack

List Version : [hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/stack_list.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/stack_list.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/stack_list_test.cpp)  
Array Version : [hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/stack_array.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/stack_array.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/stack_array_test.cpp)

## 3.3.3 Exercise : Infix to Postfix Conversion

[Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/infix_to_postfix.cpp)(include exponentiation)

## 3.4.2 Exercise : Implementation of Queue

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue_test.cpp)

***


## Exercise 3.1

```cpp
void Print(const LinkedList &l)
{
	Node* p = l.First();
	while (p) {
		std::cout << p->data << " ";
		p = l.Advance(p);
	}
	std::cout << endl;
}
```

## Exercise 3.2

```cpp
void PrintLots(const LinkedList &L, const LinkedList &P)
{
	/*Node* l = L.First();
	Node* p = P.First();
	while (l && p) {
		l = L.First();
		int loc = P.Restrieve(p);
		while (--loc)
			l = L.Advance(l);      //unsafe, may raise nullptr error
		cout << L.Restrieve(l) << " ";
		p = P.Advance(p);
	}*/
	Node* Lpos;
	Node* Ppos;
	Lpos = L.First();
	Ppos = P.First();
	int Count = 1;
	while (Lpos && Ppos) {     //safe, wouldn't raise error
		if (P.Restrieve(Ppos) == Count++) {
			cout << L.Restrieve(Lpos) << " ";
			Ppos = P.Advance(Ppos);
		}
		Lpos = L.Advance(Lpos);   //important! 
	}
}
```

## Exercise 3.3

Singly linked list: (before_p is the element before the two adjacent elements(p and after_p) are to swapped.)  
```cpp
void SinglyLinkedList::Swap(Node* before_p)
{
	Node* p;
	Node* after_p;
	p = before_p->next;
	after_p = p->next;
	before_p->next = after_p;
	p->next = after_p->next;
	after_p->next = p;
}
```

Doubly linked list:(p and after_p are the two adjacent elements are to swapped)  
Assume that the class Node has two member `Node* previous` and `Node* next`
```cpp
void DoublyLinkedList::Swap(Node* p)
{
	Node* after_p = p->next;
	Node* pre_p = p->previous;
	Node* the_next = after_p->next;
	after_p->previous = pre_p;
	pre_p->next = after_p;
	after_p->next = p;
	p->previous = after_p;
	p->next = the_next;
	the_next->previous = p;
}
```

## Exercise 3.4

```cpp
LinkedList Intersect(const LinkedList &L1, const LinkedList &L2)
{
	LinkedList answer;
	Node* loc_l1 = L1.First();
	Node* loc_l2 = L2.First();
	Node* loc_ans = answer.Header();
	while (loc_l1 && loc_l2) {
		if (L1.Restrieve(loc_l1) < L2.Restrieve(loc_l2))
			loc_l1 = L1.Advance(loc_l1);
		else if (L1.Restrieve(loc_l1) > L2.Restrieve(loc_l2))
			loc_l2 = L2.Advance(loc_l2);
		else {
			answer.Insert(L1.Restrieve(loc_l1), loc_ans);
			loc_l1 = L1.Advance(loc_l1);
			loc_l2 = L2.Advance(loc_l2);
			loc_ans = answer.Advance(loc_ans);
		}
	}
	return answer;
}
```

## Exercise 3.5

```cpp
LinkedList Union(const LinkedList &L1, const LinkedList &L2)
{
	LinkedList answer;
	int num;
	Node* loc_l1 = L1.First();
	Node* loc_l2 = L2.First();
	Node* loc_ans = answer.Header();
	while (loc_l1 && loc_l2) {
		if (L1.Restrieve(loc_l1) < L2.Restrieve(loc_l2)) {
			num = L1.Restrieve(loc_l1);
			loc_l1 = L1.Advance(loc_l1);
		}
		else if (L1.Restrieve(loc_l1) > L2.Restrieve(loc_l2)) {
			num = L2.Restrieve(loc_l2);
			loc_l2 = L2.Advance(loc_l2);
		}
		else {
			num = L1.Restrieve(loc_l1);
			loc_l1 = L1.Advance(loc_l1);
			loc_l2 = L2.Advance(loc_l2);
		}
		answer.Insert(num, loc_ans);
		loc_ans = answer.Advance(loc_ans);
	}
	while (loc_l1) {
		answer.Insert(L1.Restrieve(loc_l1),loc_ans);
		loc_l1 = L1.Advance(loc_l1);
		loc_ans = answer.Advance(loc_ans);
	}
	while (loc_l2) {
		answer.Insert(L2.Restrieve(loc_l2), loc_ans);
		loc_l2 = L2.Advance(loc_l2);
		loc_ans = answer.Advance(loc_ans);
	}
	return answer;
}
```

## Exercise 3.6 ~ 3.7

[3.2.7 Exercise](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/README.md#327-exercise--the-polynomial-adt) (Check List Version cpp)  

## Exercise 3.8

[Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_08_poly_exp.cpp)  

## Exercise 3.10

**a. Write a program with disposal of cells**  
Note that the `LinkedList` in the function below is a circular list. Just need to change the line 25 in `List.h` to  
```cpp
LinkedList() : count(0) { head->next = head; }
```  
Program:  
```cpp
int Josephus(int N,int M)
{
	LinkedList L;    
	Node* p = L.Header();
	for (int i = 1; i <= N; ++i) { 
		L.Insert(i, p);
		p = L.Advance(p);
	}
	p = L.First();
	while (L.Size() != 1) {
		int temp = M;
		while (--temp) {
			p = L.Advance(p);
			if (p == L.Header())   //list with dummy node make it a little bit inelegant
				p = L.Advance(p);
		}
		if (p == L.Header())
			p = L.Advance(p);
		Node* the_next = L.Advance(p);
		L.Delete(p->data);
		p = the_next;
		if (p == L.Header())
			p = L.Advance(p);
	}
	return L.Restrieve(p);
}
```

**b. The running time**  
O(NM)

**c. The running time if m = 1. How is the actual speed affected by the free routine for large values of N**  
If m = 1, the running time is O(N).  
For large values of N, the actual speed depends on compiler's memory management routine.

**The much more faster algorithm :**  
[Reference(Chinese)](https://blog.csdn.net/u011500062/article/details/72855826)
```cpp
int Josephus(int N, int M)
{
	int i,p = 0;
	for (i = 2; i <= N; ++i)
		p = (p + M) % i;
	return p + 1;
}
```  
Its running time is O(N).

## Exercise 3.11

**Recursive**  
```cpp
Node* LinkedList::Find(int x, Node* p)
{
	if (p != nullptr && p->data != x)
		Find(x, p->next);
	return p;
}
```

**Nonrecursive**  
```cpp
Node* LinkedList::Find(int x)
{
	Node* p = First();
	while (p != nullptr && p->data != x)
		p = p->next;
	return p;
}
```

When list has about more than 4500 elements, stack overflow.

## Exercise 3.12

```cpp
void LinkedList::Reverse()
{
	Node* pre = nullptr;
	Node* cur = First();
	Node* the_next = cur->next;
	while (cur) {
		cur->next = pre;
		pre = cur;
		cur = the_next;
		if(the_next)
			the_next = the_next->next;
	}
	head->next = pre;
}
```

## Exercise 3.13

I think use array is easier and more effective than using list, so I post array version here.  
[RadixSort](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_13_radix_sort.cpp)  
[Reference(Chinese)](https://www.jianshu.com/p/08bed64b1501)

## Exercise 3.14

[GraphAdjList for undirected graph](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/tree/master/ch03)








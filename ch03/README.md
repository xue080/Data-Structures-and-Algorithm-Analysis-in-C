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

## Exercise 3.6

[Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/README.md#327-exercise--the-polynomial-adt) (Check List Version)  
The Time Complexity : O(max{M,N})

















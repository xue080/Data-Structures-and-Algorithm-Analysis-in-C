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

List Version : [hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue_list.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue_list.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue_list_test.cpp)  
Array Version : [hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/queue_test.cpp)

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
	std::cout << std::endl;
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

Singly linked list: (*before_p* is the element before the two adjacent elements(*p* and *after_p*) to be swapped.)  
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

Doubly linked list:(*p* and *after_p* are the two adjacent elements are to swapped)  
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
Note that the *LinkedList* in the function below is a circular list. Just need to change the line 25 in `List.h` to  
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

[GraphAdjList for undirected graph](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_14_graph_adjlist.cpp)  
[Reference(Chinese)](https://blog.csdn.net/jnu_simba/article/details/8866844)

## Exercise 3.15

**a. Array implementation**  
```cpp
bool Find(int x,LinkedList L)
{
	bool flag = false;
	int loc = 0	;
	for(int i = 1;i != Size();++i) {
		if(L[i].element == x) {
			flag = true;
			loc = i;
			break;
		}
	}
	if(flag) {
		for(int i = loc;i != 1;--i)
			L[i].element = L[i - 1].element;
		L[1].element = x;
		return true;
	}
	return false;
}
```

**b.Linked list implementation**  
```cpp
Node* LinkedList::Find(int x)
{
	Node* pre = FindPrevious(x);
	Node* loc_x;
	if(pre != nullptr) {  //found
		loc_x = pre->next;
		pre->next = loc_x->next;
		loc_x->next = First();
		Header()->next = loc_x;
		return loc_x;
	}
	return nullptr;
}
```

## Exercise 3.16

**a.Explain how this procedure works**  
Traverse the list(not include the last one), compare each element with its rear ones, if equals, delete the rear one, else compare with the next one.

**b.Using general list operations**  
```cpp
void LinkedList::RemoveDup()
{
	for (Node* p = First(); !IsLast(p); p = p->next) {
		Node* q = p->next;
		while (q) {
			if (q->data == p->data) {
				Node* temp = q->next;
				delete q;
				q = temp;
				p->next = temp;  //need update p->next, otherwise it's a dangling pointer
				count--;    //update the number of elements
			}
			else
				q = q->next;
		}
	}
}
```

**c.The running time using array implementation**  
O(N^2)

**d.The running time using linked list implementation**  
O(N^2)

**e.Give an algorithm to solve this problem in O(n log n) time**  
Sort the list, and then traverse the list once to remove duplicates.

## Exercise 3.17

**a.List the advantages and disadvantages**  
Advantages : Simple to code, and there is a possibe saving if deleted elements are reinserted in the same place later.  
Disadvantages : Use more space, and in most cases, the deleted elements are not freed.

**b.Write the routine**  
Necessary modifications to the List ADT have made.  
Check [Implementation of List](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/README.md#322-exercise--implementation-of-list)
```cpp
void LinkedList::LazyDelete(int x)
{
	Node* p = Find(x);
	p->deleted = true;
	de_count++;   //de_count is the number of being deleted
				  //no_de_count is the number of not being deleted
	no_de_count = count - de_count;
	if (de_count == no_de_count) {
		Node* q = Header();
		while (q->next) {
			if (q->next->deleted) {
				Node* temp = q->next->next;
				delete q->next;
				q->next = temp;
			}
			else
				q = q->next;
		}
	}
}
```

## Exercise 3.18

I write the code of b.(a and b are the same).  
[BalanceSymbols](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_18_blance_symbols.cpp)

## Exercise 3.19 ~ 3.20

**3.19 ~ 3.20.b :**  
[3.3.3 Exercise](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/tree/master/ch03#333-exercise--infix-to-postfix-conversion)

**3.20.c :**  
The output will get extra parentheses.  
```cpp
string PostfixToInfix(const string& str)
{
	stack<string> s;
	string operators = "+-*/^";
	for(auto i : str) {
		if(isdigit(i))
			s.push(to_string(i - '0'));
		else if(operators.find(i) != string::npos) {
			string item1 = s.top();
			s.pop();
			string item2 = s.top();
			s.pop();
			s.push("(" + item2+ i + item1 + ")");
		}
	}
	return s.top();
}
```

## Exercise 3.21

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_21_two_stacks.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_21_two_stacks.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_21_two_stacks_test.cpp)


## Exercise 3.22

Let E be the extended stack(implemented with two stacks). One stack, called S, used to perform *Push* and *Pop*, and another, called M, used to perform *FindMin*. When we perform *Push(x)* in E, we perform *Push(x)* in S indeed. If x is smaller than or equal to the top element in M, we also perform *Push(x)* in M. To implement *Pop()* in E, we perform *Pop()* in S. If equals to the top element of M, we also *Pop()* in M. *FindMin()* just return the top element of M.

## Exercise 3.23

One grow from the bottom up, another from the top down, and the third in the middle grow in arbitrary direction. If the third one collides with either of the other two, it needs to be moved —— its center should be halfway between the tops of the other two stacks.

## Exercise 3.24

Stack space will not run out, but the routine will not terminate in a reasonable amount of time.

## Exercise 3.25

[3.4.2 Exercise](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/tree/master/ch03#342-exercise--implementation-of-queue)

## Exercise 3.26

[hpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_26_deque.h) [cpp](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_26_deque.cpp) [test](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch03/ex3_26_deque_test.cpp)

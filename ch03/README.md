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
```cpp
void DoublyLinkedList::Swap(Node* p)
{

}
```

#include"deque.h"
#include<iostream>
using namespace std;

int main()
{
	Deque d;
	d.Push(1);
	cout << d.Pop() << endl;
	cout << boolalpha << d.IsEmpty() << endl;
	Deque d2(d);
	d2.Inject(2);
	d2.Inject(3);
	cout << d2.Eject() << endl;
	cout << boolalpha << d2.IsEmpty() << endl;
	Deque d3 = d2;
	cout << d3.Pop() << endl;
	cout << boolalpha << d3.IsEmpty() << endl;
	return 0;
}

//output :
//1
//true
//3
//false
//2
//true

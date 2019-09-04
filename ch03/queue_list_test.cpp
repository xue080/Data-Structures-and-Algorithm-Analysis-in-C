#include"queue_list.h"
#include<iostream>
using namespace std;

int main()
{
	Queue q;
	cin >> q;
	cout << q << endl;
	q.Dequeue();
	q.Enqueue(10);
	cout << q << endl;
	cout << q.Front() << endl;
	cout << q.FrontAndDequeue() << endl;
	cout << q << endl;
	q.MakeEmpty();
	cout << boolalpha << q.IsEmpty() << endl;
	cout << q << endl;
	return 0;
}

//input:
//1 2 3 4 5
//^Z

//output:
//1 2 3 4 5
//2 3 4 5 10
//2
//2
//3 4 5 10
//true
//

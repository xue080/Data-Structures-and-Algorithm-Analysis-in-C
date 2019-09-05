#include"queue_list.h"
#include<iostream>
using namespace std;

int main()
{
	Queue q;
	for (int i = 1; i != 5; ++i)
		q.Enqueue(i);
	cout << q.Front() << endl;
	q.Enqueue(5);
	for (int i = 0; i != 3; ++i)
		q.Dequeue();
	cout << boolalpha << q.IsEmpty() << endl;
	cout << q.FrontAndDequeue() << endl;
	Queue q2(q);
	cout << q2.Front() << endl;
	Queue q3 = q2;
	cout << q3.Front() << endl;
	q3.MakeEmpty();
	cout << boolalpha << q3.IsEmpty() << endl;
	return 0;
}

//output:
//1
//false
//4
//5
//5
//true

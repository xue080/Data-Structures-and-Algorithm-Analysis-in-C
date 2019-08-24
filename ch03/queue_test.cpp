#include"Queue.h"
#include<iostream>
using namespace std;

int main()
{
	Queue q(10);
	cout << boolalpha << q.IsEmpty() << endl;
	for (int i = 0; i != 5; ++i)
		q.Enqueue(i);
	for (int i = 0; i != 3; ++i)
		cout << q.FrontAndDequeue() << endl;
	Queue p = q;
	q.MakeEmpty();
	cout << boolalpha << q.IsEmpty() << endl;
	for (int i = 0; i != 2; ++i)
		cout << p.FrontAndDequeue() << endl;
	return 0;
}

//output:
//true
//0
//1
//2
//true
//3
//4

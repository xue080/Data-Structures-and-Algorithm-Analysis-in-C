#include<iostream>
#include"stack_array.h"
using namespace std;

int main()
{
	Stack s(10);  //capacity is 10
	cout << boolalpha << s.IsEmpty() << endl;
	for (int i = 0; i != 5; ++i)
		s.Push(i);
	for (int i = 0; i != 5; ++i)
		cout << s.TopAndPop() << endl;
	cout << boolalpha << s.IsEmpty() << endl;
	return 0;
}

//output:
//true
//4
//3
//2
//1
//0
//true

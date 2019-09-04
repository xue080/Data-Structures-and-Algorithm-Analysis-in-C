#include"two_stacks.h"
#include<iostream>
using namespace std;

int main()
{
	TwoStacks s(10);
	for (int i = 0; i != 4; ++i) {
		s.Push1(i);
		s.Push2(i);
	}
	cout << boolalpha << s.IsFull() << endl;
	for (int i = 0; i != 3; ++i)
		cout << s.TopAndPop1() << " " << s.TopAndPop2() << endl;
	cout << boolalpha << s.IsEmpty1() << " " << s.IsEmpty2() << endl;
	s.MakeEmpty();
	cout << boolalpha << s.IsEmpty1() << " " << s.IsEmpty2() << endl;
	s.Push1(1);
	s.Pop1();
	s.Push2(2);
	s.Pop2();
	cout << boolalpha << s.IsEmpty1() << " " << s.IsEmpty2() << endl;
	return 0;
}

//output:
//false
//3 3
//2 2
//1 1
//false false
//true true
//true true

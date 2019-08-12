#include"Stack.h"
using namespace std;

int main()
{
	Stack stack1;
	cout << boolalpha << stack1.IsEmpty() << endl;
	for (int i = 0; i != 5; ++i)
		stack1.Push(i);
	cout << stack1 << endl;
	for (int i = 0; i != 3; ++i) {
		stack1.Pop();
		cout << stack1 << endl;
	}
	cout << stack1.Top() << endl;
	stack1.MakeEmpty();
	cout << stack1 << endl;
	system("pause");
}

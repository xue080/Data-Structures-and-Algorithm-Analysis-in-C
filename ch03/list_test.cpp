#include"List.h"
using namespace std;

int main()
{
	LinkedList list;  
	cin >> list;
	cout << list << endl;
	
	LinkedList list2(list);  
	list2.Delete(5);
	cout << list2 << endl;

	LinkedList list3 = list2;
	list3.DeleteList();
	cout << list3 << endl;
	cout << boolalpha << list3.IsEmpty() << endl;
	cout << list3.First() << endl;

	return 0;
}

//input:
//2 3 4 5 6 7
//^Z

//output"
//2 3 4 5 6 7
//2 3 4 6 7
//
//true
//00000000   (nullptr)

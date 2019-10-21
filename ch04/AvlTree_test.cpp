#include"AvlTree.h"
using namespace std;

int main()
{
	AvlTree t;
	cin >> t;
	cout << t << endl;
	cout << t.Max() << " " << t.Min() << endl;
	t.Delete(5);
	cout << t << endl;
	t.MakeEmpty();
	cout << boolalpha << t.IsEmpty() << endl;
	cout << (t.Find(2) ? "true" : "false") << endl;
	t.Insert(2);
	Position p = t.Find(2);
	cout << t.Retrieve(p) << endl;
	AvlTree t2(t);
	t2.Insert(3);
	cout << t2 << endl;
	t2.MakeEmpty();
	cout << boolalpha << t2.IsEmpty() << endl;
	cout << boolalpha << t.IsEmpty() << endl;

	AvlTree t3;
	t3.GenMinTree(3);
	cout << t3 << endl;
	system("pause");
}

//input:
//4 2 1 3 6 5 7 16 15 14 13
//^ Z

//output:
//7 4 2 1 3 6 5 15 14 13 16
//16 1
//7 4 2 1 3 6 15 14 13 16
//true
//false
//2
//2 3
//true
//false
//5 3 2 1 4 7 6
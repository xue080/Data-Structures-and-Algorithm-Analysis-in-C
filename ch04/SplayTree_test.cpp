#include"SplayTree.h"
using namespace std;


int main()
{
	SplayTree t;
	cin >> t;
	cout << t << endl;
	cout << "max: " << t.Max() << " min: " << t.Min() << endl;
	cout << boolalpha << t.Find(1) << endl;
	cout << t << endl;

	SplayTree t2(t);
	t.MakeEmpty();
	cout << boolalpha << t.IsEmpty() << endl;
	cout << t2 << endl;
	t2.Delete(3);
	cout << t2 << endl;
	return 0;
}

//input:
//4 2 3 1
//^Z

//output:
//4 2 1 3
//max: 4 min : 1
//true
//1 2 4 3
//2 1 4
#include"search_tree.h"
using namespace std;

int main()
{
	SearchTree t;
	int N;
	cin >> N;
	t.MakeRandomSearchTree(N);
	cout << t << std::endl;
	system("pause");
}

//int main()
//{
//	SearchTree t;
//	cin >> t;
//	cout << t << endl;
//	cout << t.Max() << " " << t.Min() << endl;
//	t.Delete(5);
//	cout << t << endl;
//	t.MakeEmpty();
//	cout << boolalpha << t.IsEmpty() << endl;
//	cout << (t.Find(2) ? "true" : "false") << endl;
//	t.Insert(2);
//	Position p = t.Find(2);
//	cout << t.Retrieve(p) << endl;
//	SearchTree t2(t);
//	t2.Insert(3);
//	cout << t2 << endl;
//	t2.MakeEmpty();
//	cout << boolalpha << t2.IsEmpty() << endl;
//	cout << boolalpha << t.IsEmpty() << endl;
//	system("pause");
//}

//input:
//2 4 3 5 1
//^ Z

//output:
//2 1 4 3 5
//5 1
//2 1 4 3
//true
//false
//2
//2 3
//true
//false

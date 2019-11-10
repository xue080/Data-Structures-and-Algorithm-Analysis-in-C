#include<iostream>
#include"hash_sep.h"
using namespace std;

int main()
{

	Hash h(10);
	for (size_t i = 1; i <= 20; ++i)
		h.Insert(i);
	h.Delete(1);
	if (h.Find(2)) {
		cout << h.Retrieve(h.Find(2)) << endl;
	}
	else {
		cerr << "Data not found" << endl;
	}
	Hash h2(h);
	h.MakeEmpty();
	if (h2.Find(2)) {
		cout << h2.Retrieve(h2.Find(2)) << endl;
	}
	else {
		cerr << "Data not found" << endl;
	}
	h = h2;
	if (h2.Find(10)) {
		cout << h2.Retrieve(h2.Find(10)) << endl;
	}
	else {
		cerr << "Data not found" << endl;
	}
	return 0;
}
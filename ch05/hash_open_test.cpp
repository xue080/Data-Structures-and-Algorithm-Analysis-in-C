#include<iostream>
#include<random>
#include<ctime>
#include"hash_open.h"
using namespace std;

int main()
{
	Hash h(30);
	for (size_t i = 1; i <= 15; ++i)
		h.Insert(i);
	h.Delete(1);
	if (h.GetPositionState(h.Find(2)) == Legitimate) {
		cout << h.Retrieve(h.Find(2)) << endl;
	}
	else {
		cerr << "Data not found" << endl;
	}
	Hash h2(h);
	h.MakeEmpty();
	if (h2.GetPositionState(h2.Find(30)) == Legitimate) {
		cout << h2.Retrieve(h2.Find(30)) << endl;
	}
	else {
		cerr << "Data not found" << endl;
	}
	h = h2;
	if (h.GetPositionState(h.Find(15)) == Legitimate) {
		cout << h.Retrieve(h.Find(15)) << endl;
	}
	else {
		cerr << "Data not found" << endl;
	}
	return 0;
}
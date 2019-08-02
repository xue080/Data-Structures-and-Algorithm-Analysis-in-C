//Exercise 2.7:
//Same as algorithm (1), but keep an extra array called the used array. When a
//random number, ran, is first put in the array a, set used[ran] = 1. This means
//that when filling a[i] with a random number, you can test in one step to see
//whether the random number has been used, instead of the (possibly) i steps in the
//first algorithm.

#include<iostream>                
#include<random>
#include <ctime>
#include <vector>
#include<algorithm>
using namespace std;

int RandInt(int beg,int end)        
{
	static default_random_engine generator(time(NULL));
	static uniform_int_distribution<int> distribution(beg,end);
	return distribution(generator);
}

int main()
{
	int N;
	cin >> N;
	vector<int> A;
	vector<int> Used(N + 5);
	while(A.size() != N) {
		int num = RandInt(0,N);
		if(Used[num] != 1) {
			Used[num] = 1;    
			A.push_back(num);
		}
	}
	for(const int& i : A)
		cout<< i <<" ";
	return 0;
}

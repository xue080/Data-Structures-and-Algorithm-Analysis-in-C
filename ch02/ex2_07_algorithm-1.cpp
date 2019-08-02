//Exercise 2.7:(Algorithm-1)
//Fill the array a from a[0] to a[n - 1] as follows: To fill a[i], generate
//random numbers until you get one that is not already in a[0], a[1], a[2], . . . ,a[i-1].

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
	while(A.size() != N) {
		int num = RandInt(0,N);
		if(none_of(A.begin(),A.end(),[=](int k){return k == num;}))   //true only when none of elements is equal to the random number
			A.push_back(num);
	}
	for(const int& i : A)
		cout << i << " ";
	return 0;
}

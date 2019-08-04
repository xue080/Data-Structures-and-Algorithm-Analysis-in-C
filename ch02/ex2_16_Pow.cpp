//Exercise 2.16:
//Write the fast exponentiation routine without recursion.

#include<iostream>
#include<cmath>
#include <vector>
using namespace std;

long int Pow(long int X,unsigned int N)
{
	vector<long int> v;
	int i;
	int value = 1;
	v.push_back(X);
	for(i = 1;i <= log2(N);++i)        
		v.push_back(v[i - 1] * v[i - 1]);
	i = 0;
	while(N > 0) {
		if(N % 2 == 1)
			value *= v[i];
		i++;
		N /= 2;
	}
	return value;
}

int main()
{
	long int X;
	unsigned int N;
	cin >> X >> N;
	cout << Pow(X,N) << endl;
	return 0;
}

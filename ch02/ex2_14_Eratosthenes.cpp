//Exercise 2.14:
//*2.14 The Sieve of Erastothenes is a method used to compute all primes less than
//N. We begin by making a table of integers 2 to n. We find the smallest integer,
//i, that is not crossed out, print i, and cross out i, 2i, 3i, . . . . When i > N^(1/2)
//the algorithm terminates. What is the running time of this algorithm?

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void Erastothenes(int N)
{
	vector<int> v(N,1);
	for(int i = 2;i <= sqrt(N);++i) 
		if(v[i] == 1)
			for(int j = 2 * i;j < N;j += i)
				v[j] = 0;
	
	for(int i = 2;i != N;++i) 
		if(v[i] == 1)
			cout << i << " ";
}

int main()
{
	int N;
	cin >> N;
	Erastothenes(N);
	return 0;
}

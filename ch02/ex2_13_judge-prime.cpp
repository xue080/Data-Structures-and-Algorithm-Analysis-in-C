//Exercise 2.13:
//Write a program to determine if a positive integer, n, is prime.

#include<iostream>
#include<cmath>
using namespace std;

bool JudgePrime(int n)
{
	if(n < 2)
		return false;
	for(int i = 2;i <= sqrt(n);++i) {
		if( n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	cout << boolalpha << JudgePrime(n) << endl;
	return 0;
}

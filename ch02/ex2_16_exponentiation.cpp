//Exercise 2.16:
//Write the fast exponentiation routine without recursion.

#include<iostream>
#include<cmath>
#include <vector>
using namespace std;

#include<iostream>
using namespace std;

long int Pow(int base,int exp)
{
	long int ans = 1;
	while(exp)
	{
		if(exp & 1)
			ans *= base;
		base *= base;
		exp >>= 1;
	}
	return ans;
}

int main()
{
	int a,b;
	cin >> a >> b;
	cout << Pow(a,b) << endl;
	return 0;
}

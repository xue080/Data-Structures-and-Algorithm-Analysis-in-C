#include<iostream>
#include"polynomial_list.h"
using namespace std;

Polynomial Pow(Polynomial poly, int exp)
{
	Polynomial one;
	cin >> one; //input '1 0' make it equal one then input '0 0' to quit 
	while (exp) {
		if (exp & 1)
			one *= poly;
		poly *= poly;
		exp >>= 1;
	}
	return one;
}

int main()
{
	Polynomial poly;
	int n;
	cin >> poly;    //remember '0 0' to quit
	cin >> n;
	cout << Pow(poly, n) << endl;
	return 0;
}

//input:
//1 2
//1 1
//0 0
//2
//1 0
//0 0

//output:
//x^4+2x^3+x^2

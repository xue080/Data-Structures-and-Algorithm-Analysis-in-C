//Exercise 1.3 :
//Write a procedure to output an arbitrary real number 
//(which might be negative) using only print_digit for I/O.

#include<iostream>
using namespace std;

void PrintDigit(size_t N)
{
	cout << N;
}

void PrintOut(size_t N)
{
	if (N >= 10)
		PrintOut(N / 10);
	PrintDigit(N % 10);
}

void PrintOut(double N, size_t precision)  //define precision to avoid round-off error
{
	if (N < 0) {
		cout << '-';
		N = -N;
	}
	int integer_part = static_cast<int>(N);   
	PrintOut(integer_part);   
	cout << '.';
	double float_part = N - integer_part;
	int dou_to_int= static_cast<int>(float_part * pow(10, precision));
	PrintOut(dou_to_int);
}

int main()
{
	PrintOut(995);
	cout << endl;
	PrintOut(-88.888, 3);
	cout << endl;
	return 0;
}

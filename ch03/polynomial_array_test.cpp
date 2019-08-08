#include"polynomial_array.h"
using namespace std;

int main()
{
	Polynomial poly1, poly2;
	cin >> poly1 >> poly2;
	cout << poly1 << '\t' << poly2 << endl;
	cout << poly1 + poly2 << endl;
	cout << poly1 * poly2 << endl;
	Polynomial poly3 = poly1;
	poly3 += poly1;
	cout << poly3 << endl;
	Polynomial poly4 = poly2;
	poly4 *= poly2;
	cout << poly4 << endl;
	return 0;
}

//input:
//2 3
//1 1
//0 0
//3 2
//4 0
//0 0

//output:
//2x^3+x  3x^2+4
//2x^3+3x^2+x+4
//6x^5+11x^3+4x
//4x^3+2x
//9x^4+24x^2+16

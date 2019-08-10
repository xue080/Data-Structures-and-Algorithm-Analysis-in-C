#include"polynomial_list.h"
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

//input :
//2 3
//2 2
//0 0
//1 3
//1 1
//0 0

//output :
//2x^3+2x^2       x^3+x
//3x^3+2x^2+x
//2x^6+2x^5+2x^4+2x^3
//4x^3+4x^2
//x^6+2x^4+x^2

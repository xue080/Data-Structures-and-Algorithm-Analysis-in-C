#ifndef _POLYNOMIAL_ARRAY_H
#define _POLYNOMIAL_ARRAY_H

#include<iostream>

constexpr int MaxDegree = 10000;

class Polynomial {
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend std::istream& operator>>(std::istream&, Polynomial&);
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
public:
	Polynomial();
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
private:
	int coeff[MaxDegree + 1];   
	int high_power;
};

#endif // !_POLYNOMIAL_ARRAY_H

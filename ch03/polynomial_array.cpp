#include"polynomial_array.h"
#include<algorithm>

Polynomial::Polynomial() :high_power(0)
{
	for (int i = 0; i <= MaxDegree; ++i)
		coeff[i] = 0;
}

std::istream& operator>>(std::istream &is, Polynomial &poly)
{
	int coef, expo, max_expo = 0;
	while (is >> coef >> expo && coef) {  //input "0 0" -> end
		poly.coeff[expo] = coef;
		if (expo > max_expo)
			max_expo = expo;
	}
	poly.high_power = max_expo;
	return is;
}

std::ostream& operator<<(std::ostream &os, const Polynomial &poly) 
{
	for (int i = poly.high_power; i > 1; --i) {
		if (poly.coeff[i] != 0) {
			if (poly.coeff[i] == 1)
				os << "x^" << i;
			else
				os << poly.coeff[i] << "x^" << i;
		}
		if (poly.coeff[i - 1] > 0)
			os << "+";
	}
	if (poly.coeff[1] != 0) {    
		if (poly.coeff[1] == 1)
			os << "x";
		else
			os << poly.coeff[1] << "x";
	}
	if (poly.coeff[0] > 0)
		os << "+" << poly.coeff[0];
	else if (poly.coeff[0] < 0)
		os << poly.coeff[0];
	return os;
}

Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
	high_power = std::max(high_power, poly.high_power);
	for (int i = high_power; i >= 0; --i)
		coeff[i] += poly.coeff[i];
	return *this;
}

Polynomial operator+(const Polynomial &poly1, const Polynomial &poly2)
{
	Polynomial poly_sum = poly1;
	poly_sum += poly2;
	return poly_sum;
}

Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2)
{
	Polynomial poly_product;
	poly_product.high_power = poly1.high_power + poly2.high_power;
	if (poly_product.high_power > MaxDegree)
		throw std::runtime_error("Exceeded array size");
	for (int i = 0; i <= poly1.high_power; ++i)
		for (int j = 0; j <= poly2.high_power; ++j)
			poly_product.coeff[i + j] += poly1.coeff[i] * poly2.coeff[j];
	return poly_product;
}

Polynomial& Polynomial::operator*=(const Polynomial &poly)  //to use operator* is easier
{
	*this = *this * poly;
	return *this;
}

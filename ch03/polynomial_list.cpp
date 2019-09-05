#include"polynomial_list.h"

Polynomial::Polynomial(const Polynomial &poly)
{
	Node* to_copy = poly.head;	
	Node* dest = head;
	while (to_copy->next) {
		dest->next = new Node(to_copy->next->coeff, to_copy->next->expo);
		to_copy = to_copy->next;
		dest = dest->next;
	}
}

Polynomial& Polynomial::operator=(Polynomial poly)
{
	std::swap(head, poly.head);
	return *this;
}

Polynomial::~Polynomial()
{
	Node* p = head->next;
	head->next = nullptr;
	while (p) {
		Node* temp = p->next;
		delete p;
		p = temp;
	}
	delete head;
}

Polynomial operator+(const Polynomial &poly1, const Polynomial &poly2)
{
	Node* addend1 = poly1.head->next;
	Node* addend2 = poly2.head->next;
	Polynomial poly_sum;
	Node* p = poly_sum.head;
	while (addend1 || addend2) {  //traverse
		if (addend1 && (!addend2 || addend1->expo > addend2->expo)) {
			p->next = new Node(addend1->coeff, addend1->expo);
			p = p->next;
			addend1 = addend1->next;
		} 
		else if (addend2 && (!addend1 ||addend2->expo > addend1->expo)) {
			p->next = new Node(addend2->coeff, addend2->expo);
			p = p->next;
			addend2 = addend2->next;
		}
		else {
			int coefficient = addend1->coeff + addend2->coeff;
			if (coefficient != 0) {
				p->next = new Node(coefficient, addend1->expo);
				p = p->next;
			}
			addend1 = addend1->next;
			addend2 = addend2->next;
		}
	}
	return poly_sum;
}

Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
	*this = *this + poly;
	return *this;
}

Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2)
{
	Node* mul1 = poly1.head->next;
	Polynomial poly_product;
	while (mul1) {
		Polynomial temp;
		Node* p = temp.head;
		Node* mul2 = poly2.head->next;
		while (mul2) {
			p->next = new Node(mul1->coeff*mul2->coeff, mul1->expo + mul2->expo);
			p = p->next;
			mul2 = mul2->next;
		}
		poly_product += temp;
		mul1 = mul1->next;
	}
	return poly_product;
}

Polynomial& Polynomial::operator*=(const Polynomial &poly)
{
	*this = *this * poly;
	return *this;
}

std::istream& operator>>(std::istream &is, Polynomial &poly)
{
	int coef, expo;
	Node* p = poly.head;
	while (is >> coef >> expo && coef) {  //note that the input of expo should be decreasing,
		p->next = new Node(coef, expo);      //and when input "0 0" -> end	
		p = p->next;
	}
	return is;
}

std::ostream& operator<<(std::ostream &os, const Polynomial &poly)
{
	Node* p = poly.head->next;
	while (p) {
		if (p->expo == 0)
			os << p->coeff;
		else {
			if (p->expo == 1) {
				if (p->coeff == 1)
					os << "x";
				else
					os << p->coeff << "x";
			} else {
				if (p->coeff == 1)
					os << "x^" << p->expo;
				else
					os << p->coeff << "x^" << p->expo;
			}
		}
		if (p->next) {
			if (p->next->coeff > 0)
				os << "+";
		}
		p = p->next;
	}
	return os;
}

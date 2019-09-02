#ifndef _POLYNOMIAL_LIST_H
#define _POLYNOMIAL_LSIT_H

#include<iostream>

struct Node {
	Node() :coeff(0), expo(0), next(nullptr) {}
	Node(int co, int ex) :coeff(co), expo(ex), next(nullptr) {}
	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete;

	int coeff;
	int expo;
	Node* next;
};

class Polynomial {
	friend std::istream& operator>>(std::istream&, Polynomial&);
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const Polynomial&);
public:
	Polynomial() = default;
	Polynomial(const Polynomial&);
	Polynomial& operator=(Polynomial);
	~Polynomial();

	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);

private:
	Node* head = new Node; //note that it's a dummy node(also called header)!!!
};

#endif // !_POLYNOMIAL_LIST_H

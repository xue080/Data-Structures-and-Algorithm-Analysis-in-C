//As the example in the book, we just discuss integer.

#include<iostream>
#include<stack>
#include <string>
using namespace std;

string Conversion(const string &str)   //convertinfix expressions to postfix expressions
{
	stack<char> s;
	string result;
	for(auto i : str) {
		if(isdigit(i))
			result += i;
		else {
			switch(i) {
				case '+':      //subtraction and addition have equal priority
				case '-':
					while(!s.empty() && s.top() != '(') {
						result += s.top();
						s.pop();
					}
					s.push(i);
					break;
				case '*':      //multiplication and division have equal priority
				case '/':
					while(!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '('){
						result += s.top();
						s.pop();
					}
					s.push(i);
					break;
				case '(':
					s.push(i);
					break;
				case ')':
					while(!s.empty() && s.top() != '(') {
						result += s.top();
						s.pop();
					}
					s.pop();
					break;
			}
		}
	}
	while(!s.empty()) {
		result += s.top();
		s.pop();
	}
	return result;
}

int Calculate(const string &str)       //calculate postfix expressions
{
	stack<int> s;
	int item1,item2;
	for(auto i : str) {
		if(isdigit(i))
			s.push(i - '0');
		else {
			item1 = s.top();
			s.pop();
			item2 = s.top();
			s.pop();
			switch(i) {
				case '+':
					s.push(item1 + item2);
					break;
				case '-':
					s.push(item2 - item1);
					break;
				case '*':
					s.push(item1 * item2);
					break;
				case '/':
					s.push(item2 / item1);
					break;
			}
		}
	}
	return s.top();
}

int main()
{
	string str,conv;
	cin >> str;
	conv = Conversion(str);
	cout << conv << endl;
	cout << Calculate(conv) << endl;
	return 0;
}

//input:
//2+5*2/(4-2)

//output:
//252*42-/+
//7

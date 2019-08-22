//As the example in the book, we just discuss integer.

#include<iostream>
#include <cmath>
#include<stack>
#include<map>
#include <string>
using namespace std;

string Conversion(const string &str)
{
	stack<char> s;
	map<char,int> Map;  
	string result;

	Map['('] = Map[')'] = 0;   //set priority
	Map['+'] = Map['-'] = 1;  
	Map['*'] = Map['/'] = 2;
	Map['^'] = 3;     

	for(auto i : str) {
		if(isdigit(i))
			result += i;
		else {
			switch(i) {
				case '^':     //operators that associate from right to left and '(' just call push()
				case '(':
					s.push(i);
					break;
				case ')':
					while(s.top() != '(') {
						result += s.top();
						s.pop();
					}
					s.pop();
					break;
				default:     // '+' '-' '*' '/' operators that associate from left to right
					while(!s.empty() && Map[s.top()] >= Map[i]) {
						result += s.top();
						s.pop();
					}
					s.push(i);
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

int Calculate(const string &str)
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
				case '^':
					s.push(pow(item2,item1));
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

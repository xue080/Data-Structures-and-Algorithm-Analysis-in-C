#include<iostream>
#include<fstream>
#include<stack>
#include<string>
using namespace std;

bool BalanceSymbols(ifstream& is)
{
	char pre = '/0';
	char cur;
	stack<char> s;
	string open = "([{*";
	string close = ")]}/";
	if (is) {
		while (is >> cur) {
			if (open.find(cur) != string::npos) {
				if (cur == '*') {
					if (pre == '/')    // judge /* and */ -> judge / and / in stack
						s.push(pre);
				} else 
					s.push(cur);
			}
			else if (close.find(cur) != string::npos) {
				if (cur == '/' && pre == '*') {
					if (!s.empty() && s.top() == '/')
						s.pop();
					else
						return false;
				}
				else if (cur == ')') {
					if (!s.empty() && s.top() == '(')
						s.pop();
					else
						return false;
				}
				else if (cur == ']') {
					if (!s.empty() && s.top() == '[')
						s.pop();
					else
						return false;
				}
				else if (cur == '}') {
					if (!s.empty() && s.top() == '{')
						s.pop();
					else
						return false;
				}
			}
			pre = cur;    //update pre
		}
	} else {
		is.clear();
		cerr << "fail to open the file" << endl;
	}
	is.close();
	return s.empty() ? true : false;
}

int main()
{
	ifstream is("test.txt");
	cout << boolalpha << BalanceSymbols(is) << endl;
	return 0;
}

//in test.txt:
// /* haha  /

//output:
//false

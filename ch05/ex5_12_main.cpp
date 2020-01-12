#include"hash_open.h"
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
	Hash h(100); 
	vector<string> result;
	string line, word;
	int old_num, new_num = 0xf;
	while (getline(cin, line)) {
		istringstream is(line);
		string changed_line;
		is >> word;
		old_num = stoi(word);
		changed_line += to_string(new_num);
		changed_line += " ";
		h.Insert({ old_num,new_num });
		new_num += 0xd;
		while (is >> word) {
			if (word == "GOTO" || word == "GOSUB") {
				changed_line += word;
				changed_line += " ";
				is >> word;
				changed_line += to_string(h.Retrieve(h.Find({ stoi(word),0 })).changed);
			} else {
				changed_line += word;
				changed_line += " ";
			}
		}
		result.push_back(changed_line);
	}
	copy(result.begin(), result.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}

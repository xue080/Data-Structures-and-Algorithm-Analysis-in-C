//Exercise 1.4 :
//C allows statements of the form
//#include filename
//which reads filename and inserts its contents in place of the include statement.
//Include statements may be nested; in other words, the file filename may itself
//contain an include statement, but, obviously, a file can't include itself in any
//chain. Write a program that reads in a file and outputs the file as modified by
//the include statements.

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

vector<string> files;

void ProcessFile(const string& filename)
{
	string line;
	ifstream in(filename);
	if (in.fail()) {
		cerr << "fail to open file " << filename << endl;
		return;
	}
	files.push_back(filename);
	while (getline(in, line)) {
		if (line.find("#include") != string::npos) {
			string::size_type beg = line.find_first_of("<\"");
			string::size_type end = line.find_last_of(">\"");
			string file = line.substr(beg + 1, end - beg - 1);
			if (find(files.begin(), files.end(), file) != files.end()) {
				cerr << "Existed file " << file << endl;
				continue;
			} else {
				ProcessFile(file);
			}	
		} else {
			cout << line << endl;
		}
	}
	in.close();
}

int main()
{
	ProcessFile("test.h");
	return 0;
}

//test.h
//#include"SimplifiedString.h"
//#include"test.h"
//using namespace std;

//output
//...(Omitted contents in SimplifiedString.h)
//Existed file test.h
//using namespace std;

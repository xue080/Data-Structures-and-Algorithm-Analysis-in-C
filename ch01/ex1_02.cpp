//Exercise 1.2 :
//Write a program to solve the word puzzle problem.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int change_x[8] = { 1,1,0,-1,-1,-1,0,1 };      //change x,y location
int change_y[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<vector<char>> list;  //letter list
vector<string> dict;    //dictionary

int main()
{
	int dict_n, table_n;
	string word;
	char letter;
	cin >> dict_n;   //input the number of words in dictionary
	while (dict_n--) {
		cin >> word;
		dict.push_back(word);
	}
	cin >> table_n;    //input the dimension of letter list
	list.resize(table_n);     
	for (int i = 0; i != table_n; ++i) {
		for (int j = 0; j != table_n; ++j) {
			cin >> letter;
			list[i].push_back(letter);
		}
	}
	for (int i = 0; i != table_n; ++i) {  //traversal the letter list
		for (int j = 0; j != table_n; ++j) {
			for (int k = 0; k != 8; ++k) {  //traversal the change_x/change_y array
				string s;
				int x = i;
				int y = j;
				for (int l = 0; l != table_n; ++l) {   //deep search until out of range->break 
					s += list[x][y];
					x += change_x[k];
					y += change_y[k];
					if (find(dict.cbegin(), dict.cend(), s) != dict.cend())  
						cout << s << endl;
					if (x < 0 || x >= table_n || y < 0 || y >= table_n)	break;  
				}
			}
		}
	}
	return 0;
}

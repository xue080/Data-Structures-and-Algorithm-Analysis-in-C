#include"hash_open.h"
#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

array<int, 8> change_x{ 1,1,0,-1,-1,-1,0,1 };
array<int, 8> change_y{ 0,1,1,1,0,-1,-1,-1 };

vector<vector<char>> letter_list;

int main()
{
	Hash h(200);
	int dict_n, table_n;
	string word;
	char letter;
	cin >> dict_n;
	while (dict_n--) {
		cin >> word;
		h.Insert(word);
	}
	cin >> table_n;
	letter_list.resize(table_n);
	for (int i = 0; i != table_n; ++i) {
		for (int j = 0; j != table_n; ++j) {
			cin >> letter;
			letter_list[i].push_back(letter);
		}
	}
	for (int i = 0; i != table_n; ++i) {
		for (int j = 0; j != table_n; ++j) {
			for (int k = 0; k != 8; ++k) {
				string s;
				int x = i;
				int y = j;
				for (int l = 0; l != table_n; ++l) {
					s += letter_list[x][y];
					x += change_x[k];
					y += change_y[k];
					if (h.GetPositionState(h.Find(s)) == Legitimate) {
						cout << h.Retrieve(h.Find(s)) << endl;
					}
					if (x < 0 || x >= table_n || y < 0 || y >= table_n) {
						break;
					}
				}
			}
		}
	}
	system("pause");
}
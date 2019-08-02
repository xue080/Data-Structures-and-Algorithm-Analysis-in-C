//Exercise 2.12 :
//a. find the minimum subsequence sum

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N,num;
	int ThisSum = 0,MinSum = 99999999;
	vector<int> v;
	cin >> N;
	for(int i = 0;i != N;++i) {
		cin >> num;
		v.push_back(num);
	}
	for(int i = 0;i != N;++i) {
		ThisSum += v[i];
		if(ThisSum < MinSum)
			MinSum = ThisSum;
		if(ThisSum > 0)
			ThisSum = 0;
	}
	cout << MinSum << endl;
	return 0;
}

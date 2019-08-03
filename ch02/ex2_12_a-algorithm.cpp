//Exercise 2.12 :
//a. find the minimum subsequence sum

#include<iostream>
#include<vector>
using namespace std;

int MinSubSequenceSum(const vector<int>& v,int N)
{
	int ThisSum = 0,MinSum = INT_MAX;
	for(int i = 0;i != N;++i) {
		ThisSum += v[i];
		if(ThisSum < MinSum)
			MinSum = ThisSum;
		if(ThisSum > 0)
			ThisSum = 0;
	}
	return MinSum;
}

int main()
{
	int N,num;
	vector<int> v;
	cin >> N;
	for(int i = 0;i != N;++i) {
		cin >> num;
		v.push_back(num);
	}
	cout << MinSubSequenceSum(v,N) << endl;
	return 0;
}

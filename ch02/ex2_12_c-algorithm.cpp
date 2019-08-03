// Exercise 2.12 :
//*c. find the maximum subsequence product

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSubSequenceProduct(const vector<int>& v, int N)
{
	int ThisProduct, MaxProduct = INT_MIN;
	int TMin = 1, TMax = 1;
	for (int i = 0; i != N; ++i) {
		TMax = max(TMax * v[i], v[i]);
		TMin = min(TMin * v[i], v[i]);
		if (v[i] < 0) {
			swap(TMax, TMin);
		}
		MaxProduct = max(MaxProduct, TMax);
	}
	return MaxProduct;
}

int main()
{
	vector<int> v;
	int N,num;
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> num;
		v.push_back(num);
	}
	cout << MaxSubSequenceProduct(v, N) << endl;
	return 0;
}

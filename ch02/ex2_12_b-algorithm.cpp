// Exercise 2.12 :
//*b. find the minimum positive subsequence sum

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Elem
{
	int PrefixSum = 0;
	int index;
};

int MinPositiveSubSequenceSum(const vector<int>& v, int N)  
{
	vector<Elem> data(N);
	int ThisSum = 0, MinSum = 99999999;
	for (int i = 0; i != N; ++i) {       
		ThisSum += v[i];
		data[i].index = i;
		data[i].PrefixSum = ThisSum;
	}
	sort(begin(data), end(data),            //O(NlogN)
		[](const Elem& i, const Elem& j) {return i.PrefixSum < j.PrefixSum; });
	auto loc = find_if(begin(data), end(data),       
		[](const Elem& i) {return i.PrefixSum > 0; });
	if (loc != end(data))
		MinSum = loc->PrefixSum;
	for (int i = 1; i != N; ++i) {   
		if (data[i].PrefixSum == data[i - 1].PrefixSum)   //answer should be positive, so 0 is also wrong
			continue;
		else if (data[i].index > data[i - 1].index)    
			MinSum = min(MinSum, data[i].PrefixSum - data[i - 1].PrefixSum); 
	}	
	return MinSum;
}

int main()
{
	int N,num;
	vector<int> v;
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> num;
		v.push_back(num);
	}
	cout << MinPositiveSubSequenceSum(v, N) << endl;
	return 0;
}

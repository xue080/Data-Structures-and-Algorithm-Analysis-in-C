// Exercise 2.11 :
//Give an efficient algorithm to determine if there exists an integer i such
//that ai = i in an array of integers a1< a2< a3< . . . < an. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool BinarySearch(const vector<int>& v, int N, int target)
{
	int mid,left = 0, right = N - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (v[mid] < target)
			left = mid + 1;
		else if (v[mid] > target)
			right = mid - 1;
		else
			return true;
	}
	return false;
}

int main()
{
	int N, num, target;
	vector<int> v;
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> target;
	cout << boolalpha << BinarySearch(v, N, target) << endl;
	return 0;
}

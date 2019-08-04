//Exercise 2.19:
//*e. Write a program to compute the majority element.

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FindCandidate(vector<int> A)
{
	vector<int> B;
	int length = A.size();
	if(length == 2) {
		if(A[0] != A[1])
			return -1;
		else
			return A[0];
	} else if(length == 1)
		return A[0];
	if(length % 2 == 0) {
		for(int i = 0;i < length - 1;i += 2) {
			if(A[i] == A[i + 1])
				B.push_back(A[i]);
		}
		return FindCandidate(B);
	} else {
		int ans = FindCandidate(vector<int>(A.begin(),A.end() - 1));
		return ans == -1 ? A[length - 1] : ans; 
	}
}
int main()
{
	vector<int> A;
	int num;
	while(cin >> num)
		A.push_back(num);
	int candidate = FindCandidate(A);
	if(count(A.begin(),A.end(),candidate) > A.size() / 2)
		cout << candidate << endl;
	else
		cout << "No majority element" << endl;
	return 0;
}

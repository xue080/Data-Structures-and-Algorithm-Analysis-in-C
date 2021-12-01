//Exercise 1.1 :
//Write a program to solve the selection problem. Let k = n/2. 
//Draw a table showing the running time of your program for various values of n.

#include<iostream>         //cin>>"要输入的内容";cout<<"要输出的内容";标准的输入输出流头文件;标准的C++头文件
#include<ctime>
#include<fstream>
#include<random>
using namespace std;

int arr[100010];

void BubleSort(int arr[], int length)
{
	for (int i = length - 1; i != 0; --i) {       //sort in decreasing order
	    for (int j = 0; j != i; ++j) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	ifstream in("test.txt");
	ofstream out("test.txt");
	uniform_int_distribution<unsigned> u(0, 200000);
	default_random_engine e;
	for (size_t i = 0; i < 100000; ++i) {
		out << u(e) << " ";          //write random unsigned integer into the file
	}
	int N, num;
	cin >> N;      //determine the number of elements to test
	int k = N / 2;
	clock_t t;      //timing
	t = clock();
	for (int i = 0; i != N; ++i) {
		in >> num;              //read random unsigned interger from the file
		arr[i] = num;
	}
	BubleSort(arr, N);
	cout << arr[k - 1] << endl;
	t = clock() - t;
	cout << "It took " << static_cast<float>(t) / CLOCKS_PER_SEC << " seconds" << endl;    //output the running time 
	return 0;
}

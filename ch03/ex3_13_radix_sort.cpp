#include<iostream>
#include<algorithm>

size_t MaxBit(int a[],size_t N)
{
	int max = *std::max_element(a, a + N);
	size_t cnt = 0;
	while (max) {
		cnt++;
		max /= 10;
	}
	return cnt;
}

int DigitAt(int value, int d)
{
	return (value / static_cast<int>(pow(10, d))) % 10;
}

void RadixSort(int a[], size_t N)
{
	int cardinal = 10;
	int d = MaxBit(a, N);
	int* count = new int[cardinal + 1]();
	int* temp = new int[N]();
	for (int i = 0; i != d; ++i) {
		for (int j = 0; j != N; ++j)
			count[DigitAt(a[j], i) + 1]++;
		for (int j = 0; j != cardinal; ++j)
			count[j + 1] += count[j];
		for (int j = 0; j != N; ++j) 
			temp[count[DigitAt(a[j], i)]++] = a[j];
		for (int j = 0; j != N; ++j)
			a[j] = temp[j];
		std::fill_n(count, cardinal + 1, 0);
	}
	delete[] count;
	delete[] temp;
}

# Chapter 2: Algorithm Analysis
`Note: N^x(N is an unknown number, x is a digit) means the xth power of N`
## Exercise 2.1
Omitted(Because formulas are hard to write down here).
## Exercise 2.2
a. True. Because max{f(N),f(N)} = f(N)

b. False. Counterexample: T1(N) = 2N, T2(N) = N, so T1(N) - T2(N) = N = O(N) instead of o(N)

c. False. Counterexample: T1(N) = N^2, T2(N) = N, so T1(N)/T2(N) = O(N) instead of O(1)

d. False. Counterexample: T1(N) = N^2, T2(N) = N, so T1(N) = O(N^2) instead of O(T2(N))

## Exercise 2.3 ~ 2.4
Omitted(Because formulas are hard to write down here).

## Exercise 2.5
Let f(N) = 1 when N is even, and N when N is odd. Likewise, let g(N) = 1 when N is odd, and N when N is even. Then the ratio f(N)/g(N) oscillates between 0 and ∞. (`The limit oscillates: There is no relation`)

## Exercise 2.6

**a.Analysis of the running time**  
(1) The running time : O(N)   
(2) The running time : O(N^2)     
(3) The running time : O(N^3)    
(4) The running time : O(N^2)   (Because j can be as large as N)  
(5) The running time : O(N^5)   (Because j can be as large as i * i, which can be as large as N^2. k can be as large as j, which is N^2)  
(6) The running time : O(N^4)   (j can be as large as N^2, so the if statement is executed at most O(N^3) times, but the condition is true only O(N^2) times,only i times for each i)

**b.The running time for several values of N**(Forms are as follows)  

| N |1000000|10000000|100000000|                     
|---|----|-----|------|
|(1)|0.002|0.018|0.192|  

| N |1000|10000|100000|                     
|---|----|-----|------|
|(2)|0.002|0.193|19.175|

| N |100|200|400|                     
|---|----|-----|------|
|(3)|0.002|0.015|0.122|

| N |1000|10000|100000|                     
|---|----|-----|------|
|(4)|0.001|0.071|7.173|

| N |50|100|200|                     
|---|----|-----|------|
|(5)|0.042|1.396|44.178|

| N |100|200|400|                     
|---|----|-----|------|
|(6)|0.017|0.286|4.458|

**c.Compare analysis with the actual running times**  
The empirically observed running time matches the running time predicted
by the analysis.

## Exercise 2.7

**a. Prove**   
Obviously, all algorithms generate legal permutations. The first two algorithms test on no duplicates, and the third one guarantees that by shuffling an array that initially has no duplicates. It is also clear that each permutation is equally likely.

**b.Analysis of the running time**  
Algorithm-1 : O(N^2logN)  
Algorithm-2 : O(NlogN)    
Algorithm-3 : O(N)
   
**c.Execute programs**   
Code: [Algorithm-1](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_07_algorithm-1.cpp)    [Algorithm-2](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_07_algorithm-2.cpp)    [Algorithm-3](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_07_algorithm-3.cpp)

**d.Compare analysis with the actual running times**

| N |250|500|1000|2000|                     
|---|----|-----|------|----|
|Algorithm-1|0.001|0.006|0.028|0.113|

| N |2500|5000|10000|20000|40000|80000|                     
|---|----|-----|------|----|----|-----| 
|Algorithm-2|0.001|0.002|0.003|0.007|0.015|0.031|

| N |10000|20000|40000|80000|160000|320000|640000|                     
|---|----|-----|------|----|----|-----|----|
|Algorithm-2|0.001|0.002|0.003|0.005|0.009|0.019|0.038|

Consequently, the running times agree with the preceding analysis.

**e.The worst-case running time**  
Algorithm-1 and Algorithm-2: depend on the sequence of random numbers, so the running time can not be bounded.  
Algorithm-3: does not depend on the sequence of random numbers, so the worst-case running time is still linear.

## Exercise 2.8

Algorithm-1 :  
N = 10000 -> 5 days  
N = 100000 -> 14.2 years  
N = 1000000 -> 140 centuries

Algorithm-2 :    
N = 100000 -> 3 hours  
N = 1000000 -> 2 weeks

Algorithm-3 :  
N = 1000000 -> 1.5 minutes

Algorithm-4 :  
N = 1000000 -> 3 seconds

## Exercise 2.9

(a) O(N^2)  
(b) O(NlogN)

## Exercise 2.10

**a.Steps**  
4 -> 4X+8 -> 4X^2+8X+0 -> 4X^3+8X^2+1 -> 4X^4+8X^3+X+2

**b.Reason**  
This algorithm work by using their common divisor X.

**c.The running time**  
O(N)

## Exercise 2.11

Algorithm : [Binary Search](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_11_binary-search.cpp)  
The running time : O(logN)

## Exercise 2.12

**a.find the minimum subsequence sum**  
Algorithm : [a-algorithm](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_12_a-algorithm.cpp)  
The running time : O(N)  
Analysis : Just like the routine `Figure 2.8 Algorithm 4` in Section 2.4.3 

**b.find the minimum positive subsequence sum**  
Algorithm : [b-algorithm](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_12_b-algorithm.cpp)  
The running time : O(NlogN)  
Analysis :  
1. The algorithm is based on the principle that each subsequence([i,j]) sum is equal to sum[j] - sum[i] (sum[x] -> from index 0 add up to index x)  
2. Why we can just compare the neighbouring two items(data[i] and data[i-1])?   
For example, a sequence after sorting -> A B C. Then its value order : A < B < C. if B and C can't be a subsequence, it means index of C < index of B. We don't need to try A and C anymore, because if A and C can, index of A < index of C. It turns out that A and B also can be a subsequence(index of A < index of C < index of B).  C - A > B - A, so the sequence sum of A and C is larger than that of A and B. In conclusion, we just need to compare the neighbouring two items.

**c.find the maximum subsequence product**  
Algorithm : [c-algorithm](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_12_c-algorithm.cpp)  
The running time : O(N)  
Analysis : The algorithm is based on the principle that each maximum product is only associated with the the minimum/maximum of the previous value. 

## Exercise 2.13 

**a.Program**  
[Code](https://github.com/seineo/eData-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_13_judge-prime.cpp)

**b.The worst-case running time(N)**  
O(N^(1/2)) 

**c.the value of B**  
B = O(logN)

**d.The worst-case running time(B)**  
O(N^(B/2))

**e.Compare the running times**  
20-bit : 0.001  
40-bit : 0.002

**f.N or B?**  
I think B is better because it shows the actual space the data takes up.

## Exercise 2.14

Algorithm : [The Sieve of Erastothenes](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_14_Eratosthenes.cpp)  
The running time : O(NloglogN)

## Exercise 2.15

(1)X * X -> (2)X^2 * X^2 -> (3)X^4 * X^4 -> (4)X^8 * X^2 -> (5) X^10 * X^10 -> (6) x^20 * x^20 -> (7)X^40 * X^20 ->  
(8)X^60 * X^2

## Exercise 2.16

[Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_16_exponentiation.cpp)  
Principle : Binary system and bit operation
## Exercise 2.17
 
If N = 0 or N = 1, the number is zero.  
Let b(N) is the number of ones in the binary representation of N, if N > 1, the number is [log(N)] + b(N) - 1

## Exercise 2.18

a. A  
b. B  
c. We can't determine the answer because only worst-case running times are given.  
d. No

## Exercise 2.19

a. It should terminate when the length of A <= 2.  
b. If the first N - 1 elements have a candidate, then the last one doesn't make a difference. Otherwise, the last element may be the 		    majority, so let it be the candidate.  
c. O(N)  
d. Save a copy of A and place the elements of B in A.  
e. [Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_19_find-candidate.cpp)

## Exercise 2.20

If integers don't have fixed size, we can perform many operations at the same time by playing tricks. For example we can add A and B at the same time as C and D by adding 0A0C and 0B0D. We can extend this to add N pairs of numbers at once in unit cost, which prevent our analysis of the running time.

## Exercise 2.21

a. RCW  
b. Use binary search to check if the word is in the word list instead of traversing the whole word list. 

## Exercise 2.22

No, if the target is in the subarray to the right of the middle element, sometimes the loop never ends.

## Exercise 2.23

```cpp
bool BinarySearch(const std::vector<int>& v,int target)
{
	int mid,left = 0,right = v.size() - 1;
	while(left <= right) {
		mid = (left + right) / 2;
		if(v[mid] < target) {
			left = mid + 1;
		} else {
			if(v[mid == target])
				return true;
			right = mid - 1;
		}
	} 
	return false;
}
```

## Exercise 2.24

No, as in Exercise 2.22.

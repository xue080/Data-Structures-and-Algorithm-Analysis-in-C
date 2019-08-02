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
(1) The Running Time : O(N)   
(2) The Running Time : O(N^2)     
(3) The Running Time : O(N^3)    
(4) The Running Time : O(N^2)   (Because j can be as large as N)  
(5) The Running Time : O(N^5)   (Because j can be as large as i * i, which can be as large as N^2. k can be as large as j, which is N^2)  
(6) The Running Time : O(N^4)   (j can be as large as N^2, so the if statement is executed at most O(N^3) times, but the condition is true only O(N^2) times,only i times for each i)

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
Running time : O(logN)

## Exercise 2.12

**a.find the minimum subsequence sum**  
Algorithm : [a-algorithm](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch02/ex2_12_a-algorithm.cpp)  

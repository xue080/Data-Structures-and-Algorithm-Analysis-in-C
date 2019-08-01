# Chapter 2: Algorithm Analysis
`Note: Nx(N is an unknown number, x is a digit) means the xth power of N`
## Exercise 2.1
Omitted(Because formulas are hard to write down here).
## Exercise 2.2
a. True. Because max{f(N),f(N)} = f(N)

b. False. Counterexample: T1(N) = 2N, T2(N) = N, so T1(N) - T2(N) = N = O(N) instead of o(N)

c. False. Counterexample: T1(N) = N2(the square of N), T2(N) = N, so T1(N)/T2(N) = O(N) instead of O(1)

d. False. Counterexample: T1(N) = N2(the square of N), T2(N) = N, so T1(N) = O(N2) instead of O(T2(N))

## Exercise 2.3 ~ 2.4
Omitted(Because formulas are hard to write down here).

## Exercise 2.5
Let f(N) = 1 when N is even, and N when N is odd. Likewise, let g(N) = 1 when N is odd, and N when N is even. Then the ratio f(N)/g(N) oscillates between 0 and ∞. (`The limit oscillates: There is no relation`)

## Exercise 2.6

**a.Analysis of the Running Time**

(1) The Running Time : O(N) 

(2) The Running Time : O(N2)    

(3) The Running Time : O(N3)  

(4) The Running Time : O(N2)   (Because j can be as large as N)

(5) The Running Time : O(N5)   (Because j can be as large as i * i, which can be as large as N * N. k can be as large as j, which is N * N)

(6) The Running Time : O(N4)   (j can be as large as N * N, so the if statement is executed at most O(N3) times, but the condition is true only O(N2) times,only i times for each i)

**b.The Running Time for several values of N**(Forms are as follows)

| N |1000000|10000000|100000000|                     
|---|----|-----|------|
|(1)|0.002|0.018|0.192|

| N |1000|10000|100000|                     
|---|----|-----|------|
|(2)|0.002|0.193|19.175|

| N |100|200|400|                     
|---|----|-----|------|
|(3)|0.002|0.015|0.122|,

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






# Chapter 5: Hashing

## 5.3 ： Hash Table(Separate Chaining)

[hpp]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/hash_sep.h ) [cpp]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/hash_sep.cpp) [test]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/hash_sep_test.cpp )

## 5.4 ： Hash Table(Open Addressing)

[hpp]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/hash_open.h ) [cpp]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/hash_open.cpp) [test]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/hash_open_test.cpp)

***

## Exercise 5.1

**a.  open hash table**

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex5_01_a.png?raw=true)s

**b. closed hash table using linear probing**  

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex5_01_b.png?raw=true)

**c. closed hash table using quadratic probing**

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex5_01_c.png?raw=true)

**d. closed hash table with second hash function h2(x) = 7 - (x mod 7)**

![](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/Images/ex5_01_d.png?raw=true)

## Exercise 5.2

**a.  open hash table**  
4371 in list 1, 1323 in list 12, 6173 in list 17,  
4199 in list 0, 4344 in list 12, 9679 in list 8, and 1989 in list 13.

**b. closed hash table using linear probing**  
4371 in bucket 1, 1323 in bucket 12, 6173 in bucket 17,  
4199 in bucket 0, 4344 in bucket 14, 9679 in bucket 8, and 1989 in bucket 13.

**c. closed hash table using quadratic probing**  
4371 in bucket 1, 1323 in bucket 12, 6173 in bucket 17,   
4199 in bucket 0, 4344 in bucket 16, 9679 in bucket 8 and 1989 in bucket 13.

**d. closed hash table with second hash function h2(x) = 7 - (x mod 7)**   
4371 in bucket 1, 1323 in bucket 12, 6173 in bucket 17,   
4199 in bucket 0, 4344 in bucket 15, 9679 in bucket 8 and 1989 in bucket 13.
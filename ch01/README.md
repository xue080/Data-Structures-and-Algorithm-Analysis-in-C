#  Chapter 1: Introduction
## Exercise 1.1
> Write a program to solve the selection problem. Let k = n/2. Draw a table showing the running time of your program for various values of n.

[Algorithm-1](https://github.com/seineo/Solutions-for-Data-Structures-and-Algorithm-Analysis-in-C-2th-exercises/blob/master/ch01/ex1_01_algorithm-1.cpp)  
[Algorithm-2](https://github.com/seineo/Solutions-for-Data-Structures-and-Algorithm-Analysis-in-C-2th-exercises/blob/master/ch01/ex1_01_algorithm-2.cpp)

|   |100|1000|10000|100000|
|---|---|----|-----|------|
|Algorithm-1|0.001|0.005|0.251|26.741|
|Algorithm-2|0.001|0.004|0.077|6.734|

Obviously, when the number of elements are large, the running time of algorithm-2 is much shorter than that of algorithm-1.

## Exercise 1.2
> Write a program to solve the word puzzle problem.

[Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch01/ex1_02.cpp)

## Exercise 1.3
> Write a procedure to output an arbitrary real number (which might be
negative) using only print_digit for I/O.

[Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch01/ex1_03.cpp)

## Exercise 1.4
> C allows statements of the form
#include filename
which reads filename and inserts its contents in place of the include statement.
Include statements may be nested; in other words, the file filename may itself
contain an include statement, but, obviously, a file can't include itself in any
chain. Write a program that reads in a file and outputs the file as modified by
the include statements.

[Code](https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch01/ex1_04.cpp)

## Exercise 1.5 ~ 1.10
Omitted.(Because formulas are hard to write down here.)

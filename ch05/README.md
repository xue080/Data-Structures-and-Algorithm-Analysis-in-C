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

## Exercise 5.3

We define a static variable in class `Hash`  :

```c++
static size_t collision_times;   // declaration in class
size_t Hash::collision_times = 0;   //defination outside
```

In function `Find`, we add the following statements so as to know the number of collisions :(take the example of quadratic probing here)

```c++
collision_times += collision_num;
std::cout << "collision_times:" << collision_times << std::endl;
```

Generate random numbers to test collisions : 

```c++
int RandomInt(int lower, int upper)
{
	default_random_engine e(time(NULL));
	uniform_int_distribution<int> u(lower, upper);
	return u(e);
}

int main()
{
	Hash h(200);
	for (size_t i = 0; i != 100; ++i) {
		h.Insert(RandomInt(0, i));
	}
	return 0;
}
```

At last, we can get the table as follows :  

|                   | Linear probing | Quadratic probing | Double hashing |
| ----------------- | -------------- | ----------------- | -------------- |
| Collision times 1 | 746            | 179               | 109            |
| Collision times 2 | 863            | 255               | 84             |
| Collision times 3 | 1059           | 195               | 90             |

Obviously, linear probing is the slowest one and double hashing is the fastest one. 

## Exercise 5.4

Let p be the threshold(fraction of table size) at which we rehash to a new table. Let N be the size of original table, then the new table has size N / 2 which contains p * N elements. This new table will require rehashing after either N - p * N insertions or (p * N) / 2 deletions. Let the number of insertions equal to that of deletions, then we can get p = 2 / 3.

## Exercise 5.5

**a. Prove that this strategy can always resolve the collision**  
Since each table slot will be eventually probed, the collision can be resolved.

**b. Would this strategy be expected to eliminate clustering ?**  
No, because all elements that hash to the same location will try the same collision resolution sequence.

**c,d The expected time ?**  
Similar to quadratic probing

**e. Give an efficient algorithm  generate the random sequence**  

```c++
int RandInt(int beg,int end)        
{
	static default_random_engine generator(time(NULL));
	static uniform_int_distribution<int> distribution(beg,end);
	return distribution(generator);
}

void Swap(int* m,int* n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}
int main()
{
    vector<int> A;
	for(int i = 0;i != N;++i)
		A.push_back(i);
	for(int i = 1; i != N;++i)
		Swap(&A[i],&A[RandInt(0,i)]);
}
```

Actually, we have done this in [Exercise 2.7]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/tree/master/ch02#exercise-27 )(Check it for more details).

## Exercise 5.6

- **Separate chaining hashing**： Expensive because of dynamic memory allocation.
- **Linear probing**: Easily implemented, but performance degrades severely as the load factor increases because of primary clustering.
- **Quadratic probing**: Also easily implemented. Its performance is better than linear probing, but an insertion can fail if there are more than half elements in the table.
- **Double hashing**: Eliminate primary and secondary clustering, but the computation of the second hash function can be costly.

In conclusion, quadratic probing is the fastest method in practice.

## Exercise 5.7

We give main parts of program here.   
If you've forgotten the implementations of polynomial and hash table,check these:[Polynomial]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/tree/master/ch03#327-exercise--the-polynomial-adt ) [HashTable]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/tree/master/ch05#54--hash-tableopen-addressing )

```c++
#define Elemtype Node

Position HashFunc(Elemtype x, size_t size) { return x.expo % 17; }

Position Hash::Find(Elemtype x)
{
	Position p = HashFunc(x, hash_table->table_size);
	size_t collision_num = 0;
	while (hash_table->the_array[p].info != Empty && hash_table->the_array[p].data.expo != x.expo) {
		p += 2 * ++collision_num - 1;
		if (p > hash_table->table_size)
			p -= hash_table->table_size;
	}
	return p;
}

void Hash::Insert(Elemtype x)
{
	Position p = Find(x);
	if (hash_table->the_array[p].info != Legitimate) {
		hash_table->the_array[p].info = Legitimate;
		hash_table->the_array[p].data = x;
	}
	else {  //if found
		hash_table->the_array[p].data.expo += x.expo;
		hash_table->the_array[p].data.coeff *= x.coeff;
	}
}

Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2)
{
	Hash h(100);
	Node* mul1 = poly1.head->next;
	Node* product;
	while (mul1) {
		Node* mul2 = poly2.head->next;
		while (mul2) {
			product = new Node(mul1->coeff*mul2->coeff, mul1->expo + mul2->expo);
			h.Insert(*product);  //only O(1)
			mul2 = mul2->next;
		}
		mul1 = mul1->next;
	}
	Polynomial poly_product;
	Node* p = poly_product.head;
	for (size_t i = 0; i != h.hash_table->table_size; ++i) {  //insert nodes to polynomial (here we don't sort it,you can have a try)
		if (h.hash_table->the_array[i].info == Legitimate) {
			p->next = new Node(h.hash_table->the_array[i].data);
			p = p->next;
		}
	}
	p->next = nullptr;
	return poly_product;
}
```

## Exercise 5.8

The table size should be at least 60000 entries. Each entry holds about 8 bytes, so 480000 bytes in total.

## Exercise 5.9

**a.** True.

**b.** False, because it is possible that it just hashes to the same value as some other word in the dictionary.

**c.** 300007 / 8 = 37501.

**d.** 30000 words in a table of 300007, there is 10% chance that a word that is not in the dictionary hashes to a location with value 1.

**e.** Yes.

## Exercise 5.11

Actually, if we don't `% table_size` in hash function, we don't need to compare the strings character by character after we get a match of hash values.

```c++
size_t HashValue(string str)   
{
	size_t hash_value = 0;
	for(const auto& i : str) {
		hash_value = (hash_value << 5) + i; 
	}	
	return hash_value;   //not to `% table_size`
}

size_t StringMatching(string source,string target)
{
	size_t s_len = source.size();
	size_t t_len = target.size();
	size_t t_hash_value = HashValue(target);
	for(size_t i = 0;i + t_len <= s_len;++i) {
		string sub_str = source.substr(i,t_len);
		if(HashValue(sub_str) == t_hash_value) {
			return i;
		}
	}
	return s_len;   //if fail to match, return the length of string source.
}
```

## Exercise 5.12

[hash_table.h]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/ex5_12_hash_open.h ) [hash_table.cpp]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/ex5_12_hash_open.cpp) [main.cpp]( https://github.com/seineo/Data-Structures-and-Algorithm-Analysis-in-C/blob/master/ch05/ex5_12_main.cpp) 


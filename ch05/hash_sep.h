#ifndef _HASH_SEP_H
#define _HASH_SEP_H

#include<cmath>

using Position = struct ListNode*;
using List = Position;
using HashTable = struct HashTBL*;

#define Elemtype int
#define MinSize 5

struct ListNode {
	ListNode() :data(0), next(nullptr) {}
	ListNode(Elemtype x) :data(x), next(nullptr) {}

	Elemtype data;
	Position next;
};

struct HashTBL {
	HashTBL() = default;
	HashTBL(size_t size) {  //size >= 5
		table_size = NextPrime(size);
		the_lists = new List[table_size];
		for (size_t i = 0; i != table_size; ++i) {  //create dummy node
			the_lists[i] = new ListNode();
		}
	}
	~HashTBL() {
		for (size_t i = 0; i != table_size; ++i) {
			Position p = the_lists[i]->next;
			while (p != nullptr) {
				Position temp = p->next;
				delete p;
				p = temp;
			}
			delete the_lists[i];
		}
		delete[]the_lists;
	}

	size_t NextPrime(size_t num) {
		while (true) {
			if (isPrime(num))
				break;
			num++;
		}
		return num;
	}
	bool isPrime(size_t num) {
		if (num < 2)
			return false;
		for (size_t i = 2; i <= static_cast<size_t>(sqrt(num)); ++i) {
			if (num % i == 0)
				return false;
		}
		return true;
	}

	size_t table_size;
	List* the_lists;   //the array of list
};

class Hash {
public:
	Hash(size_t);
	Hash(const Hash&);
	Hash& operator=(Hash);
	~Hash();

	Position Find(Elemtype) const;
	void Insert(Elemtype);
	Elemtype Retrieve(Position) const;
	void Delete(Elemtype);
	size_t HashFunc(Elemtype x, size_t size) const { return x % size; }  
private:
	HashTable hash_table;
};
#endif // !_HASH_SEP_H

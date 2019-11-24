#ifndef _HASH_OPEN_H
#define _HASH_OPEN_H

#include<cmath>
#include<string>

#define MinSize 5

using Elemtype = std::string;
using Position = size_t;
using HashTable = struct HashTbl*;
using State = enum KindOfEntry;

enum KindOfEntry {
	Legitimate,
	Empty,
	Deleted
};

struct HashEntry {
	Elemtype data;
	State info;
};

struct HashTbl {
	HashTbl() = default;
	HashTbl(size_t size) {
		table_size = NextPrime(size);
		the_array = new HashEntry[table_size];
		for (size_t i = 0; i != table_size; ++i)
			the_array[i].info = Empty;
	}
	~HashTbl() {
		delete[]the_array;
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
	HashEntry* the_array;
};

class Hash {
public:
	Hash(size_t);
	Hash(const Hash&);
	Hash& operator=(Hash);
	~Hash();

	Position Find(Elemtype);
	void Insert(Elemtype);
	void Delete(Elemtype);
	Elemtype Retrieve(Position);
	Position HashFunc(Elemtype, size_t);
	void MakeEmpty();
	void Rehash();
	State GetPositionState(Position) const;

	HashTable hash_table;
};

#endif // !_HASH_OPEN_H
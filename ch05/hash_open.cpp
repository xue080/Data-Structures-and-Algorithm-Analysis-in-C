#include"hash_open.h"
#include<stdexcept>

Hash::Hash(size_t size)
{
	if (size < MinSize)
		throw std::runtime_error("Size too small");
	hash_table = new HashTbl(size);
}

Hash::Hash(const Hash& h)
{
	hash_table = new HashTbl(h.hash_table->table_size);
	for (size_t i = 0; i != hash_table->table_size; ++i) {
		hash_table->the_array[i].data = h.hash_table->the_array[i].data;
		hash_table->the_array[i].info = h.hash_table->the_array[i].info;
	}
}

Hash& Hash::operator=(Hash h)
{
	std::swap(hash_table, h.hash_table);
	return *this;
}

Hash::~Hash()
{
	MakeEmpty();
}

void Hash::MakeEmpty()
{
	if (hash_table != nullptr) {
		delete hash_table;
		hash_table = nullptr;
	}
}

Position Hash::Find(Elemtype x)
{
	Position p = HashFunc(x, hash_table->table_size);
	size_t collision_num = 0; 
	while (hash_table->the_array[p].info != Empty && hash_table->the_array[p].data != x) {
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
}

void Hash::Delete(Elemtype x)
{
	Position p = Find(x);
	if (hash_table->the_array[p].info == Legitimate) {
		hash_table->the_array[p].info = Deleted;
	}
}

Elemtype Hash::Retrieve(Position p)
{
	if (hash_table->the_array[p].info == Legitimate)
		return hash_table->the_array[p].data;
	throw std::runtime_error("Null pointer");
	return 0;
}

void Hash::Rehash()
{
	HashTable old_table = hash_table;
	hash_table = new HashTbl(2 * old_table->table_size);
	for (size_t i = 0; i != old_table->table_size; ++i) {
		if (old_table->the_array[i].info == Legitimate)
			Insert(old_table->the_array[i].data);
	}
	delete old_table;
}

State Hash::GetPositionState(Position p) const
{
	return hash_table->the_array[p].info;
}
#include"hash_sep.h"
#include<stdexcept>

Hash::Hash(size_t size)
{
	if (size < MinSize)
		throw std::runtime_error("Size too small");
	hash_table = new HashTBL(size);
}

Hash::Hash(const Hash& ht)   //debug
{
	hash_table = new HashTBL(ht.hash_table->table_size);
	for (size_t i = 0; i != hash_table->table_size; ++i) {
		Position to_copy = ht.hash_table->the_lists[i]->next;
		Position target = hash_table->the_lists[i];
		while (to_copy != nullptr) {
			target->next = new ListNode(to_copy->data);
			target = target->next;
			to_copy = to_copy->next;
		}
	}
}

Hash& Hash::operator=(Hash ht)
{
	std::swap(hash_table, ht.hash_table);
	return *this;
}

Hash::~Hash()
{
	MakeEmpty();
}

Position Hash::Find(Elemtype x) const
{
	List l = hash_table->the_lists[HashFunc(x, hash_table ->table_size)];
	Position p = l->next;
	while (p != nullptr && p->data != x) {
		p = p->next;
	}
	return p;
}

void Hash::Insert(Elemtype x)
{
	Position p, temp;
	List l;
	p = Find(x);
	if (p == nullptr) {
		temp = new ListNode(x);
		l = hash_table->the_lists[HashFunc(x, hash_table->table_size)];
		temp->next = l->next;
		l->next = temp;
	}
}

Elemtype Hash::Retrieve(Position p) const {
	if (p != nullptr) {
		return p->data;
	}
	throw std::runtime_error("Null pointer");
	return 0;
}

void Hash::Delete(Elemtype x)
{
	Position p;
	List l;
	p = Find(x);
	if (p != nullptr) {
		l = hash_table->the_lists[HashFunc(x, hash_table->table_size)];
		while (l->next->data != x) {
			l = l->next;
		}
		l->next = p->next;
		delete p;
		p = nullptr;
	}
}

void Hash::MakeEmpty()
{
	if (hash_table != nullptr) {
		delete hash_table->the_lists;
		delete hash_table;
		hash_table = nullptr;
	}
}
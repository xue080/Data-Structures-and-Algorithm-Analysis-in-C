#include"two_stacks.h"
#include<stdexcept>
#include<algorithm>

TwoStacks::TwoStacks(int max)
{
	if (max < MinStackSize)
		throw std::runtime_error("Stack size is two small");
	stacks = new StackRecord(max);
}

TwoStacks::TwoStacks(const TwoStacks& s)
{
	stacks = new StackRecord(s.stacks->capacity);
	std::copy(s.stacks->array, s.stacks->array + s.stacks->capacity,
		stacks->array);
	stacks->top_of_stack1 = s.stacks->top_of_stack1;
	stacks->top_of_stack2 = s.stacks->top_of_stack2;
}

TwoStacks& TwoStacks::operator=(TwoStacks s)
{
	std::swap(stacks, s.stacks);
	return *this;
}

TwoStacks::~TwoStacks()
{
	delete stacks->array;
	delete stacks;
}

void TwoStacks::MakeEmpty()
{
	stacks->top_of_stack1 = EmptyTOS;
	stacks->top_of_stack2 = stacks->capacity;
}

void TwoStacks::Push1(int x)
{
	if (IsFull())
		throw std::runtime_error("Full Stack1");
	stacks->array[++stacks->top_of_stack1] = x;
}

void TwoStacks::Push2(int x)
{
	if (IsFull())
		throw std::runtime_error("Full Stack2");
	stacks->array[--stacks->top_of_stack2] = x;
}

int TwoStacks::Top1() const
{
	if (!IsEmpty1())
		return stacks->array[stacks->top_of_stack1];
	throw std::runtime_error("Empty Stack1");
	return 0;
}

int TwoStacks::Top2() const
{
	if (!IsEmpty2())
		return stacks->array[stacks->top_of_stack2];
	throw std::runtime_error("Empty Stack2");
	return 0;
}

void TwoStacks::Pop1()
{
	if (IsEmpty1())
		throw std::runtime_error("Empty Stack1");
	stacks->top_of_stack1--;
}

void TwoStacks::Pop2()
{
	if (IsEmpty2())
		throw std::runtime_error("Empty Stack2");
	stacks->top_of_stack2++;
}

int TwoStacks::TopAndPop1()
{
	if (!IsEmpty1())
		return stacks->array[stacks->top_of_stack1--];
	throw std::runtime_error("Empty Stack1");
	return 0;
}

int TwoStacks::TopAndPop2()
{
	if (!IsEmpty2())
		return stacks->array[stacks->top_of_stack2++];
	throw std::runtime_error("Empty Stack2");
	return 0;
}

#include"stack_array.h"
#include<stdexcept>
#include<algorithm>

Stack::Stack(int max_elements)
{
	if (max_elements < MinStackSize)
		throw std::runtime_error("Stack size is too small");
	stack = new StackRecord(max_elements, EmptyTOS);
}

Stack::Stack(const Stack &s)
{
	stack = new StackRecord(s.stack->capacity, s.stack->top_of_stack);
	std::copy(s.stack->array, s.stack->array+s.stack->capacity, stack->array);
}

Stack& Stack::operator=(Stack s)
{
	using std::swap;
	swap(stack, s.stack);
	return *this;
}

Stack::~Stack()
{
	delete stack->array;
	delete stack;
}

void Stack::MakeEmpty()
{
	stack->top_of_stack = EmptyTOS;
}

void Stack::Push(int element)
{
	if (IsFull())
		throw std::runtime_error("Full Stack");
	else
		stack->array[++stack->top_of_stack] = element;
}

int Stack::Top() const
{
	if (!IsEmpty())
		return stack->array[stack->top_of_stack];
	throw std::runtime_error("Empty Stack");
	return 0;          //return value used to avoid warning
}

void Stack::Pop()
{
	if (IsEmpty())
		throw std::runtime_error("Empty Stack");
	stack->top_of_stack--;
}

int Stack::TopAndPop()
{
	if (!IsEmpty())
		return stack->array[stack->top_of_stack--];
	throw std::runtime_error("Empty Stack");
	return 0;
}

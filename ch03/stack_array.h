#ifndef _STACK_ARRAY_H
#define _STACK_ARRAY_H

constexpr int EmptyTOS = -1;
constexpr int MinStackSize = 5;

struct StackRecord {
	StackRecord() = default;
	StackRecord(int cap, int tos) :capacity(cap), top_of_stack(tos) { array = new int[capacity]; }
	
	int capacity;
	int top_of_stack;				
	int* array;
};

class Stack {
public:           //without I/O this time
	Stack(int);
	Stack(const Stack&);
	Stack& operator=(Stack);
	~Stack();

	bool IsEmpty() const { return stack->top_of_stack == EmptyTOS; }
	bool IsFull() const { return stack->top_of_stack == stack->capacity; }
	void MakeEmpty();
	void Push(int);
	int Top() const;
	void Pop();
	int TopAndPop();

private:
	StackRecord* stack;
};

#endif // !_STACK_ARRAY_H

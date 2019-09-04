#ifndef _TWO_STACKS_H
#define _TWO_STACKS_H

constexpr int EmptyTOS = -1;
constexpr int MinStackSize = 5;

struct StackRecord {
	StackRecord() = default;
	StackRecord(int max) :capacity(max), top_of_stack1(EmptyTOS), top_of_stack2(capacity)
			{ array = new int[capacity]; }

	int capacity;
	int top_of_stack1;
	int top_of_stack2;
	int* array;
};

class TwoStacks {
public:
	TwoStacks(int);
	TwoStacks(const TwoStacks&);
	TwoStacks& operator=(TwoStacks);
	~TwoStacks();

	bool IsEmpty1() const { return stacks->top_of_stack1 == EmptyTOS; }
	bool IsEmpty2() const { return stacks->top_of_stack2 == stacks->capacity; }
	bool IsFull() const { return stacks->top_of_stack1 + 1 == stacks->top_of_stack2; }
	void MakeEmpty();
	void Push1(int);
	void Push2(int);
	int Top1() const;
	int Top2() const;
	void Pop1();
	void Pop2();
	int TopAndPop1();
	int TopAndPop2();
private:
	StackRecord* stacks;
};
#endif // !_TWO_STACKS_H

#ifndef _STACK_H
#define _STACK_H

#include <vector>
#include <stdexcept>


template <typename T>
class Stack {
public:
	Stack();
	Stack(Stack const& rhs);
	Stack<T>& operator= (Stack<T> const& rhs);
	~Stack();
	void push(T const& element);
	void pop();
	T top() const;
	bool empty() const;
	unsigned int size() const;

private:
	std::vector<T> data;
};

#endif // !_STACK_H

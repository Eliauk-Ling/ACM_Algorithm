#include "Stack.h"

template <typename T>
Stack<T>::Stack(){}

template<typename T>
Stack<T>::Stack(Stack const& rhs) {
	data = rhs.data;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> const& rhs) {
	return data = rhs.data;
}

template <typename T>
Stack<T>::~Stack() = default;

template<typename T>
void Stack<T>::push(T const& element) {
	data.push_back(element);
}

template<typename T>
void Stack<T>::pop() {
	if (data.empty())
		throw std::out_of_range("Stack::pop()  empty stack");
	data.pop_back();
}

template<typename T>
T Stack<T>::top() const {
	if (data.empty())
		throw std::out_of_range("Stack<>::top()  empty stack");
	return data.back();
}

template<typename T>
bool Stack<T>::empty() const {
	if (data.empty())return true;
	else return false;
}

template<typename T>
unsigned int Stack<T>::size() const {
	return data.size();
}


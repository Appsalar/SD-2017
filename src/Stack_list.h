#pragma once
#include <stdio.h>
template <typename T>
struct Node
{
	T value;
	Node* next;
	Node(T value, Node* next)
	{
		this->value = value;
		this->next = next;
	}
};

template <typename T>
class Stack
{
private:
	Node<T>* pTop;

	void copy(const Stack&);
	void clear();
public:
	Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();

	void push(const T& value);
	void pop();
	T& top();

	bool empty() const;
};

#include "Stack_list_impl.h"
#pragma once
#include <stdio.h>
template <typename T>
class Stack
{
private:
	T* pArr;
	size_t size;
	size_t capacity;

	void copy(const Stack&);
	void resize(size_t);
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

#include "Stack_imp.h"
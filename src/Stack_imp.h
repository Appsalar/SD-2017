template <typename T>
Stack<T>::Stack()
{
	pArr = NULL;
	size = 0;
	capacity = 0;
}

// copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if(this != &other)
	{
		delete[] pArr;

		copy(other);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] pArr;
}


template <typename T>
void Stack<T>::push(const T& value)
{
	if(size == 0)
		resize(2);

	if(size == capacity)
		resize(2 * capacity);

	pArr[size] = value;
	++size;
}


template <typename T>
T& Stack<T>::top()
{
	if(size == 0)
		throw "360 NO SKOPE";
	return pArr[size - 1];
}

template <typename T>
void Stack<T>::pop()
{
	if(size == 0)
		throw "360 NO SKOPE";

	if(size < capacity / 4)
		resize(capacity / 2);

	--size;
}

template <typename T>
bool Stack<T>::empty() const
{
	return size == 0;
}

template <typename T>
void Stack<T>::resize(size_t newSize)
{
	T* tmp = new T[newSize];

	for(size_t i = 0; i < size; ++i)
		tmp[i] = pArr[i];

	delete[] pArr;
	pArr = tmp;
	capacity = newSize;
}


template <typename T>
void Stack<T>::copy(const Stack<T>& other)
{
	pArr = new T[other.capacity];
	for(size_t i = 0; i< other.size; ++i)
		pArr[i] = other.pArr[i];
	size = other.size;
	capacity = other.capacity;
}
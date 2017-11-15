template <typename T>
Stack<T>::Stack()
{
	pTop = NULL;
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
		clear();
		copy(other);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	clear();
}


template <typename T>
void Stack<T>::push(const T& value)
{
	Node<T>* tmp = new Node<T>(value, pTop);
	pTop = tmp;
}


template <typename T>
T& Stack<T>::top()
{
	if(pTop == NULL)
		throw "360 NO SKOPE";

	return pTop->value;
}

template <typename T>
void Stack<T>::pop()
{
	if(pTop == NULL)
		throw "360 NO SKOPE";

	Node<T>* toDelete = pTop;
	pTop = pTop->next;

	delete toDelete;
}

template <typename T>
bool Stack<T>::empty() const
{
	return pTop == NULL;
}


template <typename T>
void Stack<T>::copy(const Stack& other)
{
	pTop = new Node<T>(other.pTop->value, NULL);
	Node<T>* otherInd = other.pTop->next;
	Node<T>* thisInd = pTop;
	while(otherInd != NULL)
	{
		Node<T>* tmp = new Node<T>(otherInd->value, NULL);
		otherInd = otherInd->next;
		thisInd->next = tmp;
		thisInd = tmp;
	}
}

template <typename T>
void Stack<T>::clear()
{
	while(!empty())
	{
		Node<T>* toDelete = pTop;
		pTop = pTop->next;

		delete toDelete;
	}
}
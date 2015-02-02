#include "PriorityQueue.h"
#include <iostream>

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	data = new node[DEFAULT_SIZE];
	MaxSize = DEFAULT_SIZE;
	NoOfElements = 0;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete [] data;
}

template <typename T>
void PriorityQueue<T>::insert(int key, T value)
{
	data[++NoOfElements].key = key;
	data[NoOfElements].value = value;

	int child = NoOfElements, parent = child / 2;

	while (parent > 0 && data[parent].value > data[child].value)
	{
		swap(data[parent], data[child]);

		child = parent;
		parent = child / 2;
	}
}

template <typename T>
int PriorityQueue<T>::remove()
{
	int return_value = data[1].key;
	data[1] = data[NoOfElements--];

	int parent = 1, child = 2 * parent;

	while (child <= NoOfElements)
	{
		if (data[child + 1].value < data[child].value)
            child++;

		if (data[parent].value > data[child].value)
			swap(data[parent], data[child]);

		parent = child;
		child = 2 * parent;
	}

	return return_value;
}

template <typename T>
void PriorityQueue<T>::Print()
{
	std::cout << "PQ: ";
	for (int i = 1; i <= NoOfElements; i++)
		std::cout << data[i].key << " ";

	std::cout << "\n";
}

template <typename T>
bool PriorityQueue<T>::isEmpty()
{
	return (NoOfElements == 0);
}

template class PriorityQueue<int>;
template class PriorityQueue<float>;
template class PriorityQueue<double>;
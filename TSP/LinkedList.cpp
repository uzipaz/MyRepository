#include "LinkedList.h"
#include "Vertex.h"

template <typename T>
LinkedList<T>::LinkedList()
{
	this->head = 0;
	this->current = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	node *temp;
	while (head != 0)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <typename T>
void LinkedList<T>::insert(T& data)
{
	node *temp = new node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

template <typename T>
void LinkedList<T>::remove()
{
	if (head != 0)
	{
		node* temp = head;
		head = head->next;

		//T return_value = temp->data;
		delete temp;

		//return return_value;
	}

	//return NULL;
}

template <typename T>
void LinkedList<T>::remove(T& data)
{
	bool found = false;
	node *ahead = head, *prev = 0;

	while (ahead != 0 && !found)
	{
		if (ahead->data == data)
		{
			prev = ahead->next;
			delete ahead;
			found = true;
		}

		prev = ahead;
		ahead = ahead->next;
	}
}

template <typename T>
void LinkedList<T>::begin()
{
	current = head;
}

template <typename T>
void LinkedList<T>::next()
{
	current = current->next;
}

template <typename T>
T LinkedList<T>::getCurrent()
{
	return current->data;
}

template <typename T>
bool LinkedList<T>::end()
{
	return current == 0;
}

template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<edge>;

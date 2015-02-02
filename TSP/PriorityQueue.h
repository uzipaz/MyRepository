#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

/* 01-28-2014
Priority Queue with a binary heap implementation
values in decreasing order will be given higher priority because of use of this data structure in shortest path problems
*/

#include "miscellaneous.h"

const int DEFAULT_SIZE = 9999;

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	void insert(int key, T value);
	int remove();

	bool isEmpty();

	void Print();
private:
	struct node
	{
		int key;
		T value;
	};

	node* data;
	int NoOfElements;
	int MaxSize;
};

#endif

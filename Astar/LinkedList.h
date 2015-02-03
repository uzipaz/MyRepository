#ifndef LINKEDLIST
#define LINKEDLIST

/* 02-03-2014
Behaves like a stack
insert, remove behaves similiar to a insert, remove in a stack
*/

//#include "miscellaneous.h"

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void insert(T& data);
	void remove(); // Remove in LIFO order
	void remove(T& data); // Search and Remove

	void begin();
	void next();
	T getCurrent();
	bool end();

private:
	struct node
	{
		T data;
		node* next;
	};

	node* head;
	node* current; // for iterating purposes
};

#endif

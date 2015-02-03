#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "ArrayList.h"

template <class T>
class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    void insert(int element, T priority);

    int remove();

    bool isEmpty();

    int getLowestCostElement();
    int getHighestCostElement();

    //void Print();

private:
    //inline void swap(int* x, int* y);
    //inline int findMin(int x, int y);

    ArrayList<int> elements;
    ArrayList<T> priorities;
    int CurrentSize;
};

#endif // PRIORITYQUEUE_H_INCLUDED

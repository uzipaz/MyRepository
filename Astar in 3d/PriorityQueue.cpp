#include "PriorityQueue.h"

#include <iostream>
using namespace std;

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    CurrentSize = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    // Do nothing
}

template <class T>
void PriorityQueue<T>::insert(int element, T priority)
{
    bool found = false;
    int i;

    for (i = CurrentSize - 1; !found && i >= 0; i--)
    {
        if (priority > priorities[i])
        {
            elements[i + 1] = elements[i];
            priorities[i + 1] = priorities[i];
        }

        else
        {
            found = true;
            i++;
        }
    }

    elements[i + 1] = element;
    priorities[i + 1] = priority;

    CurrentSize++;

    /*int parent, index;

    CurrentSize++;

    index = CurrentSize - 1;

    elements[index] = element;
    priorities[index] = priority;

    parent = (index - 1) / 2;

    while (index != 0)
    {
        if (priorities[parent] >= priorities[index])
        {
            swap(&elements[parent], &elements[index]);
            swap(&priorities[parent], &priorities[index]);
        }

        index = parent;
        parent = (index - 1) / 2;
    }*/
}

template <class T>
int PriorityQueue<T>::remove()
{
    /*int index = 0, child;
    int returnValue = elements[index];

    elements[0] = elements[CurrentSize - 1];
    priorities[0] = priorities[CurrentSize - 1];
    CurrentSize--;

    int left = (2 * index) + 1, right = (2 * index) + 2;

    while (index != CurrentSize)
    {
        if (priorities[left] <= priorities[right])
            child = left;

        else child = right;

        if (priorities[index] >= priorities[child])
        {
            swap(&elements[child], &elements[index]);
            swap(&priorities[child], &priorities[index]);
        }

        index = child;
        left = (2 * index) + 1;
        right = (2 * index) + 2;
    }*/

    //return returnValue;
        return elements[--CurrentSize];
}

template <class T>
bool PriorityQueue<T>::isEmpty()
{
    return (CurrentSize == 0);
}

template <class T>
int PriorityQueue<T>::getLowestCostElement()
{
    return elements[CurrentSize - 1];
    //return elements[0];
}

template <class T>
int PriorityQueue<T>::getHighestCostElement()
{
    return elements[0];
    //return elements[CurrentSize - 1];
}

/*inline void PriorityQueue::swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

inline int PriorityQueue::findMin(int x, int y)
{
    if (x <= y)
        return x;

    return y;
}

void PriorityQueue::Print()
{
    for (int i = 0; i < CurrentSize; i++)
        cout << elements[i] << " ";

    cout << "\n";
}*/

template class PriorityQueue<int>;
template class PriorityQueue<float>;

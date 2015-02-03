#ifndef MISCELLANEOUS_H_INCLUDED
#define MISCELLANEOUS_H_INCLUDED

template <class T>
void insertSort(T* data, int size)
{
    T temp;
    for (int i = 1, j; i < size; i++)
    {
        temp = data[i];
        for (j = i - 1; j >= 0 && temp < data[j]; j--)
            data[j + 1] = data[j];

        data[j + 1] = temp;
    }
}

template <class T>
void swap(T* a, T* b)
{
    T* temp = *a;
    *a = *b;
    *b = *temp;
}

#endif // MISCELLANEOUS_H_INCLUDED

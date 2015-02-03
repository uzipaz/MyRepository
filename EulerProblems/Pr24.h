#ifndef PR24_H_INCLUDED
#define PR24_H_INCLUDED

#include "miscellaneous.h"

#include <iostream>

class Pr24
{
public:
    Pr24(int* arr, int size)
    {
        this->arr = arr;
        this->size = size;
    }

    int getResult(int n)
    {
        int k, l, t = 2;
        bool found, end = false;

        long long int result;

        do
        {
            found = false;
            for (k = size - 2; k >= 0 && !found; k--)
                if (arr[k] < arr[k + 1])
                {
                    found = true;
                    k++;
                }

            if (found)
            {
                found = false;

                for (l = size - 1; l > k && !found; l--)
                        if (arr[k] < arr[l])
                        {
                            found = true;
                            l++;
                        }

                swap(arr[l], arr[k]);

                for (int i = size - 1, j = k + 1; i > k + 1; i--, j++)
                    swap(arr[i], arr[j]);

                /*result = 0;
                for (int i = size - 1, j = 1; i >= 0; i--, j = j * 10)
                    result = result + arr[i] * j;

                std::cout << result;
                cin.get();*/
            }

            else end = true;

            t++;
        } while (!end && t <= n);

        //std::cout << t - 1;

        result = 0;
        for (int i = size - 1, j = 1; i >= 0; i--, j = j * 10)
        {
            std::cout << arr[size - 1 - i];
            result = result + arr[i] * j;
        }

        std::cout << '\n';

        return result;
    }

    ~Pr24()
    {
       // if (arr != 0)
            //delete [] arr;
    }

private:
    int* arr;
    int size;
};

#endif // PR24_H_INCLUDED

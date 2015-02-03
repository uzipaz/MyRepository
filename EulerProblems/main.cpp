#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

#include "Pr21.h"
#include "Pr22.h"
#include "Pr19.h"
#include "Pr22_2.h"
#include "Pr24.h"

#include "miscellaneous.h"

int main()
{
    clock_t start;
    double duration;

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 10;

    Pr24 p(arr, size);

    start = clock();
    int result = p.getResult(6);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    cout << "Total computation time is " << duration << " sec\n";
    cout << "The result is " << result << '\n';

    /*int arr[] = {1, 2, 6, 4, 5, 3};
    int size = 6;

    insertSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';*/

    return 0;
}

#ifndef PR22_H_INCLUDED
#define PR22_H_INCLUDED

#include <iostream>
using namespace std;

#include <fstream>

class Pr22
{
public:
    Pr22()
    {
        int n, i = 1;

        fin.open("data_pr22.txt");
        fin >> lines;

        totalSize = ((lines * (lines + 1)) / 2);
        numbers = new int[totalSize + 1];

        while (!fin.eof())
        {
            fin >> n;
            numbers[i] = n;
            i++;
        }
    }

    int getResult()
    {
        int i, left, right, currentLines = lines - 1, counter = 1;

        for (i = totalSize - lines; i >= 1; i--)
        {
            left = i + currentLines;
            right = left + 1;

            if (counter < currentLines)
                counter++;

            else
            {
                currentLines--;
                counter = 1;
            }

            if (numbers[left] > numbers[right])
                numbers[i] = numbers[i] + numbers[left];

            else numbers[i] = numbers[i] + numbers[right];
        }

        return numbers[1];
    }

    ~Pr22()
    {
        delete [] numbers;
    }

private:
    ifstream fin;
    int *numbers;
    int lines;
    int totalSize;
};

#endif // PR22_H_INCLUDED

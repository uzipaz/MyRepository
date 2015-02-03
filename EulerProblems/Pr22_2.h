#ifndef PR22_2_H_INCLUDED
#define PR22_2_H_INCLUDED

#include "EnglishWord.h"
#include "miscellaneous.h"

#include <iostream>
using namespace std;

#include <fstream>

const int TOTAL_WORDS = 5163;

class Pr22_2
{
public:
    Pr22_2()
    {
        size = TOTAL_WORDS;
        ifstream fin;
        fin.open("p022_names.txt");

        char *str = new char[201];
        words = new EnglishWord[size];
        int i = 0;

        while (!fin.eof())
        {
            fin.getline(str, 200, ' ');
            words[i].setWord(str);
            i++;
        }
    }

    int getResult()
    {
        insertSort(words, size);

        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + (words[i].getValue() * (i+1));
        }

        return sum;
    }

    ~Pr22_2()
    {
        delete [] words;
    }

private:
    EnglishWord *words;
    int size;
};

#endif // PR22_2_H_INCLUDED

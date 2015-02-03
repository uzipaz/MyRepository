#ifndef ENGLISHWORD_H_INCLUDED
#define ENGLISHWORD_H_INCLUDED

#include <cstring>
#include <iostream>

class EnglishWord
{
public:
    EnglishWord();
    EnglishWord(const EnglishWord&);
    EnglishWord(const char* str);

    const EnglishWord& operator=(const EnglishWord&);

    bool operator<(const EnglishWord&);
    bool operator<=(const EnglishWord&);

    bool operator==(const EnglishWord&);

    bool operator>(const EnglishWord&);
    bool operator>=(const EnglishWord&);

    void setWord(const EnglishWord&);
    void setWord(const char* str);
    void print();

    int getValue();

    ~EnglishWord();
private:
    char *word;
    int length;
};

#endif // ENGLISHWORD_H_INCLUDED

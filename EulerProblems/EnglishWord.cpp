#include "EnglishWord.h"

EnglishWord::EnglishWord()
{
    word = 0;
    length = 0;
}

EnglishWord::EnglishWord(const char* str)
{
    word = 0;
    length = 0;
    this->setWord(str);
}

EnglishWord::EnglishWord(const EnglishWord& rhs)
{
    word = 0;
    length = 0;
    *this = rhs;
}

void EnglishWord::setWord(const EnglishWord& rhs)
{
    *this = rhs;
}

void EnglishWord::setWord(const char* str)
{
    length = strlen(str);
    word = new char[length + 1];

    for (int i = 0; i < length; i++)
        word[i] = str[i];

    word[length] = '\0';
}

const EnglishWord& EnglishWord::operator=(const EnglishWord& rhs)
{
    if (this->word != 0)
    {
        delete [] this->word;
        this->word = 0;
    }

    if (rhs.word != 0)
    {
        length = strlen(rhs.word);
        word = new char[length + 1];

        for (int i = 0; i < length; i++)
            word[i] = rhs.word[i];

        word[length] = '\0';
    }

    return *this;
}

void EnglishWord::print()
{
    std::cout << word;
}

EnglishWord::~EnglishWord()
{
    if (this->word != 0)
        delete [] this->word;
}

bool EnglishWord::operator==(const EnglishWord& rhs)
{
    if (this->length != rhs.length)
        return false;

    for (int i = 0; i < rhs.length; i++)
        if (this->word[i] != rhs.word[i])
            return false;

    return true;
}

bool EnglishWord::operator<(const EnglishWord& rhs)
{
    int min_len;

    min_len = this->length;
    if (min_len > rhs.length)
        min_len = rhs.length;

    //std::cout << this->word << " " << rhs.word << '\n';

    for (int i = 0; i < min_len; i++)
    {
        if (this->word[i] < rhs.word[i])
            return true;

        else if (this->word[i] > rhs.word[i])
            return false;
    }

    if (this->length < rhs.length)
        return true;

    else return false;
}

bool EnglishWord::operator<=(const EnglishWord& rhs)
{
    int min_len;

    min_len = this->length;
    if (min_len > rhs.length)
        min_len = rhs.length;

    for (int i = 0; i < min_len; i++)
    {
        if (this->word[i] < rhs.word[i])
            return true;

        else if (this->word[i] > rhs.word[i])
            return false;
    }

    if (this->length <= rhs.length)
        return true;

    else return false;
}

bool EnglishWord::operator>(const EnglishWord& rhs)
{
    int min_len;

    min_len = this->length;
    if (min_len > rhs.length)
        min_len = rhs.length;

    for (int i = 0; i < min_len; i++)
    {
        if (this->word[i] < rhs.word[i])
            return false;

        else if (this->word[i] > rhs.word[i])
            return true;
    }

    if (this->length > rhs.length)
        return true;

    else return false;
}

bool EnglishWord::operator>=(const EnglishWord& rhs)
{
    int min_len;

    min_len = this->length;
    if (min_len > rhs.length)
        min_len = rhs.length;

    for (int i = 0; i < min_len; i++)
    {
        if (this->word[i] < rhs.word[i])
            return false;

        else if (this->word[i] > rhs.word[i])
            return true;
    }

    if (this->length >= rhs.length)
        return true;

    else return false;
}

int EnglishWord::getValue()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
            sum = sum + word[i] - 'a' + 1;

        else if (word[i] >= 'A' && word[i] <= 'Z')
            sum = sum + word[i] - 'A' + 1;
    }

    return sum;
}

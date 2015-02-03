#ifndef PR21_H_INCLUDED
#define PR21_H_INCLUDED

class Pr21
{
public:
    Pr21(int SumLessThan)
    {
        this->SumLessThan = SumLessThan;
    }

    int getResult()
    {
        int sum = 0, a;
        for (int i = SumLessThan - 1; i >= 1; i--)
        {
            a = getTotalSumOfDivisors(i);
            if (a < SumLessThan)
                if (getTotalSumOfDivisors(a) == i && a != i)
                    sum = sum + i;
        }

        return sum;
    }

private:
    int getTotalSumOfDivisors(int n)
    {
        int j = n / 2, sum = 1;
        for (int i = 2; i <= j; i++)
            if (n % i == 0)
                sum = sum + i;

        return sum;
    }

    int SumLessThan;
};

#endif // PR21_H_INCLUDED

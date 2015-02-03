#ifndef PR19_H_INCLUDED
#define PR19_H_INCLUDED

#include <iostream>
using namespace std;

class Pr19
{
public:
    Pr19()
    {
        to_year = 2000;
        to_day = 366;
        from_year = 1901;
        from_day = 6;
    }

    int getResult()
    {
        int YearDays, sum = 0;

        const int NormalYearDays = 365;
        const int LeapYearDays = 366;
        int MonthDayNumber[] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
        int CurrentMonthDayNumber[12];

        for (int i = from_year, j = from_day; i <= to_year; i++)
        {
            if (i % 4 == 0)
            {
                if (i % 100 == 0 && i % 400 != 0)
                {
                    YearDays = NormalYearDays;
                    for (int k = 0; k < 12; k++)
                        CurrentMonthDayNumber[k] = MonthDayNumber[k];
                }

                else
                {
                    YearDays = LeapYearDays;

                    for (int k = 2; k < 12; k++)
                        CurrentMonthDayNumber[k] = MonthDayNumber[k] + 1;
                    CurrentMonthDayNumber[0] = MonthDayNumber[0];
                    CurrentMonthDayNumber[1] = MonthDayNumber[1];
                }
            }

            else
            {
                YearDays = NormalYearDays;
                for (int k = 0; k < 12; k++)
                    CurrentMonthDayNumber[k] = MonthDayNumber[k];
            }

            while (j <= YearDays)
            {
                for (int k = 0; k < 12; k++)
                    if (CurrentMonthDayNumber[k] == j)
                        sum = sum + 1;

                j = j + 7;
            }

            j = j % YearDays;
        }

        return sum;
    }

    ~Pr19()
    {
    }

private:
    int to_year;
    int to_day;
    int from_year;
    int from_day;
};

#endif // PR19_H_INCLUDED

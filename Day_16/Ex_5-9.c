#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);

int main()
{
    int year = 2023;
    int month = 6;
    int day = 15;

    int yearday = day_of_year(year, month, day);
    printf("Day of the year: %d\n", yearday);

    int retrieved_month, retrieved_day;
    month_day(year, yearday, &retrieved_month, &retrieved_day);
    printf("Month: %s, Day: %d\n", month_name(retrieved_month), retrieved_day);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    char *p = *(daytab + leap);

    while (--month)
        day += *++p;
    
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    char *p = *(daytab + leap);

    while (yearday > *++p)
        yearday -= *p;
    
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

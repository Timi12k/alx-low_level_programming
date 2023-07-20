#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 * Return: void
 */

void print_remaining_days(int month, int day, int year)
{
	int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day_of_year = day;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		if (month > 2)
		{
			day++;
		}
		else if (month == 2 && day == 29)
		{
			printf("Day of the year: %d\n", day);
			printf("Remaining days: %d\n", 366 - day);
			return;
		}
	}
	else if (month == 2 && day == 29)
	{
		printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
		return;
	}

	for (int i = 1; i < month; i++)
	{
		day_of_year += days_in_month[i];
	}

	printf("Day of the year: %d\n", day_of_year);
	printf("Remaining days: %d\n", (is_leap_year(year) ? 366 : 365) - day_of_year);
}

/**
 * is_leap_year - checks if a year is a leap year
 * @year: the year to check
 * Return: 1 if it's a leap year, 0 otherwise
 */
int is_leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

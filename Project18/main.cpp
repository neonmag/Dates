#include <iostream>
#include "CDate.h"

using namespace std;

void EnterYear(int& year)			// Enter year
{
	cout << "Enter year: ";
	cin >> year;
	while (year < 0)
	{
		cout << "\nEnter year: ";
		cin >> year;
	}
}

void EnterMonth(int& month)			//Enter month
{
	cout << "\nEnter month: ";
	cin >> month;
	while (month < 0 || month > 12)
	{
		cout << "\nEnter month: ";
		cin >> month;
	}
}

void EnterDay(int& day,int month,int year) // Enter day with check on Leap Year
{
	cout << "\nEnter day: ";
	cin >> day;
	if (year % 4 == 0 && month == 2)
	{
		while (day > 29 || day < 0)
		{
			cout << "\nEnter day: ";
			cin >> day;
		}
	}
	else if (year % 4 != 0 || month == 2)
	{
		while (day > 28 || day < 0)
		{
			cout << "\nEnter day: ";
			cin >> day;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		while (day > 31 || day < 0)
		{
			cout << "\nEnter day: ";
			cin >> day;
		}
	}
	else
	{
		while (day > 30 || day < 0)
		{
			cout << "\nEnter day: ";
			cin >> day;
		}
	}
}


int main()
{
	/*int day;
	int month;
	int year;
	EnterYear(year);
	EnterMonth(month);
	EnterDay(day, month, year);
	system("cls");*/
//	CDate date(day, month, year);
	CDate date(23, 3, 2000);
	date.PrintDate();
	CDate date2(22, 2, 2020);
	date2.PrintDate();
	cout << "\n";
	int degree = date2 - date;
	cout << "\nDegree: " << degree;
	CDate date3 = date2 + 45;
	date3.PrintDate();
	CDate date4 = date3++;
	date4.PrintDate();
	CDate date5 = date4--;
	date5.PrintDate();
	if (date5 > date4)
	{
		cout << "\nDate 5 bigger than 4";
	}
	else if (date5 < date4)
	{
		cout << "\nDate 4 bigger than 5";
	}
	if (date5 == date3)
	{
		cout << "\nThey are equal";
	}
	if (date5 != date4)
	{
		cout << "\nThey aren't equal";
	}
	cout << date5.DayOfWeek();
}
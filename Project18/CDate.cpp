#include "CDate.h"

CDate::CDate()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

CDate::CDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void CDate::PrintDate()
{
	//Check(this->day, this->month, this->year);
	cout << "\n" << this->day << "." << this->month << "." << this->year;
}

void CDate::Check(int day, int month, int year)
{
	while (this->year < 0)
	{
		cout << "\nEnter year: ";
		cin >> this->year;
	}
	while (this->month < 0 || this->month > 12)
	{
		cout << "\nEnter month: ";
		cin >> this->month;
	}
	if (this->year % 4 == 0 && this->month == 2)
	{
		while (this->day > 29 || this->day < 0)
		{
			cout << "\nEnter day: ";
			cin >> this->day;
		}
	}
	else if (this->year % 4 != 0 || this->month == 2)
	{
		while (this->day > 28 || this->day < 0)
		{
			cout << "\nEnter day: ";
			cin >> this->day;
		}
	}
	else if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 ||
		this->month == 8 || this->month == 10 || this->month == 12)
	{
		while (this->day > 31 || this->day < 0)
		{
			cout << "\nEnter day: ";
			cin >> this->day;
		}
	}
	else
	{
		while (this->day > 30 || this->day < 0)
		{
			cout << "\nEnter day: ";
			cin >> this->day;
		}
	}
}

char* CDate::DayOfWeek() const
{
	int counter = 1;
	for (int i = 0; i < this->year; i++)
	{
		counter++;
		if (counter == 8)
		{
			counter = 1;
		}
	}
	char* ptr = new char[20];
	switch (counter)
	{
	case 1:
		strcpy_s(ptr, 19, "\nMonday");
		break;
	case 2:
		strcpy_s(ptr, 19, "\nTuesday");
		break;
	case 3:
		strcpy_s(ptr, 19, "\nWednesday");
		break;
	case 4:
		strcpy_s(ptr, 19, "\nThursday");
		break;
	case 5:
		strcpy_s(ptr, 19, "\nFriday");
		break;
	case 6:
		strcpy_s(ptr, 19, "\nSaturday");
		break;
	case 7:
		strcpy_s(ptr, 19, "\nSunday");
		break;
	}
	return ptr;
}

int CDate::operator -(CDate b)
{
	int sum = 0;
	for (int i = b.year; i <= year; i++)
	{
		if (i == b.year)
		{
			for (int j = 1; j <= month; j++)
			{
				if (j == 1 || j == 3 || j == 5 || j == 7 ||
					j == 8 || j == 10 || j == 12)
				{
					sum += 31;
				}
				else if (i % 4 == 0 && j == 2)
				{
					sum += 29;
				}
				else if (i % 4 == 0 && j == 2)
				{
					sum += 28;
				}
				else
				{
					sum += 30;
				}
			}
		}
		else if (i != b.year)
		{
			for (int j = 1; j <= 12; j++)
			{
				if (j == 1 || j == 3 || j == 5 || j == 7 ||
					j == 8 || j == 10 || j == 12)
				{
					sum += 31;
				}
				else if (i % 4 == 0 && j == 2)
				{
					sum += 29;
				}
				else if (i % 4 == 0 && j == 2)
				{
					sum += 28;
				}
				else
				{
					sum += 30;
				}
			}
		}
	}
	return sum;
}

void CDate::SetDay(const int day)
{
	this->day = day;
}

void CDate::SetMonth(const int month)
{
	this->month = month;
}

void CDate::SetYear(const int year)
{
	this->year = year;
}

int CDate::GetDay()
{
	return this->day;
}

int CDate::GetMonth()
{
	return this->month;
}

int CDate::GetYear()
{
	return this->year;
}

CDate CDate::operator+(int a)
{
	CDate c;
	day += a;
	for (int i = month; i <= 12; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 ||
			i == 8 || i == 10 || i == 12)
		{
			day -= 31;
			if (month == 13)
			{
				month = 0;
			}
			month++;
			if (day < 31)
			{
				c.year = year;
				c.month = month;
				c.day = day;
				return c;
			}
		}
		else if (year % 4 == 0 && i == 2)
		{
			day -= 29;
			if (month == 13)
			{
				month = 0;
			}
			month++;
			if (day < 29)
			{
				c.year = year;
				c.month = month;
				c.day = day;
				return c;
			}
		}
		else if (year % 4 == 1 && i == 2)
		{
			day -= 28;
			if (month == 13)
			{
				month = 0;
			}
			month++;
			if (day < 28)
			{
				c.year = year;
				c.month = month;
				c.day = day;
				return c;
			}
		}
		else
		{
			day -= 30;
			if (month == 13)
			{
				month = 0;
			}
			month++;
			if (day < 30)
			{
				c.year = year;
				c.month = month;
				c.day = day;
				return c;
			}

		}
	}
}

CDate CDate::operator++(int)
{
	this->day++;
	if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 ||
		this->month == 8 || this->month == 10 || this->month == 12)
	{
		if (this->day > 31)
		{
			this->day = 1;
			this->month++;
			if (this->month == 13)
			{
				this->month = 1;
			}
		}
	}
	else if (this->year % 4 == 0 && this->month == 2)
	{
		if (this->day == 30)
		{
			this->day = 1;
			this->month++;
		}
	}
	else if (this->year % 4 == 1 && this->month == 2)
	{
		if (this->day == 29)
		{
			this->day = 1;
			this->month++;
		}
	}
	else
	{
		if (this->day == 31)
		{
			this->day = 1;
			this->month++;
		}
	}
	return *this;
}

CDate CDate::operator--(int)
{
	this->day--;
	if (this->day == 0)
	{
		this->month--;
	}
	if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 ||
		this->month == 8 || this->month == 10 || this->month == 12)
	{
		this->day == 31;
	}
	else if (this->year % 4 == 0 && this->month == 2)
	{
		this->day == 29;
	}
	else if (this->year % 4 == 1 && this->month == 2)
	{
		this->day == 28;
	}
	else
	{
		this->day == 30;
	}
	return *this;
}

bool CDate::operator>(CDate b)
{
	if (this->year > b.year)
	{
		cout << "\nRight bigger than left";
		return true;
	}
	else if (this->year < b.year)
	{
		cout << "\nLeft bigger than right";
		return false;
	}
	else
	{
		if (this->month > month)
		{
			cout << "\nRight bigger than left";
			return true;
		}
		else if (this->month < b.month)
		{
			cout << "\nLeft bigger than right";
			return false;
		}
		else
		{
			if (this->day > b.day)
			{
				cout << "\nRight bigger than left";
				return true;
			}
			else if(this->day < b.day)
			{
				cout << "\nLeft bigger than right";
				return false;
			}
			else
			{
				cout << "\nThey are the same";
				return false;
			}
		}
	}
}

bool CDate::operator<(CDate b)
{
	if (this->year < b.year)
	{
		cout << "\nRight bigger than left";
		return true;
	}
	else if (this->year > b.year)
	{
		cout << "\nLeft bigger than right";
		return false;
	}
	else
	{
		if (this->month < month)
		{
			cout << "\nRight bigger than left";
			return true;
		}
		else if (this->month > b.month)
		{
			cout << "\nLeft bigger than right";
			return false;
		}
		else
		{
			if (this->day < b.day)
			{
				cout << "\nRight bigger than left";
				return true;
			}
			else if (this->day > b.day)
			{
				cout << "\nLeft bigger than right";
				return false;
			}
			else
			{
				cout << "\nThey are the same";
				return false;
			}
		}
	}
}

bool CDate::operator==(CDate b)
{
	if (this->year == b.year)
	{
		if (this->month == b.month)
		{
			if (this->day == b.day)
			{
				return true;
			}
		}
	}
	return false;
}

bool CDate::operator!=(CDate b)
{
	if (this->year == b.year)
	{
		if (this->month == b.month)
		{
			if (this->day == b.day)
			{
				return false;
			}
		}
	}
	return true;
}

#include <iostream>
#include "CDate.h"

using namespace std;

class InputOuptut
{
private:
	char m_charackter;
	int m_data;

public:
	InputOuptut();
	InputOuptut(const char m_charackter, const int m_data);
	void SetMCharactrer(const char m_charackter)
	{
		this->m_charackter = m_charackter;
	}
	void SetMData(const int m_data)
	{
		this->m_data = m_data;
	}
	const char GetMCharackter()
	{
		return this->m_charackter;
	}
	const int GetMData()
	{
		return this->m_data;
	}
	~InputOuptut();
};

InputOuptut::InputOuptut()
{
	this->m_charackter = 0;
	this->m_data = 0;
}

InputOuptut::InputOuptut(const char m_charackter, const int m_data)
{
	this->m_charackter = m_charackter;
	this->m_data = m_data;
}

InputOuptut::~InputOuptut()
{

}

ostream& operator<<(ostream& os, CDate& obj) // Overloading operator of output
{
	os << obj.GetDay() << endl << obj.GetMonth() << endl << obj.GetYear() << endl;
	return os;
}

istream& operator>>(istream& is, CDate& obj) // Overloading operator of input
{
	int a;
	cout << "\nEnter day: ";
	is >> a;
	obj.SetDay(a);
	cout << "\nEnter month: ";
	is >> a;
	obj.SetMonth(a);
	cout << "\nEnter year: ";
	is >> a;
	obj.SetYear(a);
	while (obj.GetYear() < 0)
	{
		cout << "\nEnter year: ";
		is >> a;
		obj.SetYear(a);
	}
	while (obj.GetMonth() < 0 || obj.GetMonth() > 12)
	{
		cout << "\nEnter month: ";
		is >> a;
		obj.SetMonth(a);
	}
	while (obj.GetMonth() == 2 && obj.GetYear() % 4 == 0 && obj.GetDay() < 0 ||
		obj.GetMonth() == 2 && obj.GetYear() % 4 == 0 && obj.GetDay() > 29)
	{
		cout << "\nEnter day: ";
		is >> a;
		obj.SetDay(a);
	}
	while (obj.GetMonth() == 2 && obj.GetYear() % 4 != 0 && obj.GetDay() < 0 ||
		obj.GetMonth() == 2 && obj.GetYear() % 4 != 0 && obj.GetDay() > 28)
	{
		cout << "\nEnter day: ";
		is >> a;
		obj.SetDay(a);
	}
	if (obj.GetMonth() == 1 || obj.GetMonth() == 3 || obj.GetMonth() == 5 || obj.GetMonth() == 7 ||
		obj.GetMonth() == 8 || obj.GetMonth() == 10 || obj.GetMonth() == 12)
	{
		while (obj.GetDay() < 0 || obj.GetDay() > 31)
		{
			cout << "\nEnter day: ";
			is >> a;
			obj.SetDay(a);
		}
	}
	else if (obj.GetMonth() == 1 || obj.GetMonth() == 4 || obj.GetMonth() == 6 || obj.GetMonth() == 9 ||
		obj.GetMonth() == 11)
	{
		while (obj.GetDay() < 0 || obj.GetDay() > 30)
		{
			cout << "\nEnter day: ";
			is >> a;
			obj.SetDay(a);
		}
	}
	return is;
}

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

void EnterDay(int& day, int month, int year) // Enter day with check on Leap Year
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



	/*CDate date(23, 3, 2000);
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
	cout << date5.DayOfWeek();*/

	CDate obj;
	cin >> obj;
	cout << obj;
}
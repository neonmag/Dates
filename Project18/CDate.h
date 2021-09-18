#pragma once
#include <iostream>

using namespace std;

class CDate
{
private:
	int day;
	int month;
	int year;
public:
	CDate();
	CDate(int day, int month, int year);
	void Check(int day, int month, int year);
	void PrintDate();
	char* DayOfWeek() const;
	int operator-(CDate b);
	CDate operator+(int a);
	CDate operator++(int);
	CDate operator--(int);
	bool operator>(CDate b);
	bool operator<(CDate b);
	bool operator==(CDate b);
	bool operator!=(CDate b);
};


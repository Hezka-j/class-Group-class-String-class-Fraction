#include "Date.h"

void Date::SetDates(unsigned short day, unsigned short month, short year)
{
	SetDay(day);
	SetMonth(month);
	SetYear(year);
}

void Date::SetDay(unsigned short day)
{
	if (month % 2 == 0 && month != 2)
	{
		if (day > 30 && day == 0)
			throw "Error";
	}
	else if (month % 2 != 0 && month != 2)
	{
		if (day > 31 && day == 0)
			throw "Error";

	}
	else
	{
		if (day > 28 && day == 0)
			throw "Error";

	}
	this->day = day;
	if (month > 12 && month == 0)
		throw "Error";
	this->month = month;
	this->year = year;
}

void Date::SetMonth(unsigned short month)
{
	if (month > 12 && month == 0)
		throw "Error";
	this->month = month;
}

void Date::SetYear(short year)
{
	this->year = year;
}

unsigned short Date::GetDay() const
{
	return day;
}

unsigned short Date::GetMonth() const
{
	return month;
}

short Date::GetYear() const
{
	return year;
}
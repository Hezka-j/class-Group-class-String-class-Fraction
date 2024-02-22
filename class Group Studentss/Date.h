#pragma once

class Date {
	unsigned short day : 5;
	unsigned short month : 4;
	short year;

public:
	void SetDates(unsigned short day, unsigned short month, short year);
	void SetDay(unsigned short day);
	void SetMonth(unsigned short month);
	void SetYear(short year);
	unsigned short GetDay() const;
	unsigned short GetMonth() const;
	short GetYear() const;
};
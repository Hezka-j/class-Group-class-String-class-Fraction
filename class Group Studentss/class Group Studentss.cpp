#include <iostream>
#include <ctime>
using namespace std;

#include "Date.h"
#include "Student.h"
#include "Group.h"
//Group operator += (Group& left,Student& right)
//{
//	left.AddStudent(right);
//	return left;
//}
istream& operator >> (const istream& i, Group& group)
{
	cout << "Enter name group - ";
	cin >> group.name;
	cout << "Enter count students group - ";
	cin >> group.count_students;
	cout << "Enter course number group - ";
	cin >> group.number_course;
	cout << "Enter speciality group - ";
	cin >> group.speciality;
	return cin;
}
ostream& operator << (const ostream& o, const Group& group)
{
	group.Print();
	return cout;
}
bool operator <= (Student& left, Student& right)
{
	return left.MiddleGrade(left) <= right.MiddleGrade(right);
}

bool operator >= (Student& left, Student& right)
{
	return left.MiddleGrade(left) >= right.MiddleGrade(right);
}

bool operator == (Student& left, Student& right)
{
	return left.MiddleGrade(left) == right.MiddleGrade(right);
}

bool operator != (Student& left, Student& right)
{
	return left.MiddleGrade(left) != right.MiddleGrade(right);
}

bool operator < (Student& left, Student& right)
{
	return left.MiddleGrade(left) < right.MiddleGrade(right);
}

bool operator > (Student& left, Student& right)
{
	return left.MiddleGrade(left) > right.MiddleGrade(right);
}
////////////////////////////////////////////////////////////////////////////////////////
bool operator <= (Group& left, Group& right)
{
	return left.GetCountStudents() <= right.GetCountStudents();
}

bool operator >= (Group & left, Group & right)
{
	return left.GetCountStudents() >= right.GetCountStudents();
}

bool operator != (Group& left, Group& right)
{
	return left.GetCountStudents() != right.GetCountStudents();
}

bool operator == (Group& left, Group& right)
{
	return left.GetCountStudents() == right.GetCountStudents();
}

bool operator < (Group& left, Group& right)
{
	return left.GetCountStudents() < right.GetCountStudents();
}

bool operator > (Group& left, Group& right)
{
	return left.GetCountStudents() > right.GetCountStudents();
}

int operator - (Date& right,Date& left)
{
	bool ok = false;
	int result_day;
	int result_month;
	int result_year;
	if (right.GetDay() >= left.GetDay() && right.GetMonth() >= left.GetMonth() && right.GetYear() >= left.GetYear())
	{
		result_day = right.GetDay() - left.GetDay();
		result_month = right.GetMonth() - left.GetMonth();
		result_year = right.GetYear() - left.GetYear();
	}
	else
	{
		result_day = left.GetDay() - right.GetDay();
		result_month = left.GetMonth() - right.GetMonth();
		result_year = left.GetYear() - right.GetYear();
	}
	if (left.GetYear() > right.GetYear() || left.GetYear() < right.GetYear())
	{		
		for (int i = 0; i < result_year; i++)
		{
			if (left.GetYear() > right.GetYear())
			{
				if (right.GetYear() + i / 400 == 0 && right.GetYear() + i / 100 == 0)
				{
					result_day += 366;
				}
				else
				{
					result_day += 365;
				}
			}
			else
			{
				if (left.GetYear() + i / 400 == 0 && left.GetYear() + i / 100 == 0)
				{
					result_day += 366;
				}
				else
				{
					result_day += 365;
				}
			}
			if (!ok)
			{
					for (int j = 0; j < result_month; j++)
					{
						if (j % 2 == 0)
						{
							result_day += 30;
						}
						else
						{
							result_day += 31;
						}
						ok = true;
					}
			}
		}
	}
	else
	{
		for (int j = 0; j < result_month; j++)
		{
			if (j % 2 == 0)
			{
				result_day += 30;
			}
			else
			{
				result_day += 31;
			}
		}
	}
	return result_day;
}

int main()
{
	srand(time(0));
	Student s;
	Student g(s);
	g.AddClassWorkRate(12);
	g.AddExamRate(12);
	s.AddClassWorkRate(12);
	s.AddExamRate(5);
	s.AddHomeWorkRate(10);
	s.AddHomeWorkRate(2);
	//cout << s.MiddleGrade(s);
	if (s >= g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (s <= g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (s > g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";
	if (s < g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";
	if (s == g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (s != g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	/*Group h("P26", "programmer", 2);
	h += s;
	h += g;
	h.Print();
	Group j;
	if (h >= j)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (h <= j)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (h > j)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";
	if (h < j)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";
	if (h == j)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (h != j)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";*/
	/*Group a("P26", "Programmer", 2);
	a.AddStudent(s);
	Group b;
	b.AddStudent(g);
	Group c = a + b;
	cout << c.GetName() << "\n";
	cout << c.GetCountStudents() << "\n";*/
	/*Date d;
	d.SetDates(1, 2, 2000);
	Date c; 
	c.SetDates(14, 5, 2025);
	int result = d - c;
	cout << result;*/
}
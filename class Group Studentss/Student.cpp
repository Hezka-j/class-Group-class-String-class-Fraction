#include <iostream>
using namespace std;

#include "Date.h"
#include "Student.h"

Student::~Student() {
	if (homework_rates != nullptr)
		delete[] homework_rates;
	if (classwork_rates != nullptr)
		delete[] classwork_rates;
	if (exam_rates != nullptr)
		delete[] exam_rates;
}

Student::Student() : Student("Stud", "Student", "0654968793") {}

Student::Student(string name, string surname, string number)
{
	SetName(name);
	SetSecondName("");
	SetSurname(surname);
	SetNumber(number);
	home_email = "student@gmail.com";
	birthday.SetDay(1 + rand() % 28);
	birthday.SetMonth(1 + rand() % 12);
	birthday.SetYear(rand() % 200 + 1900);

	study_date.SetDay(1 + rand() % 28);
	study_date.SetMonth(1 + rand() % 12);
	study_date.SetYear(rand() % 10 + 2015);
}

Student::Student(const Student& original) {
	this->surname = original.surname;
	this->name = original.name;
	this->second_name = original.second_name;
	this->home_email = original.home_email;

	this->birthday = original.birthday;
	this->study_date = original.study_date;

	this->classworks_count = original.classworks_count;
	this->homeworks_count = original.homeworks_count;
	this->exams_count = original.exams_count;

	this->classwork_rates = new double[classworks_count];
	for (int i = 0; i < classworks_count; i++) {
		this->classwork_rates[i] = original.classwork_rates[i];
	}

	this->homework_rates = new double[homeworks_count];
	for (int i = 0; i < homeworks_count; i++) {
		this->homework_rates[i] = original.homework_rates[i];
	}

	this->exam_rates = new double[exams_count];
	for (int i = 0; i < exams_count; i++) {
		this->exam_rates[i] = original.exam_rates[i];
	}
}

void Student::AddExamRate(double exam_rate)
{
	if (exam_rate >= 0 && exam_rate <= 12)
	{
		double* temp = new double[exams_count + 1];
		for (int i = 0; i < exams_count; i++)
		{
			temp[i] = exam_rates[i];
		}
		temp[exams_count] = exam_rate;
		exams_count++;
		delete[] exam_rates;
		exam_rates = temp;
	}
	else
		throw "Error";
}

void Student::AddClassWorkRate(double classwork_rate)
{
	if (classwork_rate >= 0 && classwork_rate <= 12)
	{
		double* temp = new double[classworks_count + 1];
		for (int i = 0; i < classworks_count; i++)
		{
			temp[i] = classwork_rates[i];
		}
		temp[classworks_count] = classwork_rate;
		classworks_count++;
		delete[] classwork_rates;
		classwork_rates = temp;
	}
	else
		throw "Error";
}

void Student::AddHomeWorkRate(double homework_rate)
{
	if (homework_rate >= 0 && homework_rate <= 12)
	{
		double* temp = new double[homeworks_count + 1];
		for (int i = 0; i < homeworks_count; i++)
		{
			temp[i] = homework_rates[i];
		}
		temp[homeworks_count] = homework_rate;
		homeworks_count++;
		delete[] homework_rates;
		homework_rates = temp;
	}
	else
		throw "Error";
}

void Student::DeleteExamRate(double exam_rate)
{
	if (exam_rate > 0 && exam_rate < 13)
	{
		for (int i = 0; i < exams_count; i++)
		{
			if (exam_rate == exam_rates[i])
			{
				double* temp = new double[exams_count - 1];
				for (int i = 0; i < exams_count; i++)
				{
					if (exam_rate == exam_rates[i])
					{
						temp[i] = exam_rates[i + 1];
						i++;
					}
					else
						temp[i] = exam_rates[i];
				}
				delete[] exam_rates;
				exams_count--;
				exam_rates = temp;
			}
		}
	}
	else
		throw "Error";
}

void Student::DeleteHomeWorkRate(double homework_rate)
{
	if (homework_rate > 0 && homework_rate < 13)
	{
		for (int i = 0; i < homeworks_count; i++)
		{
			if (homework_rate == homework_rates[i])
			{
				double* temp = new double[homeworks_count - 1];
				for (int i = 0; i < homeworks_count; i++)
				{
					if (homework_rate == homework_rates[i])
					{
						temp[i] = homework_rates[i + 1];
						i++;
					}
					else
						temp[i] = homework_rates[i];
				}
				delete[] homework_rates;
				homeworks_count--;
				homework_rates = temp;
			}
		}
	}
	else
		throw "Error";
}

void Student::DeleteClassWorkRate(double classwork_rate)
{
	if (classwork_rate > 0 && classwork_rate < 13)
	{
		for (int i = 0; i < classworks_count; i++)
		{
			if (classwork_rate == classwork_rates[i])
			{
				double* temp = new double[classworks_count - 1];
				for (int i = 0; i < classworks_count; i++)
				{
					if (classwork_rate == classwork_rates[i])
					{
						temp[i] = classwork_rates[i + 1];
						i++;
					}
					else
						temp[i] = classwork_rates[i];
				}
				delete[] classwork_rates;
				classworks_count--;
				classwork_rates = temp;
			}
		}
	}
	else
		throw"Error";
}

void Student::DeleteHomeWorkRateIndex(int homework_rate_index)
{
	if (homework_rate_index >= 0 && homeworks_count > homework_rate_index)
	{

		bool ok = false;
		for (int i = 0; i < homeworks_count; i++)
		{
			if (homework_rate_index == i)
			{
				double* temp = new double[homeworks_count - 1];
				for (int i = 0; i < homeworks_count - 1; i++)
				{
					if (homework_rate_index == i)
					{
						temp[i] = homework_rates[i + 1];
						ok = true;
					}
					else if (!ok)
						temp[i] = homework_rates[i];
					else
					{
						temp[i] = homework_rates[i + 1];

					}

				}
				delete[] homework_rates;
				homeworks_count--;
				homework_rates = temp;
			}
		}
	}
	else
		throw "Error";
}

void Student::DeleteExamRateIndex(int exam_rate_index)
{
	if (exam_rate_index >= 0 && exams_count > exam_rate_index)
	{

		bool ok = false;
		for (int i = 0; i < exams_count; i++)
		{
			if (exam_rate_index == i)
			{
				double* temp = new double[exams_count - 1];
				for (int i = 0; i < exams_count - 1; i++)
				{
					if (exam_rate_index == i)
					{
						temp[i] = exam_rates[i + 1];
						ok = true;
					}
					else if (!ok)
						temp[i] = exam_rates[i];
					else
					{
						temp[i] = exam_rates[i + 1];

					}

				}
				delete[] exam_rates;
				exams_count--;
				exam_rates = temp;
			}
		}
	}
	else
		throw "Error";
}

void Student::DeleteClassWorkRateIndex(int classwork_rate_index)
{
	if (classwork_rate_index >= 0 && classworks_count > classwork_rate_index)
	{
		bool ok = false;
		for (int i = 0; i < classworks_count; i++)
		{
			if (classwork_rate_index == i)
			{
				double* temp = new double[classworks_count - 1];
				for (int i = 0; i < classworks_count - 1; i++)
				{
					if (classwork_rate_index == i)
					{
						temp[i] = classwork_rates[i + 1];
						ok = true;
					}
					else if (!ok)
						temp[i] = classwork_rates[i];
					else
					{
						temp[i] = classwork_rates[i + 1];

					}

				}
				delete[] classwork_rates;
				classworks_count--;
				classwork_rates = temp;
			}
		}
	}
	else
		throw "Error";
}

short Student::GetHomeWorkCount() const
{
	return homeworks_count;
}

short Student::GetClassWorkCount() const
{
	return classworks_count;
}

short Student::GetExamCount() const
{
	return exams_count;
}

void Student::SetBirthday(Date& birthday)
{
	this->birthday = birthday;
}

Date Student::GetBirthday() const
{
	return birthday;
}

void Student::SetStudyDate(Date& study_date)
{
	this->study_date = study_date;
}
Date Student::GetStudyDate() const
{
	return study_date;
}
void Student::SetHomeEmail(string home_email)
{
	this->home_email = home_email;
}

string Student::GetHomeEmail() const
{
	return home_email;
}

void Student::SetNumber(string number)
{
	this->number = number;
}

string Student::GetNumber() const
{
	return number;
}

void Student::SetName(string name)
{
	this->name = name;
}

string Student::GetName() const
{
	return name;
}

void Student::SetSecondName(string second_name)
{
	this->second_name = second_name;
}

string Student::GetSecondName() const
{
	return second_name;
}

void Student::SetSurname(string surname)
{
	this->surname = surname;
}

string Student::GetSurname() const
{
	return surname;
}

void Student::ViewAllHomeworkRates() const
{
	for (int i = 0; i < homeworks_count; i++)
	{
		cout << homework_rates[i] << " ";
	}
	cout << "\n";
}

void Student::ViewAllClassworkRates() const
{
	for (int i = 0; i < classworks_count; i++)
	{
		cout << classwork_rates[i] << " ";
	}
	cout << "\n";
}

void Student::ViewAllExamRates() const
{
	for (int i = 0; i < exams_count; i++)
	{
		cout << exam_rates[i] << " ";
	}
	cout << "\n";
}

double Student::GetHomeworkRate(unsigned short index_rate) const
{
	for (int i = 0; i < homeworks_count; i++)
	{
		if (index_rate == i)
			return homework_rates[i];
	}
	throw "Bad index";
}

double Student::GetClassworkRate(unsigned short index_rate) const
{
	for (int i = 0; i < classworks_count; i++)
	{
		if (index_rate == i)
			return classwork_rates[i];
	}
	throw "Bad index";
}

double Student::GetExamRate(unsigned short index_rate) const
{
	for (int i = 0; i < exams_count; i++)
	{
		if (index_rate == i)
			return exam_rates[i];
	}
	throw "Bad index";
}
double Student::MiddleGrade(const Student& student)
{
	double middle_grade = 0;
	for (int i = 0; i < student.exams_count; i++)
	{
		middle_grade += student.exam_rates[i];
	}
	for (int i = 0; i < student.homeworks_count; i++)
	{
		middle_grade += student.homework_rates[i];
	}
	for (int i = 0; i < student.classworks_count; i++)
	{
		middle_grade += student.classwork_rates[i];
	}
	return middle_grade /= student.classworks_count + student.homeworks_count + student.exams_count;
}
void Student::Print() const
{
	cout << "FIO:" << name << " " << second_name << " " << surname << "\n";
	cout << "Number:" << number << "\n";
	cout << "Birthday date:" << birthday.GetDay() << "/" << birthday.GetMonth() << "/" << birthday.GetYear() << "\n";
	cout << "Email:" << home_email << "\n";
	cout << "Study start:" << study_date.GetDay() << "/" << study_date.GetMonth() << "/" << study_date.GetYear() << "\n";
	cout << "Homeworks rates: ";
	for (int i = 0; i < homeworks_count; i++)
	{
		cout << homework_rates[i] << ' ';
	}
	cout << "\n";
	cout << "Class works rates: ";
	for (int i = 0; i < classworks_count; i++)
	{
		cout << classwork_rates[i] << ' ';
	}
	cout << "\n";
	cout << "Exams rates: ";
	for (int i = 0; i < exams_count; i++)
	{
		cout << exam_rates[i] << ' ';
	}
	cout << "\n";
}

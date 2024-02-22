#pragma once

#include <iostream>
using namespace std;

#include "Date.h"

class Student {
	string name;
	string second_name;
	string surname;
	string number;
	string home_email;
	Date birthday;
	Date study_date;
	short homeworks_count = 0;
	short classworks_count = 0;
	short exams_count = 0;
	double* homework_rates = nullptr;
	double* classwork_rates = nullptr;
	double* exam_rates = nullptr;

public:
	~Student();
	Student();
	Student(string name, string surname, string number);
	Student(const Student& original);

	void AddExamRate(double exam_rate);
	void AddClassWorkRate(double classwork_rate);
	void AddHomeWorkRate(double homework_rate);

	void DeleteExamRate(double exam_rate);
	void DeleteHomeWorkRate(double homework_rate);
	void DeleteClassWorkRate(double classwork_rate);

	void DeleteHomeWorkRateIndex(int homework_rate_index);
	void DeleteExamRateIndex(int exam_rate_index);
	void DeleteClassWorkRateIndex(int classwork_rate_index);

	short GetHomeWorkCount() const;
	short GetClassWorkCount() const;
	short GetExamCount() const;

	void SetBirthday(Date& birthday);
	Date GetBirthday() const;

	void SetStudyDate(Date& study_date);
	Date GetStudyDate() const;

	void SetHomeEmail(string home_email);
	string GetHomeEmail() const;

	void SetNumber(string number);
	string GetNumber() const;

	void SetName(string name);
	string GetName() const;

	void SetSecondName(string second_name);
	string GetSecondName() const;

	void SetSurname(string surname);
	string GetSurname() const;

	void ViewAllHomeworkRates() const;
	void ViewAllClassworkRates() const;
	void ViewAllExamRates() const;

	double GetHomeworkRate(unsigned short index) const;
	double GetClassworkRate(unsigned short index) const;
	double GetExamRate(unsigned short index) const;

	double MiddleGrade(const Student& student);
	void Print() const;
};
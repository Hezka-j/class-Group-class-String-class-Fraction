#pragma once

#include <iostream>
using namespace std;

#include "Student.h"

class Group {
	string name = "";
	string speciality = "";
	int number_course = 1;
	int count_students = 0;
	Student** students = nullptr;

public:
	void operator += (Student& right)
	{
		AddStudent(right);		
	}
	Group operator + (Group& b)
	{
		Group c;
		c.name = this->name + b.GetName();
		c.speciality = this->speciality + b.GetSpeciality();
		c.number_course = this->number_course + b.GetCourseNumber();
		c.count_students = this->count_students + b.GetCountStudents();
		return c;
	}
	Group(const Group& original);
	Group();
	Group(string name, string speciality, int number_course);
	~Group();

	void SetName(string name);
	string GetName() const;

	void SetSpeciality(string speciality);
	string GetSpeciality() const;

	void SetCountStudents(int count_students);
	int GetCountStudents() const;

	void SetCourseNumber(int number_course);
	int GetCourseNumber() const;

	void Print() const;

	void AddStudent(const Student& new_student);
	void DeleteStudent(short student_index);
	friend istream& operator >> (const istream& i, Group& group);
};
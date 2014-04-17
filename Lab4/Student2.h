#pragma once
#include "Student.h"
#include <string>
#include <iostream>
class Student2 :
	public Student
{
private:
	string s_degree;
	double *p_average_ratings;

public:
	Student2(int=5,int=10,int=3);
	~Student2();

	void set_s_degree(string);
	string get_s_degree();

	friend istream& operator>>(istream&, Student2&);
	friend ostream& operator<<(ostream&, Student2&);
};


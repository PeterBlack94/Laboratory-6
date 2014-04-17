#pragma once
#include "Human.h"
#include "IInterface.h"
#include <string>
#include <iostream>
class Student :
	public Human, public IInterface
{
protected:
	static int i_counter_rates;
	int i_index;
	int i_semester;
	int *p_rates;
	string s_specialization;
	string s_department;

public:
	Student(int=10,int=3);
	virtual ~Student();
	
	void set_i_index(int);
	void set_i_semester(int);
	void set_s_specialization(string);
	void set_s_department(string);

	int get_i_index();
	int get_i_semester();
	string get_s_specialization();
	string get_s_department();

	void comparison(Human&);
	void comparison_age(IInterface&);
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, Student&);
};


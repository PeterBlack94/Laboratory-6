#include "stdafx.h"
#include "Student.h"

int Student::i_counter_rates = 0;

Student::Student(int i_a,int i_n):Human(i_n)
{
	p_rates = new int[i_a];
}


Student::~Student()
{
	delete[]p_rates;
	p_rates = NULL;
}

void Student::set_i_index(int i_index)
{
	this->i_index = i_index;
}

void Student::set_i_semester(int i_semester)
{
	this->i_semester = i_semester;
}

void Student::set_s_department(string s_department)
{
	this->s_department = s_department;
}

void Student::set_s_specialization(string s_specialization)
{
	this->s_specialization = s_specialization;
}

int Student::get_i_index()
{
	return i_index;
}

int Student::get_i_semester()
{
	return i_semester;
}

string Student::get_s_department()
{
	return s_department;
}

string Student::get_s_specialization()
{
	return s_specialization;
}

void Student::comparison(Human& Human) // PORÓWNANIE ŒREDNICH OCEN
{
	Student& Student = dynamic_cast <::Student&> (Human);
	
	double d_rates1 = 0;
	for (int i = 0; i < sizeof(i_counter_rates); ++i)
	{
		d_rates1 = +p_rates[i];
	}
	d_rates1 = d_rates1 / i_counter_rates;

	double d_rates2 = 0;
	for (int i = 0; i < sizeof(Student.i_counter_rates); ++i)
	{
		d_rates2 = +Student.p_rates[i];
	}
	d_rates2 = d_rates2 / Student.i_counter_rates;

	if (d_rates1 > d_rates2) cout << "First Student has got better results." << endl;
	if (d_rates1 < d_rates2) cout << "Second Student has got better results." << endl;
	if (d_rates1 == d_rates2) cout << "Both Students have got the same results." << endl;
}

void Student::comparison_age(IInterface& IInterface)
{
	Student& Student = dynamic_cast <::Student&> (IInterface);

	if (birthday.year < Student.birthday.year)
		cout << "First Student is older."<<endl;
	if (birthday.year > Student.birthday.year)
		cout << "Second Student is older."<<endl;
	if (birthday.year == Student.birthday.year)
	{
		if (birthday.month < Student.birthday.month)
			cout << "First Student is older." << endl;
		if (birthday.month > Student.birthday.month)
			cout << "Second Student is older." << endl;
		if (birthday.month == Student.birthday.month)
		{
			if (birthday.day < Student.birthday.day)
				cout << "First Student is older." << endl;
			if (birthday.day > Student.birthday.day)
				cout << "Second Student is older." << endl;
			if (birthday.day == Student.birthday.day)
				cout << "Both Students were born in the same day." << endl;
		}
	}
}

istream & operator>>(istream & in, Student& Student)
{
	cout << endl<<"Serve data about object (class Student):" << endl;
	cout << "First name: ";
	in >> Student.s_firstname;
	cout << "Last name: ";
	in >> Student.s_lastname;
	do
	{
		cout << "Sex (M/F): ";
		in >> Student.c_sex;
		if (Student.c_sex != 'M' && Student.c_sex != 'F')
			cout << endl << "ERROR! ! !  Press \"M\" if You are male or press \"F\" if You are female." << endl << endl;
	} while (Student.c_sex != 'M' && Student.c_sex != 'F');
	cout << "Birthday (DD MM YYYY): ";
	in >> Student.birthday.day >> Student.birthday.month >> Student.birthday.year;
	for (int i = 0; i < Student.i_counter_books; ++i)
	{
		cout << "Favorite book nr " << i + 1 << ": ";
		in >> Student.p_favorite_books[i];
	}
	cout << "Index: ";
	in >> Student.i_index;
	cout << "Semester: ";
	in >> Student.i_semester;
	cout << "Department: ";
	in >> Student.s_department;
	cout << "Specialization: ";
	in >> Student.s_specialization;
	cout << "Rates to serve: ";
	in >> Student.i_counter_rates;
	for (int i = 0; i < Student.i_counter_rates; ++i)
	{
		cout << "Rate nr " << i + 1 << ": ";
		in >> Student.p_rates[i];
	}

	return in;
}

ostream& operator<<(ostream& out, Student& Student)
{
	out << endl << "OBJECT STUDENT" << endl;
	out << "First name: " << Student.s_firstname << endl;
	out << "Last name: " << Student.s_lastname << endl;
	out << "Sex: " << Student.c_sex << endl;
	out << "Birthday: " << Student.birthday.day << " " << Student.birthday.month << " " << Student.birthday.year << endl;
	for (int i = 0; i < Student.i_counter_books; ++i)
		out << "Favorite book nr " << i + 1 << ": " << Student.p_favorite_books[i] << endl;
	out << "Index: " << Student.i_index << endl;
	out << "Semester: " << Student.i_semester << endl;
	out << "Department: " << Student.s_department << endl;
	out << "Specialization: " << Student.s_specialization << endl;
	out << "Rates: ";
	for (int i = 0; i < Student.i_counter_rates; ++i)
		out << Student.p_rates[i]<<" " << endl;

	return out;
}

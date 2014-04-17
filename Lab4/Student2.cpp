#include "stdafx.h"
#include "Student2.h"

Student2::Student2(int i_k, int i_a, int i_n) :Student(i_a,i_n)
{
	p_average_ratings = new double[i_k];
}


Student2::~Student2()
{
	delete[]p_average_ratings;
	p_average_ratings = NULL;

}

void Student2::set_s_degree(string s_degree)
{
	this->s_degree = s_degree;
}

string Student2::get_s_degree()
{
	return s_degree;
}

istream & operator>>(istream & in, Student2& Student2)
{
	cout <<endl<< "Serve data about object (class Student2):" << endl;
	cout << "First name: ";
	in >> Student2.s_firstname;
	cout << "Last name: ";
	in >> Student2.s_lastname;
	do
	{
		cout << "Sex (M/F): ";
		in >> Student2.c_sex;
		if (Student2.c_sex != 'M' && Student2.c_sex != 'F')
			cout << endl << "ERROR! ! !  Press \"M\" if You are male or press \"F\" if You are female." << endl << endl;
	} while (Student2.c_sex != 'M' && Student2.c_sex != 'F');
	cout << "Birthday (DD MM YYYY): ";
	in >> Student2.birthday.day >> Student2.birthday.month >> Student2.birthday.year;
	for (int i = 0; i < Student2.i_counter_books; ++i)
	{
		cout << "Favorite book nr " << i + 1 << ": ";
		in >> Student2.p_favorite_books[i];
	}
	cout << "Index: ";
	in >> Student2.i_index;
	cout << "Semester: ";
	in >> Student2.i_semester;
	cout << "Department: ";
	in >> Student2.s_department;
	cout << "Specialization: ";
	in >> Student2.s_specialization;
	cout << "Degree: ";
	in >> Student2.s_degree;
	cout << "Rates to serve: ";
	in >> Student2.i_counter_rates;
	for (int i = 0; i < Student2.i_counter_rates; ++i)
	{
		cout << "Rate nr " << i + 1 << ": ";
		in >> Student2.p_rates[i];
	}
	cout << "Average ratings: ";
	for (int i = 0; i < Student2.i_semester-1; ++i)
	{
		cout << "Semester nr " << i + 1 << ": ";
		in >> Student2.p_average_ratings[i];
	}
	return in;
}

ostream& operator<<(ostream& out, Student2& Student2)
{
	out << endl << "OBJECT STUDENT2" << endl;
	out << "First name: " << Student2.s_firstname << endl;
	out << "Last name: " << Student2.s_lastname << endl;
	out << "Sex: " << Student2.c_sex << endl;
	out << "Birthday: " << Student2.birthday.day << " " << Student2.birthday.month << " " << Student2.birthday.year << endl;
	for (int i = 0; i < Student2.i_counter_books; ++i)
		out << "Favorite book nr " << i + 1 << ": " << Student2.p_favorite_books[i] << endl;
	out << "Index: " << Student2.i_index << endl;
	out << "Semester: " << Student2.i_semester << endl;
	out << "Department: " << Student2.s_department << endl;
	out << "Specialization: " << Student2.s_specialization << endl;
	out << "Degree: " << Student2.s_degree << endl;
	out << "Rates: ";
	for (int i = 0; i < Student2.i_counter_rates; ++i)
		out << Student2.p_rates[i] << " " << endl;

	out << "Average ratings: ";
	for (int i = 0; i < Student2.i_semester-1; ++i)
		out << "Sem. " << i + 1 << ": "<<Student2.p_average_ratings[i]<<"   ";

	return out;
}
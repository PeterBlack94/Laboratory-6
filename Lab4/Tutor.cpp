#include "stdafx.h"
#include "Tutor.h"

Tutor::Tutor(int i_a) :Human(i_a)
{
}


Tutor::~Tutor()
{
}

void Tutor::set_s_academic_title(string s_academic_title)
{
	this->s_academic_title = s_academic_title;
}

void Tutor::set_i_publication_number(int i_publication_number)
{
	this->i_publication_number = i_publication_number;
}

string Tutor::get_s_academic_title()
{
	return s_academic_title;
}

int Tutor::get_i_publication_number()
{
	return i_publication_number;
}

void Tutor::comparison(Human& Human) // PORÓWNANIE TUTORÓW - LICZBA PUBLIKACJI
{
	Tutor& Tutor = dynamic_cast <::Tutor&> (Human);
	if (i_publication_number > Tutor.i_publication_number)
		cout << "First Tutor wrote more publications."<<endl;
	if (i_publication_number < Tutor.i_publication_number)
		cout << "Second Tutor wrote more publications."<<endl;
	if (i_publication_number == Tutor.i_publication_number)
		cout << "Both Tutors wrote the same number of publications." << endl;
}

istream & operator>>(istream & in, Tutor& Tutor)
{
	cout <<endl<< "Serve data about object (class Tutor):" << endl;
	cout << "First name: ";
	in >>Tutor.s_firstname;
	cout << "Last name: ";
	in >> Tutor.s_lastname;
	do
	{
		cout << "Sex (M/F): ";
		in >> Tutor.c_sex;
		if (Tutor.c_sex != 'M' && Tutor.c_sex != 'F')
			cout << endl << "ERROR! ! !  Press \"M\" if You are male or press \"F\" if You are female." << endl << endl;
	} while (Tutor.c_sex != 'M' && Tutor.c_sex != 'F');
	cout << "Birthday (DD MM YYYY): ";
	in >> Tutor.birthday.day >> Tutor.birthday.month >> Tutor.birthday.year;
	for (int i = 0; i < Tutor.i_counter_books; ++i)
	{
		cout << "Favorite book nr " << i + 1 << ": ";
		in >> Tutor.p_favorite_books[i];
	}
	cout << "Academic Title: ";
	in >> Tutor.s_academic_title;
	cout << "Number of publication: ";
	in >> Tutor.i_publication_number;
	return in;
}

ostream& operator<<(ostream& out, Tutor& Tutor)
{
	out << endl << "OBJECT TUTOR" << endl;
	out << "First name: " << Tutor.s_firstname << endl;
	out << "Last name: " << Tutor.s_lastname << endl;
	out << "Sex: " << Tutor.c_sex << endl;
	out << "Birthday: " << Tutor.birthday.day << " " << Tutor.birthday.month << " " << Tutor.birthday.year << endl;
	for (int i = 0; i < Tutor.i_counter_books; ++i)
		out << "Favorite book nr " << i + 1 << ": " << Tutor.p_favorite_books[i] << endl;
	out << "Academic Title: " << Tutor.s_academic_title << endl;
	out << "Number of publication: " << Tutor.i_publication_number << endl;

	return out;
}

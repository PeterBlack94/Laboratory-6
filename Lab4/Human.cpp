#include "stdafx.h"
#include "Human.h"

int Human::i_counter = 0;
int Human::i_counter_books = 0;

Human::Human(int i_n)
{
	++i_counter;
	p_favorite_books = new string[i_n];
	i_counter_books=+i_n;
}

Human::~Human()
{
	--i_counter;
	delete[]p_favorite_books;
	p_favorite_books = NULL;
}

int Human::count()
{
	return i_counter;
}

void Human::set_s_firstname(string s_firstname)
{
	this->s_firstname = s_firstname;
}

void Human::set_s_lastname(string s_lastname)
{
	this->s_lastname = s_lastname;
}

void Human::set_c_sex(char c_sex)
{
	this->c_sex = c_sex;
}

void Human::set_birthday(struct birthday birthday)
{
	this->birthday = birthday;
}

string Human::get_s_firstname()
{
	return s_firstname;
}

string Human::get_s_lastname()
{
	return s_lastname;
}

char Human::get_c_sex()
{
	return c_sex;
}

::birthday Human::get_birthday()
{
	return this->birthday;
}

void Human::if_birthday()
{
	struct tm now;
	__time32_t long_time;
	_time32(&long_time);
	errno_t err;
	err = _localtime32_s(&now, &long_time);

	if ((now.tm_mday) == (this->birthday.day) && (now.tm_mon + 1) == (this->birthday.month + 1) && (now.tm_year + 1900) == (this->birthday.year))
		cout << "This person has got birthday today! :D" << endl;
}

istream & operator>>(istream & in,Human& Human)
{
	cout <<endl<< "Serve data about object (class Human):" << endl;
	cout << "First name: ";
	in >> Human.s_firstname;
	cout << "Last name: ";
	in >> Human.s_lastname;
	do
	{
		cout << "Sex (M/F): ";
		in >> Human.c_sex;
		if (Human.c_sex != 'M' && Human.c_sex != 'F')
			cout << endl << "ERROR! ! !  Press \"M\" if You are male or press \"F\" if You are female." << endl << endl;
	} while (Human.c_sex != 'M' && Human.c_sex != 'F');
	cout << "Birthday (DD MM YYYY): ";
	in >> Human.birthday.day >> Human.birthday.month >> Human.birthday.year; 
	for (int i = 0; i < Human.i_counter_books; ++i)
	{
		cout << "Favorite book nr " << i+1 << ": ";
		in >> Human.p_favorite_books[i];
	}
	return in;
}

ostream& operator<<(ostream& out,Human& Human)
{
	out << endl << "OBJECT HUMAN" << endl;
	out << "First name: " << Human.s_firstname << endl; 
	out << "Last name: " << Human.s_lastname << endl; 
	out << "Sex: " << Human.c_sex << endl;
	out << "Birthday: " << Human.birthday.day << " " << Human.birthday.month << " " << Human.birthday.year << endl;
	for (int i = 0; i < Human.i_counter_books; ++i)
		out << "Favorite book nr " << i + 1 << ": " << Human.p_favorite_books[i] << endl;
	
	return out;
}

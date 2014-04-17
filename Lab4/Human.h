#pragma once
#include "IMamal.h"
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

struct birthday
{
	int day, month, year;
};

class Human :
	public IMamal
{
protected:
	static int i_counter;
	static int i_counter_books;
	char c_sex;
	::birthday birthday;
	string s_firstname;
	string s_lastname;
	string *p_favorite_books;

public:
	Human(int=3);
	virtual ~Human();
	virtual void comparison(Human&) = 0; // PROPOZYCJA METODY WIRTUALNEJ - PORÓWNANIE STUDENTÓW I NAUCZYCIELI
	static int count();
	void if_birthday();

	void set_s_firstname(string);
	void set_s_lastname(string);
	void set_c_sex(char);
	void set_birthday(::birthday);

	string get_s_firstname();
	string get_s_lastname();
	char get_c_sex();
	::birthday get_birthday();

	friend istream& operator>>(istream&,Human&);
	friend ostream& operator<<(ostream&,Human&);
};


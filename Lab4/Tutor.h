#pragma once
#include "Human.h"
#include <string>
#include <iostream>
class Tutor :
	public Human
{
private:
	string s_academic_title;
	int i_publication_number;
public:
	Tutor(int=3);
	~Tutor();

	void set_s_academic_title(string);
	void set_i_publication_number(int);

	string get_s_academic_title();
	int get_i_publication_number();

	void comparison(Human&);
	friend istream& operator>>(istream&, Tutor&);
	friend ostream& operator<<(ostream&, Tutor&);
};


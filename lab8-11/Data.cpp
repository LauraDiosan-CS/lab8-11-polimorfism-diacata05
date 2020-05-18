#include "Data.h"
#include <iostream>
using namespace std;
/*
	descr: constructor implicit
	in: -
	out: entitate Data
*/
Data::Data() {
	zi = 1;
	luna = 1;
	an = 2000;
}

/*
	descr: constructor cu parametrii
	in: integer z, integer l, interger a
	out: entitate data cu parametrii setati
*/
Data::Data(int z, int l, int a) {
		this->zi = z;
		this->luna = l;
		this->an = a;
}

/*
	descr: constructor de copiere
	in: ref entitate Data
	out: entitate Data
*/
Data::Data(const Data& d) {
	this->zi = d.zi;
	this->luna = d.luna;
	this->an = d.an;
}

/*
	descr: destructor
	in: -
	out: -
*/
Data::~Data() {}

/*
	descr: getter pentru atributul zi
	in: -
	out: integer - atribitul zi al entitatii
*/
int Data::getZi() {
	return zi;
}

/*
	descr: getter pentru atributul luna
	in: -
	out: integer - atribitul luna al entitatii
*/
int Data::getLuna() {
	return luna;
}

/*
	descr: getter pentru atributul an
	in: -
	out: integer - atribitul an al entitatii
*/
int Data::getAn() {
	return an;
}

/*
	descr: setter pentru atribitul zi
	in: integer z
	out: -
*/
void Data::setZi(int z) {
	if (z > 0 && z <= 31) {
		zi = z;
	}
	else {
		zi = 1;
	}
}

/*
	descr: setter pentru atribitul luna
	in: integer l
	out: -
*/
void Data::setLuna(int l) {
	if (l > 0 && l <= 12) {
		luna = l;
	}
	else {
		luna = 1;
	}
}

/*
	descr: setter pentru atribitul an
	in: integer a
	out: -
*/
void Data::setAn(int a) {
	if (a > 0 && a < 2030) {
		an = a;
	}
	else {
		an = 2020;
	}
}

/*
	descr: operator >
	in: Data& d;
	out: bool
*/
bool Data::operator==(const Data& d) {
	return this->zi == d.zi && this->luna == d.luna && this->an == d.an;
}


Data& Data::operator=(const Data& d) {
	if (this != &d) {
		this->zi = d.zi;
		this->luna = d.luna;
		this->an = d.an;
	}
	return *this;
}

char* Data::toString() {
	char* s = new char[10];
	char* zi = new char[3];
	char* luna = new char[3];
	char* an = new char[5];

	strcpy_s(s, 10, "");
	_itoa_s(this->zi, zi, 3, 10);
	_itoa_s(this->luna, luna, 3, 10);
	_itoa_s(this->an, an, 5, 10);


	strcat_s(s, 10, zi);
	strcat_s(s, 10, "/");
	strcat_s(s, 10, luna);
	strcat_s(s, 10, "/");
	strcat_s(s, 10, an);

	if (zi) {
		delete[] zi;
		zi = NULL;
	}
	if (luna) {
		delete[] luna;
		luna = NULL;
	}
	if (an) {
		delete[] an;
		an = NULL;
	}
	return s;
}

ostream& operator<<(ostream& os, const Data& d)
{
	os << d.zi << "/" << d.luna << "/" << d.an;
	return os;
}

istream& operator>>(istream& is, Data& d) {
	char slash;
	is >> d.zi >> slash >> d.luna >> slash >> d.an;
	return is;
}


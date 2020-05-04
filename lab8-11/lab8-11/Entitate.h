#ifndef ENTITATE_H
#define ENTITATE_H

#include <string>

using namespace std;

class Entitate {
protected:
	string cod;
	string nume;
	double pret;
public:
	Entitate();
	Entitate(string cod, string nume, double pret);
	Entitate(const Entitate& e);
	~Entitate();

	virtual Entitate* clone();

	string getCod();
	string getNume();
	double getPret();

	void setCod(string cod);
	void setNume(string nume);
	void setPret(double pret);

	Entitate& operator=(const Entitate& e);
	bool operator==(const Entitate& e);

	virtual string toString(string delim);
};

#pragma once

#endif
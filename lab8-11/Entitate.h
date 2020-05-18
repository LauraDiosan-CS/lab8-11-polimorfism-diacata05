#ifndef ENTITATE_H
#define ENTITATE_H

#include <string>
#include "Data.h"

using namespace std;

class Entitate {
protected:
	string cod;
	string nume;
	double pret;
	Data dataIntroducere;
	int exemplare;
public:
	Entitate();
	Entitate(string cod, string nume, double pret, Data dataIntroducere, int exemplare);
	Entitate(const Entitate& e);
	~Entitate();

	virtual Entitate* clone();

	string getCod();
	string getNume();
	double getPret();
	Data getDataIntroducere();
	int getExemplare();

	void setCod(string cod);
	void setNume(string nume);
	void setPret(double pret);
	void setDataIntroducere(Data dataIntroducere);
	void setExemplare(int exemplare);

	Entitate& operator=(const Entitate& e);
	bool operator==(const Entitate& e);

	virtual string toString(string delim);
};

#pragma once

#endif
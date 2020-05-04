#ifndef PRODUS_H
#define PRODUS_H

#include "Data.h"
#include "Entitate.h"

class Produs : public Entitate {
private:
	Data dataIntroducere;
	Data dataExpirare;
	int exemplare;
public:
	Produs();
	Produs(string cod, string nume, double pret, Data dataIntroducere, Data dataExpirare, int exemplare);
	Produs(string cod, string nume, double pret, string dataIntroducere, string dataExpirare, int exemplare);
	Produs(const Produs& p);
	~Produs();

	Entitate* clone();

	Data getDataIntroducere();
	Data getDataExpirare();
	int getExemplare();

	void setDataIntroducere(Data dI);
	void setDataExpirare(Data dE);
	void setExemplare(int exemplare);

	Produs& operator=(const Produs& p);
	bool operator==(const Produs& p);

	string toString(string delim);
};



#pragma once

#endif
#ifndef PRODUS_H
#define PRODUS_H

#include "Data.h"
#include "Entitate.h"

class Produs : public Entitate {
private:
	Data dataExpirare;
public:
	Produs();
	Produs(string cod, string nume, double pret, Data dataIntroducere, int exemplare, Data dataExpirare);
	Produs(const Produs& p);
	~Produs();

	Entitate* clone();

	Data getDataExpirare();

	void setDataExpirare(Data dE);

	Produs& operator=(const Produs& p);
	bool operator==(const Produs& p);

	string toString(string delim);
};



#pragma once

#endif
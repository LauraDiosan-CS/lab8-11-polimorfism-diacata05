#ifndef ANIMAL_H
#define ANIMAL_H

#include "Data.h"
#include "Entitate.h"
#include <iostream>

using namespace std;

class Animal : public Entitate {
private:
	int varsta;
public:
	Animal();
	Animal(string cod, string nume, double pret, Data dataIntroducere, int exemplare, int varsta);
	Animal(const Animal& a);
	~Animal();

	Entitate* clone();

	int getVarsta();

	void setVarsta(int v);

	Animal& operator=(const Animal& a);
	bool operator==(const Animal& a);
	string toString(string delim);
};

#pragma once

#endif
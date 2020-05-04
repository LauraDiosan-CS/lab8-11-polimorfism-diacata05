#ifndef ANIMAL_H
#define ANIMAL_H

#include "Data.h"
#include "Entitate.h"
#include <iostream>

using namespace std;

class Animal : public Entitate {
private:
	Data data;
	int varsta;
	int exemplare;
public:
	Animal();
	Animal(string cod, string nume, double pret, Data data, int varsta, int exemplare);
	Animal(string cod, string nume, double pret, string data, int varsta, int exemplare);
	Animal(const Animal& a);
	~Animal();

	Entitate* clone();

	Data getData();
	int getVarsta();
	int getExemplare();

	void setData(Data d);
	void setVarsta(int v);
	void setExemplare(int e);

	Animal& operator=(const Animal& a);
	bool operator==(const Animal& a);
	string toString(string delim);
};

#pragma once

#endif
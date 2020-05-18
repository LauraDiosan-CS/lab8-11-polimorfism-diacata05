#include "Animal.h"
#pragma once


Animal::Animal() : Entitate()
{
	this->varsta = 0;
}

Animal::Animal(string cod, string nume, double pret, Data dataIntroducere, int exemplare, int varsta) : Entitate(cod, nume, pret, dataIntroducere, exemplare)
{
	this->varsta = varsta;
}

Animal::Animal(const Animal& a) : Entitate(a)
{
	this->varsta = a.varsta;
}

Animal::~Animal()
{
}

Entitate* Animal::clone()
{
	return new Animal(this->cod, this->nume, this->pret, this->dataIntroducere, this->exemplare, this->varsta);
}

int Animal::getVarsta()
{
	return this->varsta;
}

void Animal::setVarsta(int v)
{
	this->varsta = v;
}

Animal& Animal::operator=(const Animal& a)
{
	Entitate::operator=(a);
	this->varsta = a.varsta;
	return *this;
}

bool Animal::operator==(const Animal& a)
{

	return Entitate::operator==(a) && this->varsta == a.varsta;
}

string Animal::toString(string delim)
{
	return "A" + delim + Entitate::toString(delim) + delim + to_string(this->varsta);
}

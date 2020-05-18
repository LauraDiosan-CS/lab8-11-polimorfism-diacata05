#include "Produs.h"


Produs::Produs() : Entitate()
{
	this->dataExpirare = Data();
}

Produs::Produs(string cod, string nume, double pret, Data dataIntroducere, int exemplare, Data dataExpirare) : Entitate(cod, nume, pret, dataIntroducere, exemplare)
{
	this->dataExpirare = dataExpirare;
}

Produs::Produs(const Produs& p) : Entitate(p)
{
	this->dataExpirare = p.dataExpirare;
}

Produs::~Produs()
{
}

Entitate* Produs::clone()
{
	return new Produs(this->cod, this->nume, this->pret, this->dataIntroducere, this->exemplare, this->dataExpirare);
}

Data Produs::getDataExpirare()
{
	return this->dataExpirare;
}

void Produs::setDataExpirare(Data dE)
{
	this->dataExpirare = dE;
}

Produs& Produs::operator=(const Produs& p)
{
	Entitate::operator=(p);
	this->dataExpirare = p.dataExpirare;
	return *this;
}

bool Produs::operator==(const Produs& p)
{
	return Entitate::operator==(p) && this->dataExpirare == p.dataExpirare;
}

string Produs::toString(string delim)
{
	return "P" + delim + Entitate::toString(delim) + delim + this->dataExpirare.toString();
}

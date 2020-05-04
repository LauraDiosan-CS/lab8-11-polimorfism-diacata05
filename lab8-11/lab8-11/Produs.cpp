#include "Produs.h"


Produs::Produs() : Entitate()
{
	this->dataIntroducere = Data();
	this->dataExpirare = Data();
	this->exemplare = 0;
}

Produs::Produs(string cod, string nume, double pret, Data dataIntroducere, Data dataExpirare, int exemplare) : Entitate(cod, nume, pret)
{
	this->dataIntroducere = dataIntroducere;
	this->dataExpirare = dataExpirare;
	this->exemplare = exemplare;
}

Produs::Produs(string cod, string nume, double pret, string dataIntroducere, string dataExpirare, int exemplare) : Entitate(cod, nume, pret)
{
	int pos = dataIntroducere.find("/");
	int ziI = stoi(dataIntroducere.substr(1, pos));
	dataIntroducere.erase(0, pos + 1);

	pos = dataIntroducere.find("/");
	int lunaI = stoi(dataIntroducere.substr(1, pos));
	dataIntroducere.erase(0, pos + 1);

	int anI = stoi(dataIntroducere.substr(0, dataIntroducere.length()));

	pos = dataExpirare.find("/");
	int ziE = stoi(dataExpirare.substr(1, pos));
	dataExpirare.erase(0, pos + 1);

	pos = dataExpirare.find("/");
	int lunaE = stoi(dataExpirare.substr(1, pos));
	dataExpirare.erase(0, pos + 1);

	int anE = stoi(dataExpirare.substr(0, dataExpirare.length()));

	this->dataIntroducere = Data(ziI, lunaI, anI);
	this->dataExpirare = Data(ziE, lunaE, anE);
	this->exemplare = exemplare;
}

Produs::Produs(const Produs& p) : Entitate(p)
{
	this->dataIntroducere = p.dataIntroducere;
	this->dataExpirare = p.dataExpirare;
	this->exemplare = p.exemplare;
}

Produs::~Produs()
{
}

Entitate* Produs::clone()
{
	return new Produs(this->cod, this->nume, this->pret, this->dataIntroducere, this->dataExpirare, this->exemplare);
}

Data Produs::getDataIntroducere()
{
	return this->dataIntroducere;
}

Data Produs::getDataExpirare()
{
	return this->dataExpirare;
}

int Produs::getExemplare()
{
	return this->exemplare;
}

void Produs::setDataIntroducere(Data dI)
{
	this->dataIntroducere = dI;
}

void Produs::setDataExpirare(Data dE)
{
	this->dataExpirare = dE;
}

void Produs::setExemplare(int exemplare)
{
	this->exemplare = exemplare;
}

Produs& Produs::operator=(const Produs& p)
{
	Entitate::operator=(p);
	this->dataIntroducere = p.dataIntroducere;
	this->dataExpirare = p.dataExpirare;
	this->exemplare = p.exemplare;
	return *this;
}

bool Produs::operator==(const Produs& p)
{
	
	return Entitate::operator==(p) && this->dataIntroducere == p.dataIntroducere && this->dataExpirare == p.dataExpirare && this->exemplare == p.exemplare;
}

string Produs::toString(string delim)
{
	return "P" + delim + Entitate::toString(delim) + delim + this->dataIntroducere.toString() + delim + this->dataExpirare.toString() + delim + to_string(this->exemplare);
}

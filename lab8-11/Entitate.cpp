#include "Entitate.h"

Entitate::Entitate()
{
	this->pret = 0;
	this->exemplare = 0;
}

Entitate::Entitate(string cod, string nume, double pret, Data dataIntroducere, int exemplare)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
	this->dataIntroducere = dataIntroducere;
	this->exemplare = exemplare;
}

Entitate::Entitate(const Entitate& e)
{
	this->cod = e.cod;
	this->nume = e.nume;
	this->pret = e.pret;
	this->dataIntroducere = e.dataIntroducere;
	this->exemplare = e.exemplare;
}

Entitate::~Entitate()
{
}

Entitate* Entitate::clone()
{
	return new Entitate(this->cod, this->nume, this->pret, this->dataIntroducere, this->exemplare);
}

string Entitate::getCod() {
	return this->cod;
}

string Entitate::getNume()
{
	return this->nume;
}

double Entitate::getPret()
{
	return this->pret;
}

Data Entitate::getDataIntroducere()
{
	return this->dataIntroducere;
}

int Entitate::getExemplare()
{
	return this->exemplare;
}

void Entitate::setCod(string cod) {
	this->cod = cod;
}

void Entitate::setNume(string nume)
{
	this->nume = nume;
}

void Entitate::setPret(double pret)
{
	this->pret = pret;
}

void Entitate::setDataIntroducere(Data dataIntroducere)
{
	this->dataIntroducere = dataIntroducere;
}

void Entitate::setExemplare(int exemplare)
{
	this->exemplare = exemplare;
}

Entitate& Entitate::operator=(const Entitate& e)
{
	this->cod = e.cod;
	this->nume = e.nume;
	this->pret = e.pret;
	this->dataIntroducere = e.dataIntroducere;
	this->exemplare = e.exemplare;
	return *this;
}

bool Entitate::operator==(const Entitate& e)
{
	return this->cod == e.cod && this->nume == e.nume && this->pret == e.pret && this->dataIntroducere == e.dataIntroducere && this->exemplare == e.exemplare;
}

string Entitate::toString(string delim)
{
	return this->cod + delim + this->nume + delim + to_string(this->pret).substr(0, 4) + delim + this->dataIntroducere.toString() + delim + to_string(this->exemplare);
}

#include "Entitate.h"

Entitate::Entitate()
{
	this->pret = 0;
}

Entitate::Entitate(string cod, string nume, double pret)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
}

Entitate::Entitate(const Entitate& e)
{
	this->cod = e.cod;
	this->nume = e.nume;
	this->pret = e.pret;
}

Entitate::~Entitate()
{
}

Entitate* Entitate::clone()
{
	return new Entitate(this->cod, this->nume, this->pret);
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

Entitate& Entitate::operator=(const Entitate& e)
{
	this->cod = e.cod;
	this->nume = e.nume;
	this->pret = e.pret;
	return *this;
}

bool Entitate::operator==(const Entitate& e)
{
	return this->cod == e.cod && this->nume == e.nume && this->pret == e.pret;
}

string Entitate::toString(string delim)
{
	return this->cod + delim + this->nume + delim + to_string(this->pret).substr(0,4);
}

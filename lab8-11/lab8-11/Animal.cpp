#include "Animal.h"
#pragma once


Animal::Animal() : Entitate()
{
	this->data = Data();
	this->varsta = 0;
	this->exemplare = 0;
}

Animal::Animal(string cod, string nume, double pret, Data data, int varsta, int exemplare) : Entitate(cod, nume, pret)
{
	this->data = data;
	this->varsta = varsta;
	this->exemplare = exemplare;
}

Animal::Animal(string cod, string nume, double pret, string data, int varsta, int exemplare) : Entitate(cod, nume, pret)
{
	int pos = data.find("/");
	int zi = stoi(data.substr(1, pos));
	data.erase(0, pos + 1);

	pos = data.find("/");
	int luna = stoi(data.substr(1, pos));
	data.erase(0, pos + 1);
	
	int an = stoi(data.substr(0, data.length()));

	this->data = Data(zi, luna, an);
	this->varsta = varsta;
	this->exemplare = exemplare;
}

Animal::Animal(const Animal& a) : Entitate(a)
{
	this->data = a.data;
	this->varsta = a.varsta;
	this->exemplare = a.exemplare;
}

Animal::~Animal()
{
}

Entitate* Animal::clone()
{
	return new Animal(this->cod, this->nume, this->pret, this->data, this->varsta, this->exemplare);
}

Data Animal::getData()
{
	return this->data;
}

int Animal::getVarsta()
{
	return this->varsta;
}

int Animal::getExemplare()
{
	return this->exemplare;
}

void Animal::setData(Data d)
{
	this->data = d;
}

void Animal::setVarsta(int v)
{
	this->varsta = v;
}

void Animal::setExemplare(int e)
{
	this->exemplare = e;
}

Animal& Animal::operator=(const Animal& a)
{
	Entitate::operator=(a);
	this->data = a.data;
	this->varsta = a.varsta;
	this->exemplare = a.exemplare;
	return *this;
}

bool Animal::operator==(const Animal& a)
{

	return Entitate::operator==(a) && this->data == a.data && this->varsta == a.varsta && this->exemplare == a.exemplare;
}

string Animal::toString(string delim)
{
	return "A" + delim + Entitate::toString(delim) + delim + this->data.toString() + delim + to_string(this->varsta) + delim + to_string(this->exemplare);
}

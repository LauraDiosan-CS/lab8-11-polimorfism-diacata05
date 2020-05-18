#ifndef UI_H
#define UI_H

#include "Login.h"
#include "Service.h"
#include "RepoFileCSV.h"

using namespace std;

class Ui {
private:
	Login loginService;
	Service service;
public:
	Ui();
	~Ui();

	void consola();
	void consolaService();
	void consolaUtilizator();
	void consolaAutentificare();

	Entitate* readAnimal();
	Entitate* readProdus();

	void printEntitati();
	
	string readString();
	Data readData();
	double readPret();
	int readInt();
};
#pragma once

#endif
#ifndef REPOFILE_H
#define REPOFILE_H

#include "Produs.h"
#include "ValidatorAnimal.h"
#include "ValidatorProdus.h"
#include <vector>

using namespace std;

class RepoFile {
protected:
	vector<Entitate*> entitati;
	string fileName;
	ValidatorAnimal va;
	ValidatorProdus vp;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Entitate*> getAll();
	int getSize();
	Entitate* getEntitate(int pos);
	void addEntitate(Entitate* e);
	void updateEntitate(Entitate* entitateVeche, Entitate* entitateNoua);
	void deleteEntitate(Entitate* e);

	int findByName(string name);
	int findByCod(string cod);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};

#pragma once

#endif

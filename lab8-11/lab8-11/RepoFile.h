#ifndef REPOFILE_H
#define REPOFILE_H

#include "Produs.h"
#include <deque>

using namespace std;

class RepoFile {
protected:
	deque<Entitate*> entitati;
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	deque<Entitate*> getAll();
	int getSize();
	Entitate* getEntitate(int pos);
	void addEntitate(Entitate* e);
	void updateEntitate(Entitate* entitateVeche, Entitate* entitateNoua);
	void deleteEntitate(Entitate* e);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};

#pragma once

#endif

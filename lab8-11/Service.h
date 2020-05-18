#ifndef SERVICE_H
#define SERVICE_H

#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "ServiceException.h"
#include "ValidationException.h"
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

class Service {
private:
	RepoFile* repo;
public:
	Service();
	Service(RepoFile* repo);
	Service(const Service& s);
	~Service();

	void setRepo(RepoFile* repo);

	RepoFile* getRepo();

	void addEntitate(Entitate* e);
	void deleteEntitate(string nume);
	void updateEntitate(string nume, Entitate* e);

	Entitate* getEntitateByName(string nume);

	vector<Entitate*> findByNume(string nume);
	vector<Entitate*> findByData(Data data);
	vector<Entitate*> cumpara(string cod, int exemplare);
};

#pragma once

#endif
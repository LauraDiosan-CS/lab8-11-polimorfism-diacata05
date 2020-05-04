#ifndef REPOFILECSV_H
#define REPOFILECSV_H

#include "RepoFile.h"
#include "Animal.h"
#include "Produs.h"
#include <fstream>

class RepoFileCSV : public RepoFile {
public:
	RepoFileCSV();
	RepoFileCSV(string fileName);
	~RepoFileCSV();
	void loadFromFile();
	void saveToFile();
};

#pragma once

#endif
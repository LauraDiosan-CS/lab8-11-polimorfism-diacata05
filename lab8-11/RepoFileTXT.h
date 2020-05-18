#ifndef REPOFILETXT_H
#define REPOFILETXT_H

#include "RepoFile.h"
#include "Animal.h"
#include "Produs.h"
#include <fstream>

class RepoFileTXT : public RepoFile {
public:
	RepoFileTXT();
	RepoFileTXT(string fileName);
	~RepoFileTXT();
	void loadFromFile();
	void saveToFile();
};

#pragma once

#endif
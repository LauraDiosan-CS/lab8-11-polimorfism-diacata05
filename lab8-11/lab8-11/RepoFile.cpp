#include "RepoFile.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

deque<Entitate*> RepoFile::getAll()
{
	return this->entitati;
}

int RepoFile::getSize()
{
	return this->entitati.size();
}

Entitate* RepoFile::getEntitate(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->entitati[pos]->clone();
	}
	return new Entitate();
}

void RepoFile::addEntitate(Entitate* e)
{
	//this->entitati.push_back(e->clone());
	this->entitati.push_front(e->clone());
}

void RepoFile::updateEntitate(Entitate* entitateVeche, Entitate* entitateNoua)
{
	for (int i = 0; i < this->entitati.size(); i++)
	{
		if (*(this->getEntitate(i)) == *entitateVeche)
		{
			delete this->entitati[i];
			this->entitati[i] = entitateNoua->clone();
			return;
		}
	}
}

void RepoFile::deleteEntitate(Entitate* e)
{
	for (int i = 0; i < this->entitati.size(); i++)
	{
		if (**(this->entitati.begin() + i) == *e)
		{
			delete this->entitati[i];
			this->entitati.erase(this->entitati.begin() + i);
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->entitati[i];
	}
	this->entitati.clear();
}
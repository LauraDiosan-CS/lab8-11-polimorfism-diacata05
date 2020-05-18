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

vector<Entitate*> RepoFile::getAll()
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

void RepoFile::addEntitate(Entitate* e) throw(ValidationException)
{
	if (typeid(e) == typeid(Animal)) {
		this->va.validate(e);
	}
	if (typeid(e) == typeid(Produs)) {
		this->vp.validate(e);
	}
	this->entitati.push_back(e->clone());
}

void RepoFile::updateEntitate(Entitate* entitateVeche, Entitate* entitateNoua)
{
	if (typeid(entitateNoua) == typeid(Animal)) {
		this->va.validate(entitateNoua);
	}
	if (typeid(entitateNoua) == typeid(Produs)) {
		this->vp.validate(entitateNoua);
	}
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

int RepoFile::findByName(string name)
{
	for (int i = 0; i < this->entitati.size(); i++) {
		if (this->entitati[i]->getNume() == name) {
			return i;
		}
	}

	return -1;
}

int RepoFile::findByCod(string cod)
{
	for (int i = 0; i < this->entitati.size(); i++) {
		if (this->entitati[i]->getCod() == cod) {
			return i;
		}
	}

	return -1;
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->entitati[i];
	}
	this->entitati.clear();
}
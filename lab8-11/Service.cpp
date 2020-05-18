#include "Service.h"

Service::Service()
{
	this->repo = new RepoFileTXT("entitati.txt");
}

Service::Service(RepoFile* repo)
{
	this->repo = repo;
	this->repo->loadFromFile();
}

Service::Service(const Service& s)
{
	this->repo = s.repo;
}

Service::~Service()
{
	delete this->repo;
	this->repo = NULL;
}

void Service::setRepo(RepoFile* repo)
{
	this->repo = repo;
	this->repo->loadFromFile();
}

void Service::addEntitate(Entitate* e) throw(ServiceException, ValidationException)
{
	int position = this->repo->findByName(e->getNume()); // > 0 daca a gasit entitatea, -1 daca nu a gasit

	if (position != -1) {
		throw ServiceException("Entitatea cu numele ["+e->getNume()+"] deja exista!");
	}

	position = this->repo->findByCod(e->getCod());

	if (position != -1) {
		throw ServiceException("Exista entitate cu codul trimis!");
	}

	this->repo->addEntitate(e);
	this->repo->saveToFile();
}

void Service::deleteEntitate(string nume) throw(ServiceException)
{
	int position = this->repo->findByName(nume);

	if (position == -1) {
		throw ServiceException("Entitatea nu exista!");
	}

	this->repo->deleteEntitate(this->repo->getEntitate(position));
	this->repo->saveToFile();
}

void Service::updateEntitate(string nume, Entitate* e) throw(ServiceException)
{
	int position = this->repo->findByName(nume);

	if (position == -1) {
		throw ServiceException("Entitatea nu exista!");
	}

	this->repo->updateEntitate(this->repo->getEntitate(position), e);
	this->repo->saveToFile();
}

Entitate* Service::getEntitateByName(string nume) throw(ServiceException)
{
	int position = this->repo->findByName(nume);
	if (position == -1) {
		throw ServiceException("Entitatea nu a fost gasita!");
	}
	return this->repo->getEntitate(position);
}

vector<Entitate*> Service::findByNume(string nume) throw(ServiceException)
{
	vector<Entitate*> found;
	for (int i = 0; i < this->repo->getAll().size(); i++) {
		Entitate* e = this->repo->getAll()[i];
		string _nume = e->getNume();
		transform(_nume.begin(), _nume.end(), _nume.begin(), ::tolower);
		if (_nume.find(nume) != string::npos) {
			found.push_back(e);
		}
	}
	if (found.size() == 0) {
		throw ServiceException("Nicion entitate gasita!");
	}
	return found;
}

vector<Entitate*> Service::findByData(Data data) throw(ServiceException)
{
	vector<Entitate*> found;
	for (int i = 0; i < this->repo->getAll().size(); i++) {
		Entitate* e = this->repo->getAll()[i];
		if (e->getDataIntroducere() == data) {
			found.push_back(e);
		}
	}
	if (found.size() == 0) {
		throw ServiceException("Nicion entitate gasita!");
	}
	return found;
}

vector<Entitate*> Service::cumpara(string cod, int exemplare) throw(ServiceException)
{
	int position = this->repo->findByCod(cod);

	if (position == -1) {
		throw ServiceException("Entitatea nu a fost gasita cu codul: [" + cod + "]");
	}

	Entitate* e = this->repo->getEntitate(position)->clone();

	if (e->getExemplare() < exemplare) {
		throw ServiceException("Articole disponibile: [" + to_string(e->getExemplare()) +"]");
	}

	e->setExemplare(e->getExemplare() - exemplare);

	this->repo->updateEntitate(this->repo->getEntitate(position), e);

	this->repo->saveToFile();
	
	return this->repo->getAll();
}

RepoFile* Service::getRepo()
{
	return this->repo;
}

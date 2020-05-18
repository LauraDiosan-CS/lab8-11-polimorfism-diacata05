#include "Teste.h"
#include <assert.h>

void testeEntitate() {
	Entitate e;

	assert(e.getCod().empty());
	assert(e.getNume().empty());
	assert(e.getPret() == 0);
	assert(e.getDataIntroducere() == Data());
	assert(e.getExemplare() == 0);

	e.setCod("abcd");
	e.setNume("nume");
	e.setPret(1.1);
	e.setDataIntroducere(Data(18, 5, 2020));
	e.setExemplare(3);

	assert(e.getCod() == "abcd");
	assert(e.getNume() == "nume");
	assert(e.getPret() == 1.1);
	assert(e.getDataIntroducere() == Data(18, 5, 2020));
	assert(e.getExemplare() == 3);

	Entitate e1 = e;

	assert(e1.getCod() == "abcd");
	assert(e1.getNume() == "nume");
	assert(e1.getPret() == 1.1);
	assert(e1.getDataIntroducere() == Data(18, 5, 2020));
	assert(e1.getExemplare() == 3);

	assert(e1 == e);
}

void testeAnimal() {
	Animal a;

	assert(a.getCod().empty());
	assert(a.getNume().empty());
	assert(a.getPret() == 0);
	assert(a.getDataIntroducere() == Data());
	assert(a.getVarsta() == 0);
	assert(a.getExemplare() == 0);

	a.setCod("abcd");
	a.setNume("nume");
	a.setPret(1.1);
	a.setDataIntroducere(Data(4, 5, 2020));
	a.setVarsta(2);
	a.setExemplare(10);

	assert(a.getCod() == "abcd");
	assert(a.getNume() == "nume");
	assert(a.getPret() == 1.1);
	assert(a.getDataIntroducere() == Data(4, 5, 2020));
	assert(a.getVarsta() == 2);
	assert(a.getExemplare() == 10);

	Animal a1 = a;

	assert(a1.getCod() == "abcd");
	assert(a1.getNume() == "nume");
	assert(a1.getPret() == 1.1);
	assert(a1.getDataIntroducere() == Data(4, 5, 2020));
	assert(a1.getVarsta() == 2);
	assert(a1.getExemplare() == 10);

	assert(a1 == a);
}

void testeProdus() {
	Produs p;

	assert(p.getCod().empty());
	assert(p.getNume().empty());
	assert(p.getPret() == 0);
	assert(p.getDataIntroducere() == Data());
	assert(p.getDataExpirare() == Data());
	assert(p.getExemplare() == 0);

	p.setCod("abcd");
	p.setNume("nume");
	p.setPret(1.1);
	p.setDataIntroducere(Data(4, 5, 2020));
	p.setDataExpirare(Data(4, 5, 2020));
	p.setExemplare(10);

	assert(p.getCod() == "abcd");
	assert(p.getNume() == "nume");
	assert(p.getPret() == 1.1);
	assert(p.getDataIntroducere() == Data(4, 5, 2020));
	assert(p.getDataExpirare() == Data(4, 5, 2020));
	assert(p.getExemplare() == 10);

	Produs p1 = p;

	assert(p1.getCod() == "abcd");
	assert(p1.getNume() == "nume");
	assert(p1.getPret() == 1.1);
	assert(p1.getDataIntroducere() == Data(4, 5, 2020));
	assert(p1.getDataExpirare() == Data(4, 5, 2020));
	assert(p1.getExemplare() == 10);

	assert(p == p1);
}

void testeRepoFile() {
	RepoFile* repo = new RepoFileTXT();

	assert(repo->getSize() == 0);

	repo->addEntitate(new Entitate());

	assert(repo->getSize() == 1);

	repo->updateEntitate(new Entitate(), new Entitate("abcd", "test", 2.5, Data(), 1));

	assert(repo->getEntitate(0)->getCod() == "abcd");
	assert(repo->getEntitate(0)->getNume() == "test");
	assert(repo->getEntitate(0)->getPret() == 2.5);
	assert(repo->getEntitate(0)->getDataIntroducere() == Data());
	assert(repo->getEntitate(0)->getExemplare() == 1);

	repo->deleteEntitate(new Entitate("abcd", "test", 2.5, Data(), 1));

	assert(repo->getSize() == 0);

	delete repo;
}

void testeRepoFileTXTandCSV() {

	RepoFile* repo = new RepoFileTXT("entitati_test.txt");

	repo->loadFromFile();

	assert(repo->getSize() == 2);

	repo->addEntitate(new Animal());

	assert(repo->getSize() == 3);

	repo->deleteEntitate(new Animal());

	repo->saveToFile();

	RepoFile* repo1 = new RepoFileCSV("entitati_test.csv");

	repo1->loadFromFile();

	assert(repo1->getSize() == 2);

	repo1->addEntitate(new Animal());

	assert(repo1->getSize() == 3);

	repo1->deleteEntitate(new Animal());

	repo1->saveToFile();

	delete repo;
	delete repo1;
}

void testeService() {
	Service s(new RepoFileCSV("entitati_test.csv"));

	Entitate* animal = new Animal("cod", "Papagal", 25.3, Data(), 1, 10);
	Entitate* animal1 = new Animal("cod1", "Papagal1", 25.3, Data(), 1, 10);

	s.addEntitate(animal);

	assert(s.getRepo()->getSize() == 3);

	s.updateEntitate("Papagal", animal1);

	assert(s.getEntitateByName("Papagal1")->getCod() == "cod1");

	s.deleteEntitate("Papagal1");

	assert(s.getRepo()->getSize() == 2);

	delete animal;
	delete animal1;
}

void testeLogin() {
	Login login;

	assert(login.isUserLoggedIn() == false);

	login.login("diana", "parola");

	assert(login.isUserLoggedIn() == true);
	try {
		login.login("diana", "parolaa");
	}
	catch (LoginException e) {
	}

	assert(login.isUserLoggedIn() == false);

	login.logout();
	assert(login.isUserLoggedIn() == false);
}

void testeLoginException() {
	bool exceptionIsThrown = false;

	Login login;
	try {
		login.login("", "");
	}
	catch (LoginException e) {
		exceptionIsThrown = true;
	}

	assert(exceptionIsThrown == true);
	exceptionIsThrown = false;

	try {
		login.login("diana", "");
	}
	catch (LoginException e) {
		exceptionIsThrown = true;
	}

	assert(exceptionIsThrown == true);
	exceptionIsThrown = false;

	try {
		login.login("diana", "parola1");
	}
	catch (LoginException e) {
		exceptionIsThrown = true;
	}

	assert(exceptionIsThrown == true);
	exceptionIsThrown = false;

	try {
		login.login("diana1", "parola");
	}
	catch (LoginException e) {
		exceptionIsThrown = true;
	}

	assert(exceptionIsThrown == true);
	exceptionIsThrown = false;

	try {
		login.login("diana", "parola");
	}
	catch (LoginException e) {
		exceptionIsThrown = true;
	}

	assert(exceptionIsThrown == false);
}

void testeValidator() {
	ValidatorEntitate ve;
	ValidatorAnimal va;
	ValidatorProdus vp;

	Entitate* e = new Entitate("cod", "nume", 2.5, Data(), 10);
	try {
		ve.validate(e);
	}
	catch (...) {
		assert(false);
	}

	e->setCod("");

	try
	{
		ve.validate(e);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	e->setCod("cod");
	e->setNume("");

	try
	{
		ve.validate(e);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	e->setCod("cod");
	e->setNume("nume");
	e->setPret(-2.5);

	try
	{
		ve.validate(e);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}


	e->setCod("cod");
	e->setNume("nume");
	e->setPret(2.5);
	e->setDataIntroducere(Data(-1, 10, 2020));

	try
	{
		ve.validate(e);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	e->setCod("cod");
	e->setNume("nume");
	e->setPret(2.5);
	e->setDataIntroducere(Data(1, 10, 2020));
	e->setExemplare(-2);

	try
	{
		ve.validate(e);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	Animal* a = new Animal("cod", "nume", 2.5, Data(), 5, -2);

	try
	{
		va.validate(a);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	Produs* p = new Produs("cod", "nume", 2.5, Data(), 5, Data(-1, 10, 2020));

	try
	{
		vp.validate(p);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	delete e;
	delete a;
	delete p;
}

void teste()
{
	testeEntitate();
	testeAnimal();
	testeProdus();
	testeRepoFile();
	testeRepoFileTXTandCSV();
	testeService();
	testeLogin();
	testeValidator();
}

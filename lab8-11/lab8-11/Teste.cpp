#include "Teste.h"
#include <assert.h>

void testeEntitate() {
	Entitate e;
	
	assert(e.getCod().empty());
	assert(e.getNume().empty());
	assert(e.getPret() == 0);

	e.setCod("abcd");
	e.setNume("nume");
	e.setPret(1.1);

	assert(e.getCod() == "abcd");
	assert(e.getNume() == "nume");
	assert(e.getPret() == 1.1);

	Entitate e1 = e;

	assert(e1.getCod() == "abcd");
	assert(e1.getNume() == "nume");
	assert(e1.getPret() == 1.1);

	assert(e1 == e);
} 

void testeAnimal() {
	Animal a;

	assert(a.getCod().empty());
	assert(a.getNume().empty());
	assert(a.getPret() == 0);
	assert(a.getData() == Data());
	assert(a.getVarsta() == 0);
	assert(a.getExemplare() == 0);

	a.setCod("abcd");
	a.setNume("nume");
	a.setPret(1.1);
	a.setData(Data(4, 5, 2020));
	a.setVarsta(2);
	a.setExemplare(10);

	assert(a.getCod() == "abcd");
	assert(a.getNume() == "nume");
	assert(a.getPret() == 1.1);
	assert(a.getData() == Data(4, 5, 2020));
	assert(a.getVarsta() == 2);
	assert(a.getExemplare() == 10);

	Animal a1 = a;

	assert(a1.getCod() == "abcd");
	assert(a1.getNume() == "nume");
	assert(a1.getPret() == 1.1);
	assert(a1.getData() == Data(4, 5, 2020));
	assert(a1.getVarsta() == 2);
	assert(a1.getExemplare() == 10);

	assert(a1 == a);

	Animal a2("acs", "nume", 2.5, "01/05/2020", 2, 10);

	assert(a2.getData() == Data(1, 5, 2020));
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

	Produs p2("acs", "nume", 2.5, "01/05/2020","01/05/2021", 10);

	assert(p2.getDataIntroducere() == Data(1, 5, 2020));
	assert(p2.getDataExpirare() == Data(1, 5, 2021));
}

void testeRepoFile() {
	RepoFile* repo = new RepoFileTXT();
	
	assert(repo->getSize() == 0);

	repo->addEntitate(new Entitate());

	assert(repo->getSize() == 1);

	repo->updateEntitate(new Entitate(), new Entitate("abcd", "test", 2.5));

	assert(repo->getEntitate(0)->getCod() == "abcd");
	assert(repo->getEntitate(0)->getNume() == "test");
	assert(repo->getEntitate(0)->getPret() == 2.5);

	repo->deleteEntitate(new Entitate("abcd", "test", 2.5));

	assert(repo->getSize() == 0);
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
}

void testeLive() {
	RepoFile* repo = new RepoFileCSV("fisier-112-1.csv");
	repo->loadFromFile();
	Entitate* a1 = new Animal("pwf6", "papagal",100, "01/04/2020", 2, 5);
	Entitate* a2 = new Produs("d59g", "mancare_pesti", 30, "11/12/2019", "01/01/2022", 12);
	Entitate* a3 = new Animal("eh79", "hamster", 60, "03/05/2020", 1, 3);
	Entitate* a4 = new Animal("d59g", "canar", 70, "07/03/2020", 3, 1);

	assert(repo->getSize() == 2);
	assert(*(repo->getEntitate(0)) == *a2);
	assert(*(repo->getEntitate(1)) == *a1);
	repo->addEntitate(a3);
	assert(repo->getSize() == 3);
	assert(*(repo->getEntitate(0)) == *a3);
	assert(*(repo->getEntitate(1)) == *a2);
	assert(*(repo->getEntitate(2)) == *a1);
	/*repo->addEntitate(a4);
	assert(repo->getSize() == 4);
	assert(*(repo->getEntitate(0)) == *a3);
	assert(*(repo->getEntitate(1)) == *a4);
	assert(*(repo->getEntitate(2)) == *a1);*/
}

void teste()
{
	testeEntitate();
	testeAnimal();
	testeProdus();
	testeRepoFile();
	testeRepoFileTXTandCSV();
}

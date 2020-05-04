#include "RepoFileCSV.h"

RepoFileCSV::RepoFileCSV() : RepoFile()
{
}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{
}

RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = ",";
		while (getline(f, linie))
		{
			if (linie.substr(0, 1) == "A")
			{
				linie = linie.erase(0, 2);

				int pos = linie.find(delim);
				string cod = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double pret = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find("/");
				int zi = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find("/");
				int luna = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int an = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int varsta = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int exemplare = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				Animal* a = new Animal(cod, nume, pret, Data(zi, luna, an), varsta, exemplare);

				//this->entitati.push_back(a);
				this->entitati.push_front(a);
			}
			else if (linie.substr(0, 1) == "P")
			{
				linie = linie.erase(0, 2);

				int pos = linie.find(delim);
				string cod = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double pret = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find("/");
				int ziI = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find("/");
				int lunaI = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int anI = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find("/");
				int ziE = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find("/");
				int lunaE = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int anE = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int exemplare = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				Produs* p = new Produs(cod, nume, pret,Data(ziI, lunaI, anI), Data(ziE, lunaE, anE), exemplare);
				//this->entitati.push_back(p);
				this->entitati.push_front(p);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Entitate* entitate : this->entitati)
		{
			f << entitate->toString(",") << endl;
		}
	}
}

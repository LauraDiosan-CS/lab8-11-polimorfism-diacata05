#include "Ui.h"


Ui::Ui() { }

Ui::~Ui() { }

void Ui::consola()
{
    bool running = true;

    while (running) {
        cout << "----------Diana Animale & Co--------------" << endl;
        cout << "1. Autentificare" << endl;
        cout << "2. Exit" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Optiune: ";
        int optiune = this->readInt();

        switch (optiune) {
        case 1:
            this->consolaAutentificare();
            break;
        case 2:
            running = false;
            break;
        default:
            cout << "Optiune gresita" << endl;
            break;
        }
    }


}

void Ui::consolaAutentificare() {
    int counter = 3;
    string username;
    string parola;

    while (counter != 0) {
        cout << "--Autentificare--" << endl;
        cout << "Incercari: " << counter << endl;
        cout << "Username: ";
        username = this->readString();
        cout << "Parola: ";
        parola = this->readString();

        try {
            this->loginService.login(username, parola);
            break;
        }
        catch (LoginException e) {
            cout << e.what() << endl;
        }

        counter--;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "Cu ce tip de fisier doriti sa lucrati?" << endl;
    cout << "Introduceti tipul fisierului (txt sau csv):";
    string fisier;
    cin >> fisier;
    cout << "--------------------------------------------------------" << endl;

    if (fisier == "txt") {
        this->service.setRepo(new RepoFileTXT("entitati.txt"));
    }

    if (fisier == "csv") {
        this->service.setRepo(new RepoFileCSV("entitati.csv"));
    }

    if (fisier != "csv" && fisier != "txt") {
        this->service.setRepo(new RepoFileTXT("entitati.txt"));
        cout << "Nu ati ales niciun fisier corect. Implicit este txt." << endl;
    }

    if (this->loginService.isUserLoggedIn()) {
        if (this->loginService.isUserAdmin()) {
            this->consolaService();
        }
        else {
            this->consolaUtilizator();
        }
        counter = 0;
    }
}

void printConsolaService() {
    cout << "------------------------" << endl;
    cout << "1. Add entitate" << endl;
    cout << "2. Delete entitate" << endl;
    cout << "3. Update entitate" << endl;
    cout << "4. Afisare entitati" << endl;
    cout << "0. Logout" << endl;
    cout << "------------------------" << endl;
}

void printConsolaUtilizator() {
    cout << "------------------------" << endl;
    cout << "1. Cauta entitate" << endl;
    cout << "2. Cumpara entitate" << endl;
    cout << "0. Log out" << endl;
    cout << "------------------------" << endl;
}

void Ui::consolaService()
{
    bool running = true;

    while (running) {
        printConsolaService();
        cout << "Optiune: ";
        int optiune = readInt();

        switch (optiune) {
        case 1: {
            cout << "1. Animal" << endl;
            cout << "2. Produs" << endl;
            cout << "0. Inapoi" << endl;
            int entitate = readInt();
            switch (entitate) {
            case 1: {
                Entitate* e = this->readAnimal();
                try {
                    this->service.addEntitate(e);
                }
                catch (ValidationException e) {
                    cout << e.what() << endl;
                }
                catch (ServiceException e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 2:
            {
                Entitate* e = this->readProdus();
                try {
                    this->service.addEntitate(e);
                }
                catch (ValidationException e) {
                    cout << e.what() << endl;
                }
                catch (ServiceException e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 0:
                break;
            }
            break;
        }

        case 2: {
            cout << "Nume entitate de sters: ";
            string nume = this->readString();
            try {
                this->service.deleteEntitate(nume);
            }
            catch (ServiceException e) {
                cout << e.what() << endl;
            }
            break;
        }

        case 3: {
            cout << "1. Animal" << endl;
            cout << "2. Produs" << endl;
            cout << "0. Inapoi" << endl;
            int optiune = readInt();
            switch (optiune) {
            case 1: {
                cout << "Nume entitate de updatat: ";
                string nume = this->readString();
                Entitate* e = new Animal();
                try {
                    e = this->service.getEntitateByName(nume);
                }
                catch (ValidationException e) {
                    cout << e.what() << endl;
                }
                catch (ServiceException e) {
                    cout << e.what() << endl;
                }

                cout << "Introduceti noile date" << endl;
                cout << "Pret: ";
                double pret = readPret();
                cout << "Data: ";
                Data d = readData();
                cout << "Varsta: ";
                int varsta = readInt();
                cout << "Exemplare: ";
                int exemplare = readInt();

                Entitate* eu = new Animal(e->getCod(), e->getNume(), pret, d, varsta, exemplare);
                this->service.updateEntitate(nume, eu);
                break;
            }
            case 2: {

                cout << "Nume entitate de updatat: ";
                string nume = this->readString();
                Entitate* e = new Produs();
                try {
                    e = this->service.getEntitateByName(nume);
                }
                catch (ValidationException e) {
                    cout << e.what() << endl;
                }
                catch (ServiceException e) {
                    cout << e.what() << endl;
                }
                cout << "Introduceti noile date" << endl;
                cout << "Pret: ";
                double pret = readPret();
                cout << "Data introducere: ";
                Data dI = readData();
                cout << "Data expirare: ";
                Data dE = readData();
                cout << "Varsta: ";
                int varsta = readInt();
                cout << "Exemplare: ";
                int exemplare = readInt();

                Entitate* eu = new Produs(e->getCod(), e->getNume(), pret, dI, exemplare, dE);
                this->service.updateEntitate(nume, eu);
                break;
            }

            case 3:
                break;
            }
        }
        case 4:
        {
            this->printEntitati();
            break;
        }
        case 0:
            this->loginService.logout();
            running = false;
            break;
        }
    }

}

void Ui::consolaUtilizator()
{
    bool running = true;

    while (running) {
        printConsolaUtilizator();
        cout << "Optiune: ";
        int optiune = readInt();

        switch (optiune) {
        case 1: {
            cout << "1. Cautare dupa nume" << endl;
            cout << "2. Cautare dupa data" << endl;
            cout << "0. Inapoi" << endl;
            cout << "Optiune: ";
            int optiune = readInt();
            vector<Entitate*> entitatiGasite;
            switch (optiune) {
                case 1:
                {
                    cout << "Introduceti numele articolului: ";
                    string nume = this->readString();
                    try {
                        entitatiGasite = this->service.findByNume(nume);
                        for (int i = 0; i < entitatiGasite.size(); i++) {
                            cout << entitatiGasite[i]->toString(",") << endl;
                        }
                    }
                    catch (ServiceException e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Introduceti data: ";
                    Data data = this->readData();
                    try {
                        entitatiGasite = this->service.findByData(data);
                        for (int i = 0; i < entitatiGasite.size(); i++) {
                            cout << entitatiGasite[i]->toString(",") << endl;
                        }
                    }
                    catch (ServiceException e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
            }
            break;
        }
        case 2: {
            cout << "Introduceti codul produsului: ";
            string cod = this->readString();
            cout << "Introduceti numarul de exemplare: ";
            int numar = this->readInt();
            try {
                this->service.cumpara(cod, numar);
            }
            catch (ServiceException e) {
                cout << e.what() << endl;
            }
            this->printEntitati();
            break;
        }
        case 0:
            this->loginService.logout();
            running = false;
            break;
        default:
            cout << "Optiune incorecta!";
            break;
        }
    }
}

void Ui::printEntitati() {
    RepoFile* repo = this->service.getRepo();
    for (int i = 0; i < repo->getAll().size(); i++) {
        cout << repo->getAll()[i]->toString(",") << endl;
    }
}

Entitate* Ui::readAnimal()
{
    cout << "Cod: ";
    string cod = this->readString();
    cout << "Nume: ";
    string nume = this->readString();
    cout << "Pret: ";
    double pret = this->readPret();
    cout << "Data: ";
    Data data = this->readData();
    cout << "Varsta: ";
    int varsta = this->readInt();
    cout << "Exemplare: ";
    int exemplare = this->readInt();

    return new Animal(cod, nume, pret, data, varsta, exemplare);
}

Entitate* Ui::readProdus()
{
    cout << "Cod: ";
    string cod = this->readString();
    cout << "Nume: ";
    string nume = this->readString();
    cout << "Pret: ";
    double pret = this->readPret();
    cout << "Data introducere: ";
    Data dataI = this->readData();
    cout << "Data expirare: ";
    Data dataE = this->readData();
    cout << "Exemplare: ";
    int exemplare = this->readInt();

    return new Produs(cod, nume, pret, dataI, exemplare, dataE);
}

string Ui::readString()
{
    string str;

    cin >> str;

    return str;
}

Data Ui::readData()
{
    cout << "--- zi: ";
    int zi = readInt();
    cout << "--- luna: ";
    int luna = readInt();
    cout << "--- an: ";
    int an = readInt();

    return Data(zi, luna, an);
}

double Ui::readPret()
{
    double pret;

    cin >> pret;

    return pret;
}

int Ui::readInt()
{
    int _int;

    cin >> _int;

    return _int;
}

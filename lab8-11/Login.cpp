#include "Login.h"

Login::Login()
{
	this->isLoggedIn = false;
	this->isAdmin = false;
	this->usersFromFile();
}

Login::~Login() {}

void Login::logout() {
	this->isLoggedIn = false;
	this->isAdmin = false;
}

void Login::login(string username, string password) throw(LoginException)
{
	map<string, string>::iterator it;

	if (username != "") {
		it = this->users.find(username); 
	}
	else {
		this->isLoggedIn = false;
		throw LoginException("Username-ul nu poate fi vid!");
	}

	if (password == "") { 
		this->isLoggedIn = false;
		throw LoginException("Parola nu poate fi vida!");
	}

	if (it != this->users.end()) {
		if (it->second == password) {
			if (username == "admin") {
				this->isAdmin = true;
			}
			else {
				this->isAdmin = false;
			}
			this->isLoggedIn = true;
		}
		else {
			this->isLoggedIn = false;
			throw LoginException("Parola nu corespunde pentru: [" + username + "]");
		}
	}
	else {
		this->isLoggedIn = false;
		throw LoginException("Utilizatorul [" + username + "] nu a fost gasit!");
	}
}

bool Login::isUserLoggedIn()
{
	return this->isLoggedIn;
}

bool Login::isUserAdmin()
{
	return this->isAdmin;
}

void Login::usersFromFile()
{
	this->users.clear();

	ifstream f("users.txt");

	if (f.is_open()) {
		string linie;

		while (getline(f, linie)) {
			int pos = linie.find(" ");
			string username = linie.substr(0, pos);
			linie = linie.erase(0, pos + 1);

			pos = linie.find(" ");
			string password = linie.substr(0, pos);
			linie = linie.erase(0, pos + 1);

			this->users.insert(pair<string, string>(username, password));
		}
	}

	f.close();
}

void Login::saveToFile()
{
	ofstream f("users.txt");

	if (f.is_open()) {
		for (std::map<string, string>::iterator it = this->users.begin(); it != this->users.end(); ++it)
			f << it->first << it->second << endl;
	}

	f.close();
}

#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <map>
#include <fstream>
#include "LoginException.h"

using namespace std;

class Login {
private:
	map<string, string> users;
	bool isLoggedIn;
	bool isAdmin;
public:
	Login();
	~Login();

	void logout();
	void login(string username, string parola);
	bool isUserLoggedIn();
	bool isUserAdmin();

	void usersFromFile();
	void saveToFile();
};

#pragma once

#endif
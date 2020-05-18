#ifndef LOGINEXCEPTION_H
#define LOGINEXCEPTION_H

#include <stdexcept>

using namespace std;

class LoginException : public runtime_error {
private:
	string msg;
public:
	LoginException(string msg) : runtime_error(msg) {
		this->msg = msg;
	}

	string what() {
		return this->msg;
	}
};
#pragma once

#endif
#ifndef VALIDATIONEXCEPTION_H
#define VALIDATIONEXCEPTION_H

#include <stdexcept>

using namespace std;

class ValidationException : public runtime_error {
private:
	string msg;
public:
	ValidationException(string msg) : runtime_error(msg) {
		this->msg = msg;
	}

	string what() {
		return this->msg;
	}
};

#pragma once

#endif

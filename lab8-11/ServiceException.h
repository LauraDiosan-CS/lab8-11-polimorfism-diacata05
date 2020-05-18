#ifndef SERVICEEXCEPTION_H
#define SERVICEEXCEPTION_H

#include <stdexcept>

using namespace std;

class ServiceException : public runtime_error {
private:
	string msg;
public:
	ServiceException(string msg) : runtime_error(msg) {
		this->msg = msg;
	}

	string what() {
		return this->msg;
	}
};

#pragma once

#endif

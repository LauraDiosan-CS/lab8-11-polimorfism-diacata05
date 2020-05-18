#ifndef VALIDATORENTITATE_H
#define VALIDATORENTITATE_H

#include "ValidationException.h"
#include "Entitate.h"

class ValidatorEntitate {
public:
	ValidatorEntitate();
	~ValidatorEntitate();
	virtual void validate(Entitate* e);
};

#pragma once

#endif
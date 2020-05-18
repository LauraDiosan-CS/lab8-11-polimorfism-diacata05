#ifndef VALIDATORANIMAL_H
#define VALIDATORANIMAL_H

#include "ValidationException.h"
#include "ValidatorEntitate.h"
#include "Animal.h"

class ValidatorAnimal : public ValidatorEntitate {
public:
	ValidatorAnimal();
	~ValidatorAnimal();
	virtual void validate(Entitate* e);
};

#pragma once

#endif
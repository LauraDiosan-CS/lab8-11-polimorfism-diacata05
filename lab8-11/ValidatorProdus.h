#ifndef VALIDATORPRODUS_H
#define VALIDATORPRODUS_H

#include "ValidationException.h"
#include "ValidatorEntitate.h"
#include "Produs.h"

class ValidatorProdus : public ValidatorEntitate {
public:
	ValidatorProdus();
	~ValidatorProdus();
	virtual void validate(Entitate* e);
};

#pragma once

#endif
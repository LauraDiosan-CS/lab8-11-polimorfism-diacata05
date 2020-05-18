#include "ValidatorAnimal.h"

ValidatorAnimal::ValidatorAnimal() : ValidatorEntitate()
{
}

ValidatorAnimal::~ValidatorAnimal()
{
}

void ValidatorAnimal::validate(Entitate* e) throw(ValidationException)
{
	ValidatorEntitate::validate(e);
	Animal* a = (Animal*)e;
	if (a->getVarsta() < 0) {
		throw ValidationException("Varsta trebuie sa fie pozitiva!");
	}
}

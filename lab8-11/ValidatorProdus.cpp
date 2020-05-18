#include "ValidatorProdus.h"

ValidatorProdus::ValidatorProdus() : ValidatorEntitate()
{
}

ValidatorProdus::~ValidatorProdus()
{
}

void ValidatorProdus::validate(Entitate* e) throw(ValidationException)
{
	ValidatorEntitate::validate(e);
	Produs* p = (Produs*)e;
	if (p->getDataExpirare().getAn() < 0) {
		throw ValidationException("Alegeti un an corect!");
	}
	if (p->getDataExpirare().getLuna() < 0 || p->getDataExpirare().getLuna() > 12) {
		throw ValidationException("Alegeti o luna corecta!");
	}
	if (p->getDataExpirare().getZi() < 0 || p->getDataExpirare().getZi() > 31) {
		throw ValidationException("Alegeti o zi corecta!");
	}
}

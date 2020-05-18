#include "ValidatorEntitate.h"

ValidatorEntitate::ValidatorEntitate()
{
}

ValidatorEntitate::~ValidatorEntitate()
{
}

void ValidatorEntitate::validate(Entitate* e) throw(ValidationException)
{
	if (e->getCod().empty()) {
		throw ValidationException("Codul entitatii nu poate fi gol");
	}
	if (e->getNume().empty()) {
		throw ValidationException("Numele entitatii nu poate fi gol");
	}
	for (char c : e->getNume())
	{
		if (!isalpha(c))
		{
			throw ValidationException("Numele entitatii trebuie sa contina doar litere!");
		}
	}
	if (e->getDataIntroducere().getZi() < 0 || e->getDataIntroducere().getZi() > 31) {
		throw ValidationException("Alege o zi intre 1 si 28/29-30-31!");
	}
	if (e->getDataIntroducere().getLuna() < 0 || e->getDataIntroducere().getLuna() > 12) {
		throw ValidationException("Alege o luna intre 1 si 12!");
	}
	if (e->getDataIntroducere().getAn() < 0 ) {
		throw ValidationException("Alege un an corect!");
	}
	if (e->getPret() < 0) {
		throw ValidationException("Introduceti in pret corect!");
	}
	if (e->getExemplare() < 0) {
		throw ValidationException("Numarul de exemplare trebuie sa fie pozitiv!");
	}
}

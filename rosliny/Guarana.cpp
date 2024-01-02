#include "Guarana.h"
#include "../Swiat.h"
#include <cstdlib>



Guarana::Guarana(int x, int y, Swiat** world) : Roslina(x, y, world, 99, 0, 'g', 8, 1, "Guarana") {}



bool Guarana::jestZjedzonaPrzez(Organizm* zwierze) {
	zwierze->setSila(zwierze->getSila() + 3);
	return __super::jestZjedzonaPrzez(zwierze);
}



void Guarana::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Guarana* nowa = new Guarana(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
#include "Zolw.h"
#include "../Swiat.h"
#include <cstdlib>
#include "../GUI.h"


Zolw::Zolw(int x, int y, Swiat** world) : Zwierze(x, y, world, 2, 1, 'z', 12, 1, "Zolw") {}



void Zolw::akcja() {
	if ((rand() % 100) < 75) {
		__super::akcja();
	}
}



bool Zolw::czyOdbijaAtak(Organizm* organ) {
	if (organ->getSila() < 5) {
		(*this->getSwiat())->getGUI()->logOdbicie(this, organ);
		return true;
	}

	return false;
}



void Zolw::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Zolw* nowa = new Zolw(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
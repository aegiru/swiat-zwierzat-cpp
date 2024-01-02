#include "Lis.h"
#include <cstdlib>
#include "../Swiat.h"
#include "../GUI.h"

Lis::Lis(int x, int y, Swiat** world) : Zwierze(x, y, world, 3, 7, 'y', 11, 1, "Lis") {}



bool Lis::czyNieChceWejsc(Organizm* organ) {
	(*this->getSwiat())->getGUI()->logNieWejdzie(this, organ);
	return (this->getSila() >= organ->getSila());
}



void Lis::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Lis* nowa = new Lis(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
#include "Antylopa.h"
#include "../Swiat.h"
#include <cstdlib>

Antylopa::Antylopa(int x, int y, Swiat** world) : Zwierze(x, y, world, 4, 4, 'a', 10, 2, "Antylopa") {}



bool Antylopa::czyUcieczkaPrzedWalka() {
	return ((rand() % 2) == 1);
}



bool Antylopa::ucieczka(Organizm* organ) {
	bool toReturn = false;

	if ((*this->getSwiat())->czyPusty(this->getX() - 1, this->getY())) {
		this->setX(this->getX() - 1);
		toReturn = true;
	}

	if ((*this->getSwiat())->czyPusty(this->getX() + 1, this->getY())) {
		this->setX(this->getX() + 1);
		toReturn = true;
	}

	if ((*this->getSwiat())->czyPusty(this->getX(), this->getY() - 1)) {
		this->setY(this->getY() - 1);
		toReturn = true;
	}

	if ((*this->getSwiat())->czyPusty(this->getX(), this->getY() + 1)) {
		this->setY(this->getY() + 1);
		toReturn = true;
	}

	if (toReturn) {
		(*this->getSwiat())->getGUI()->logUnik(this, organ);
	}

	return toReturn;
}



void Antylopa::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Antylopa* nowa = new Antylopa(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
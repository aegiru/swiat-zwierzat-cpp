#include "Wilk.h"
#include <cstdlib>
#include "../Swiat.h"

Wilk::Wilk(int x, int y, Swiat** world) : Zwierze(x, y, world, 9, 5, 'k', 14, 1, "Wilk") {}

void Wilk::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Wilk* nowa = new Wilk(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
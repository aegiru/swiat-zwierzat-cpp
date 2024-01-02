#include "Trawa.h"
#include "../Swiat.h"
#include <cstdlib>

Trawa::Trawa(int x, int y, Swiat** world) : Roslina(x, y, world, 0, 0, 't', 6, 1, "Trawa") {}

void Trawa::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Trawa* nowa = new Trawa(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
#include "Mlecz.h"
#include "../Swiat.h"
#include <cstdlib>



Mlecz::Mlecz(int x, int y, Swiat** world) : Roslina(x, y, world, 0, 0, 'm', 9, 1, "Mlecz") {}



void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		__super::akcja();
	}
}



void Mlecz::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Mlecz* nowa = new Mlecz(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
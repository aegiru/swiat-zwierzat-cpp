#include "Owca.h"
#include <cstdlib>
#include "../Swiat.h"



Owca::Owca(int x, int y, Swiat** world) : Zwierze(x, y, world, 4, 4, 'o', 13, 1, "Owca") {}



void Owca::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		Owca* nowa = new Owca(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
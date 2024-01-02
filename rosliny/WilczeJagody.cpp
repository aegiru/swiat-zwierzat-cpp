#include "WilczeJagody.h"
#include <cstdlib>
#include "../Swiat.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat** world) : Roslina(x, y, world, 0, 0, 'j', 7, 1, "WilczeJagody") {}



bool WilczeJagody::jestZjedzonaPrzez(Organizm* zwierze)
{
	zwierze->umiera();
	return false;
}



void WilczeJagody::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		WilczeJagody* nowa = new WilczeJagody(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}
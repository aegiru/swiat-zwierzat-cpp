#include "BarszczSosnowskiego.h"
#include "../Swiat.h"
#include <cstdlib>

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat** world) : Roslina(x, y, world, 10, 0, 'b', 3, 1, "BarszczSosnowskiego") {}



bool BarszczSosnowskiego::jestZjedzonaPrzez(Organizm* zwierze) {
	zwierze->setSila(zwierze->getSila() + 3);
	return __super::jestZjedzonaPrzez(zwierze);
}



void BarszczSosnowskiego::akcja() {
	if (!(*this->getSwiat())->czyPusty(this->getX() - 1, this->getY())) {
		if ((*this->getSwiat())->getOrganizm(this->getX() - 1, this->getY())->jestZwierze()) {
			this->zabija((*this->getSwiat())->getOrganizm(this->getX() - 1, this->getY()));
		}
	}

	if (!(*this->getSwiat())->czyPusty(this->getX() + 1, this->getY())) {
		if ((*this->getSwiat())->getOrganizm(this->getX() + 1, this->getY())->jestZwierze()) {
			this->zabija((*this->getSwiat())->getOrganizm(this->getX() + 1, this->getY()));
		}
	}

	if (!(*this->getSwiat())->czyPusty(this->getX(), this->getY() - 1)) {
		if ((*this->getSwiat())->getOrganizm(this->getX(), this->getY() - 1)->jestZwierze()) {
			this->zabija((*this->getSwiat())->getOrganizm(this->getX(), this->getY() - 1));
		}
	}

	if (!(*this->getSwiat())->czyPusty(this->getX(), this->getY() + 1)) {
		if ((*this->getSwiat())->getOrganizm(this->getX(), this->getY() + 1)->jestZwierze()) {
			this->zabija((*this->getSwiat())->getOrganizm(this->getX(), this->getY() + 1));
		}
	}

	__super::akcja();
}



void BarszczSosnowskiego::rozmnazanie() {
	if ((rand() % 100) < 75) {
		return;
	}

	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	if ((*this->getSwiat())->czyPusty(x + xDifference, y + yDifference)) {
		BarszczSosnowskiego* nowa = new BarszczSosnowskiego(x + xDifference, y + yDifference, this->world);
		(*this->getSwiat())->dodajOrganizm(nowa);
	}
}



void BarszczSosnowskiego::zabija(Organizm* zwierze) {
	(*this->getSwiat())->getGUI()->logBarszczyk(this, zwierze);
	(*this->getSwiat())->clearOrganizm(zwierze->getX(), zwierze->getY());
}

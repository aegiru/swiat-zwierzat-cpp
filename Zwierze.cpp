#include "Zwierze.h"
#include "Roslina.h"
#include "Swiat.h"
#include <cstdlib>



Zwierze::Zwierze(int x, int y, Swiat** world, int sila, int inicjatywa, char representation, int color, int range, char* nazwa) : Organizm(x, y, world, sila, inicjatywa, representation, color, range, nazwa) {}



void Zwierze::akcja() {
	int x = this->getX();
	int y = this->getY();
	int xDifference = 0;
	int yDifference = 0;

	this->getLosowaPozycja(xDifference, yDifference);

	Organizm* potentialCollision = (*this->getSwiat())->getOrganizm(x + xDifference, y + yDifference);

	if (this->kolizja(potentialCollision)) {
		this->x += xDifference;
		this->y += yDifference;
	}
}



bool Zwierze::kolizja(Organizm* organ) {
	if (organ == nullptr) {
		return true;
	}

	if (areOfSameType(organ)) {
		// rozmnazanie
		this->rozmnazanie();
		return false;
	}
	else {
		// walka | zjedzenie

		if (organ->czyOdbijaAtak(this)) {
			return false;
		}

		if (this->czyNieChceWejsc(organ)) {
			return false;
		}

		if (organ->jestZwierze()) {
			if (this->czyUciekaPrzedWalka()) {
				if (this->ucieczka(organ)) {
					return false;
				}
			}

			if (organ->czyUciekaPrzedWalka()) {
				if (organ->ucieczka(this)) {
					return true;
				}
			}

			return this->walka(organ);
		}

		if (organ->jestRoslina()) {
			(*this->getSwiat())->getGUI()->logJedzenie(this, organ);
			return this->zjada(organ);
		}

	}
}



bool Zwierze::czyNieChceWejsc(Organizm* organ) {
	return false;
}



void Zwierze::rozmnazanie() {

}



bool Zwierze::jestZwierze() {
	return true;
}



bool Zwierze::jestRoslina() {
	return false;
}
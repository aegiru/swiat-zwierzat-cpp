#include "Czlowiek.h"
#include "GUI.h"
#include "Swiat.h"
#include <cstdlib>



Czlowiek::Czlowiek(int x, int y, Swiat** world) : Zwierze(x, y, world, 5, 4, 'C', 6, 1, "Czlowiek") {}



void Czlowiek::akcja() {
	GUI* gui = (*this->getSwiat())->getGUI();

	int input = gui->getInput();

	this->zmianaUmiejetnosc();

	if (input && input != 224) {
		if (input == gui->keyN) {
			return;
		}

		if (input == gui->keyU) {
			this->umiejetnosc();
			return;
		}
	}
	else {
		int key = gui->getInput();

		int x = this->getX();
		int y = this->getY();
		int xDifference = 0;
		int yDifference = 0;

		if (key == gui->keyUp) {
			yDifference -= (range);
		}
		else if (key == gui->keyDown) {
			yDifference += (range);
		}
		else if (key == gui->keyLeft) {
			xDifference -= (range);
		}
		else if (key == gui->keyRight) {
			xDifference += (range);
		}

		(*this->getSwiat())->getGUI()->clear();
		
		if (this->wouldBeOutOfBounds(x + xDifference, y + yDifference)) {
			return;
		}

		Organizm* potentialCollision = (*this->getSwiat())->getOrganizm(x + xDifference, y + yDifference);

		if (this->kolizja(potentialCollision)) {
			this->setX(x + xDifference);
			this->setY(y + yDifference);
		}

		
	}
}



void Czlowiek::setTury(int n) {
	this->turyUmiejetnosci = n;
}



int Czlowiek::getTury() {
	return this->turyUmiejetnosci;
}



void Czlowiek::umiejetnosc() {
	if (this->turyUmiejetnosci == 0) {
		this->setTury(10);
	}
}



void Czlowiek::zmianaUmiejetnosc() {
	this->range = 1;
	int tura = this->getTury();


	if (tura > 7) {
		this->range = 2;
	}

	if (tura > 5) {
		if (rand() % 2 == 1) {
			this->range = 2;
		}
	}

	if (tura > 0) {
		this->setTury(this->getTury() - 1);
	}
}
#include "Organizm.h"

#include "GUI.h"
#include "Swiat.h"
#include <cstdlib>
#include <string.h>



bool Organizm::wouldBeOutOfBounds(int x, int y) {
	int maxX = (*this->getSwiat())->getSizeX();
	int maxY = (*this->getSwiat())->getSizeY();

	if ((0 <= x) && (x < maxX) && (0 <= y) && (y < maxY)) {
		return false;
	}

	return true;
}



Organizm::Organizm(int x, int y, Swiat** world, int sila, int inicjatywa, char representation, int color, int range, char* nazwa) {
	this->x = x;
	this->y = y;
	this->world = world;

	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->representation = representation;
	this->color = color;
	this->range = range;
	this->name = nazwa;
}


Organizm::Organizm(const Organizm& organ) {
	this->x = organ.x;
	this->y = organ.y;
	this->sila = organ.sila;
	this->inicjatywa = organ.inicjatywa;
	this->world = organ.world;
	this->color = organ.color;
	this->representation = organ.representation;
	this->name = organ.name;
	this->range = organ.range;
}



const int Organizm::getX() {
	return this->x;
}



const int Organizm::getY() {
	return this->y;
}



const int Organizm::getSila() {
	return this->sila;
}



const int Organizm::getInicjatywa() {
	return this->inicjatywa;
}



char Organizm::getReprezentacja() {
	return this->representation;
}



const int Organizm::getColor() {
	return this->color;
}



void Organizm::setX(int x) {
	this->x = x;
}



void Organizm::setY(int y) {
	this->y = y;
}



void Organizm::setSila(int s) {
	this->sila = s;
}



void Organizm::rysowanie() {
	(*world)->getGUI()->drawWorldElement(this->x, this->y, this->representation, this->color);
}



Swiat** Organizm::getSwiat() {
	return this->world;
}



const char* Organizm::getName() {
	return this->name;
}



bool Organizm::areOfSameType(Organizm* organ)
{
	if (strcmp(this->getName(), organ->getName()) == 0) {
		return true;
	}

	return false;
}



bool Organizm::czyOdbijaAtak(Organizm* organ)
{
	return false;
}



bool Organizm::czyUciekaPrzedWalka()
{
	return false;
}



bool Organizm::ucieczka(Organizm* organ)
{
	return false;
}



bool Organizm::walka(Organizm* organ) {
	if (this->getSila() >= organ->getSila())
	{
		(*this->getSwiat())->getGUI()->logWygranieWalki(this, organ);
		organ->umiera();
		return true;
	}
	else
	{
		(*this->getSwiat())->getGUI()->logWygranieWalki(organ, this);
		this->umiera();
		return false;
	}
}



bool Organizm::zjada(Organizm* roslina)
{
	if (roslina->jestZjedzonaPrzez(this)) {
		return true;
	}

	return false;
}



bool Organizm::jestZjedzonaPrzez(Organizm* zwierze)
{
	this->umiera();
	return true;
}



void Organizm::umiera()
{
	
	(*this->getSwiat())->clearOrganizm(this->getX(), this->getY());
}



const int Organizm::getWiek() {
	return this->wiek;
}



void Organizm::setWiek(int w) {
	this->wiek = w;
}



void Organizm::rozmnazanie() {}



void Organizm::getLosowaPozycja(int& dX, int& dY) {
	int random = rand() % 4;

	int xDifference = 0;
	int yDifference = 0;

	switch (random) {
	case 0:
		yDifference -= (range);
		break;
	case 1:
		xDifference += (range);
		break;
	case 2:
		yDifference += (range);
		break;
	case 3:
		xDifference -= (range);
		break;
	}

	if (this->wouldBeOutOfBounds(x + xDifference, y + yDifference)) {
		if (xDifference != 0) {
			xDifference = (-xDifference);
		}

		if (yDifference != 0) {
			yDifference = (-yDifference);
		}
	}

	dX = xDifference;
	dY = yDifference;
}



bool Organizm::jestZwierze() {
	return false;
}



bool Organizm::jestRoslina() {
	return false;
}



const int Organizm::getRange() {
	return this->range;
}



void Organizm::setInicjatywa(int i) {
	this->inicjatywa = i;
}



void Organizm::setRange(int r) {
	this->range = r;
}



void Organizm::setRepresentation(char c) {
	this->representation = c;
}



void Organizm::setColor(int c) {
	this->color = c;
}

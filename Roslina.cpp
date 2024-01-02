#include "Roslina.h"



Roslina::Roslina(int x, int y, Swiat** world, int sila, int inicjatywa, char representation, int color, int range, char* nazwa) : Organizm(x, y, world, sila, inicjatywa, representation, color, range, nazwa) {}



void Roslina::akcja() {
	this->rozmnazanie();
}



bool Roslina::kolizja(Organizm* organ) {
	return true;
}



void Roslina::rozmnazanie() {}



bool Roslina::jestZwierze() {
	return false;
}



bool Roslina::jestRoslina() {
	return true;
}
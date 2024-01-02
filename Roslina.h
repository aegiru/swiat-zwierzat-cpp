#pragma once

#include "Organizm.h"

class Roslina : public Organizm {
public:
	Roslina(int x, int y, Swiat** world, int sila, int inicjatywa, char representation, int color, int range, char* nazwa);
	void akcja() override;
	bool kolizja(Organizm* organ) override;
	virtual void rozmnazanie() override;
	virtual bool jestZwierze();
	virtual bool jestRoslina();
};
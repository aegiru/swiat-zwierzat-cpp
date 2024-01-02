#pragma once

#include "Organizm.h"

class Zwierze : public Organizm {
public:
	Zwierze(int x, int y, Swiat** world, int sila, int inicjatywa, char representation, int color, int range, char* nazwa);
	void akcja() override;
	bool kolizja(Organizm* organ) override;
	bool czyNieChceWejsc(Organizm* organ);
	virtual void rozmnazanie() override;
	bool jestZwierze();
	bool jestRoslina();
};
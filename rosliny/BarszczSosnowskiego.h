#pragma once

#include "../Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(int x, int y, Swiat** world);
	bool jestZjedzonaPrzez(Organizm* organ);
	void akcja();
	void rozmnazanie() override;
	void zabija(Organizm* zwierze);
};
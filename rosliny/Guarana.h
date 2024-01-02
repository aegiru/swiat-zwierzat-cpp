#pragma once

#include "../Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int x, int y, Swiat** world);
	bool jestZjedzonaPrzez(Organizm* organ);
	void rozmnazanie() override;
};
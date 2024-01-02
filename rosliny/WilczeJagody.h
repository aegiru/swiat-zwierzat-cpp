#pragma once

#include "../Roslina.h"

class WilczeJagody : public Roslina {
public:
	WilczeJagody(int x, int y, Swiat** world);
	bool jestZjedzonaPrzez(Organizm* organ);
	void rozmnazanie() override;
};
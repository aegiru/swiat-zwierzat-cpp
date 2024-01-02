#pragma once

#include "../Zwierze.h"

class Zolw : public Zwierze {


public:
	Zolw(int x, int y, Swiat** world);
	void akcja();
	bool czyOdbijaAtak(Organizm* organ);
	void rozmnazanie() override;
};
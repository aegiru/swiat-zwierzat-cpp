#pragma once

#include "../Zwierze.h"

class Antylopa : public Zwierze {


public:
	Antylopa(int x, int y, Swiat** world);
	bool czyUcieczkaPrzedWalka();
	bool ucieczka(Organizm* organ);
	void rozmnazanie() override;
};
#pragma once

#include "../Zwierze.h"

class Lis : public Zwierze {


public:
	Lis(int x, int y, Swiat** world);
	bool czyNieChceWejsc(Organizm* organ);
	void rozmnazanie() override;
};
#pragma once

#include "../Zwierze.h"

class Wilk : public Zwierze {


public:
	Wilk(int x, int y, Swiat** world);
	void rozmnazanie() override;
};
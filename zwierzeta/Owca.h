#pragma once

#include "../Zwierze.h"

class Owca : public Zwierze {


public:
	Owca(int x, int y, Swiat** world);
	void rozmnazanie() override;
};

#pragma once

#include "../Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(int x, int y, Swiat** world);
	void rozmnazanie() override;
};
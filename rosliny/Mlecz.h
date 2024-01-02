#pragma once

#include "../Roslina.h"


class Mlecz : public Roslina {
public:
	Mlecz(int x, int y, Swiat** world);
	void akcja();
	void rozmnazanie() override;
};
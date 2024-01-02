#pragma once

#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int turyUmiejetnosci = 0;


public:
	Czlowiek(int x, int y, Swiat** world);
	void akcja();
	void umiejetnosc();
	void zmianaUmiejetnosc();
	int getTury();
	void setTury(int n);
};
#pragma once

#include "GUI.h"
#include "Organizm.h"

class Swiat {
private:
	int sizeX;
	int sizeY;
	GUI** gui;
	Organizm** organizmy;
	int liczbaDodanychOrganizmow = 0;
	void setOrganizm(Organizm* organ);
	int tura = 0;



public:
	Swiat(int x, int y, GUI** gui);
	GUI* getGUI();
	void rysujSwiat();
	void wykonajTure();
	Organizm* getOrganizm(int id);
	Organizm* getOrganizm(int x, int y);
	void setOrganizm(int id, Organizm* organ);
	int getSizeX();
	int getSizeY();
	void dodajOrganizm(Organizm* organ);
	void clearOrganizm(int x, int y);
	bool czyPusty(int x, int y);
	void zamienOrganizmy(int i, int j);
	int partycja(int niskie, int wysokie);
	void sortujOrganizmy(int niskie, int wysokie);
	void posortujOrganizmy();
	bool czyPierwszyMniejszyRownyDrugi(Organizm* o1, Organizm* o2);
	int liczbaOrganizmow();
	int getTura();
	void setTura(int tura);
};

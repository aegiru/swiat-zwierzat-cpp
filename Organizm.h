#pragma once

class GUI;
class Swiat;


class Organizm {
protected:
	int sila = 0;
	int inicjatywa = 0;
	int x;
	int y;
	Swiat** world;
	int color = 0;
	char representation = '*';
	char* name = nullptr;
	int range = 1;
	bool wouldBeOutOfBounds(int x, int y);
	int wiek = 0;
	bool areOfSameType(Organizm* organ);
	void getLosowaPozycja(int& dX, int& dY);
	



public:
	Organizm(int x, int y, Swiat** world, int sila, int inicjatywa, char representation, int color, int range, char* nazwa);
	Organizm(const Organizm& organ);
	virtual void akcja() = 0;
	virtual bool kolizja(Organizm* organ) = 0;
	void rysowanie();
	const int getX(), getY();
	const int getSila();
	const int getInicjatywa();
	char getReprezentacja();
	const int getColor();
	const int getWiek();
	const int getRange();
	void setX(int x), setY(int y);
	void setSila(int s);
	void setWiek(int w);
	Swiat** getSwiat();
	const char* getName();
	virtual bool czyOdbijaAtak(Organizm* organ);
	virtual bool czyUciekaPrzedWalka();
	virtual bool ucieczka(Organizm* organ);
	virtual bool walka(Organizm* organ);
	virtual bool zjada(Organizm* roslina);
	virtual bool jestZjedzonaPrzez(Organizm* zwierze);
	void umiera();
	virtual void rozmnazanie();
	virtual bool jestZwierze();
	virtual bool jestRoslina();
	void setInicjatywa(int i);
	void setRange(int r);
	void setRepresentation(char c);
	void setColor(int c);
};

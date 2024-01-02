#pragma once
#include "Swiat.h"
#include "GUI.h"


class Kontener {
private:
	Swiat* world;
	GUI* graphics;
	
	Organizm* interpret(char* nazwa, int x, int y);


public:
	Kontener(int sizeX, int sizeY, int index, char* firstName, char* surname);
	Kontener(char* filename);
	void przykladoweOrganizmy1();
	void rozpocznijGre();
	void zapiszSwiat(char* filename);
	
};
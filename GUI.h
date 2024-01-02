#pragma once

#include "Organizm.h"

class GUI {
private:
	char border;
	int index = 0;
	int loggedThisTurn = 0;
	char* surname = "White";
	char* firstName = "Walter";
	int offsetX, offsetY;
	int worldSizeX, worldSizeY;
	void printChar(const char a);
	void printInt(const int i);
	void printCharArray(const char* s);
	void printAt(const int x, const int y, const char* string, int c);
	void printAt(const int x, const int y, const char n, int c);
	void printAt(const int x, const int y, const int i, int c);
	void goTo(const int x, const int y);
	void goAndSetColor(const int x, const int y, const int c);
	void hideCursor();
	void setColor(const int n);
	void drawHorizontalLine(const int startX, const int startY, const int length);
	void drawVerticalLine(const int startX, const int startY, const int length);
	void drawRectangle(const int startX, const int startY, const int width, const int height);
	void drawWorldBorder();
	void drawStudentDetails();
	void drawTurnDetails(int tura);
	void logAction(Organizm* subject, Organizm* object, char* akcja);



public:
	GUI(char border, int worldSizeX, int worldSizeY, int offsetX, int offsetY, int index, char* name, char* surname);
	void drawGUI(int tura);
	void clear();
	void logJedzenie(Organizm* subject, Organizm* object);
	void logWygranieWalki(Organizm* subject, Organizm* object);
	void logBarszczyk(Organizm* barszcz, Organizm* zwierze);
	void logUnik(Organizm* lopa, Organizm* zwierze);
	void logOdbicie(Organizm* zolw, Organizm* zwierze);
	void logNieWejdzie(Organizm* lis, Organizm* inne);
	void end();
	void drawWorldElement(const int x, const int y, const char r, const int c);
	const int getInput();
	const int getIndex();
	const char* getFirstName();
	const char* getSurname();
	const int keyUp = 72;
	const int keyDown = 80;
	const int keyLeft = 75;
	const int keyRight = 77;
	const int keyN = 110;
	const int keyU = 117;
};

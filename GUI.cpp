#include "GUI.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

using namespace std;



GUI::GUI(char border, int worldSizeX, int worldSizeY, int offsetX, int offsetY, int index, char* name, char* surname) {
	this->border = border;
	this->worldSizeX = worldSizeX;
	this->worldSizeY = worldSizeY;
	this->offsetX = offsetX;
	this->offsetY = offsetY;
	this->index = index;
	this->firstName = name;
	this->surname = surname;
}



void GUI::printCharArray(const char* s) {
	cout << s;
}



void GUI::printChar(const char a) {
	cout << a;
}



void GUI::printInt(const int i) {
	cout << i;
}



void GUI::printAt(const int x, const int y, const char* string, int c) {
	this->goAndSetColor(x, y, c);
	printCharArray(string);
}



void GUI::printAt(const int x, const int y, const char n, int c) {
	this->goAndSetColor(x, y, c);
	this->printChar(n);
}



void GUI::printAt(const int x, const int y, const int i, int c) {
	this->goAndSetColor(x, y, c);
	this->printInt(i);
}



void GUI::goTo(const int x, const int y) {
	COORD coordinate;

	coordinate.X = x;
	coordinate.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
	this->hideCursor();
}



void GUI::goAndSetColor(const int x, const int y, const int c) {
	this->goTo(x, y);
	this->setColor(c);
}



void GUI::hideCursor() {
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}



void GUI::setColor(const int n) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}



void GUI::drawHorizontalLine(const int startX, const int startY, const int length) {
	for (int i = 0; i < length; i++) {
		this->printAt(startX + i, startY, this->border, 15);
	}
}



void GUI::drawVerticalLine(const int startX, const int startY, const int length) {
	for (int i = 0; i < length; i++) {
		this->printAt(startX , startY + i, this->border, 15);
	}
}



void GUI::drawRectangle(const int startX, const int startY, const int width, const int height) {
	this->drawHorizontalLine(startX, startY, width);
	this->drawHorizontalLine(startX, startY + height - 1, width);

	this->drawVerticalLine(startX, startY, height);
	this->drawVerticalLine(startX + width - 1, startY, height);
}



void GUI::drawWorldBorder() {
	int startX = this->offsetX;
	int startY = this->offsetY;
	int width = this->worldSizeX + 2;
	int length = this->worldSizeY + 2;

	this->drawRectangle(startX, startY, width, length);
}



void GUI::drawStudentDetails() {
	int startX = this->offsetX + this->worldSizeX + 4;
	int startY = this->offsetY;

	printAt(startX, startY, "Student:", 15);
	printAt(startX, startY + 1, this->getFirstName(), 15);
	printAt(startX, startY + 2, this->getSurname(), 15);
	printAt(startX, startY + 3, this->getIndex(), 15);
}



void GUI::drawTurnDetails(int tura) {
	int startX = this->offsetX;
	int startY = this->offsetY + this->worldSizeY + 3;
	
	this->printAt(startX, startY, "Tura:", 15);
	this->printAt(startX + 6, startY, tura, 15);
	this->printAt(startX, startY + 1, "Logs:", 15);
}



void GUI::logAction(Organizm* subject, Organizm* object, char* akcja) {
	int startX = this->offsetX;
	int startY = this->offsetY + this->worldSizeY + 5 + loggedThisTurn;

	this->goTo(startX, startY);
	this->setColor(subject->getColor());
	cout << subject->getName() << " (" << subject->getX() << ", " << subject->getY() << ") ";
	this->setColor(15);
	cout << akcja;
	this->setColor(object->getColor());
	cout << " " << object->getName() << " (" << object->getX() << ", " << object->getY() << ")";

	this->loggedThisTurn++;
}



void GUI::clear() {
	this->loggedThisTurn = 0;
	system("cls");
}



void GUI::drawGUI(int tura) {
	srand((unsigned)time(NULL));
	this->drawWorldBorder();
	this->drawStudentDetails();
	this->drawTurnDetails(tura);
}



void GUI::logJedzenie(Organizm* subject, Organizm* object) {
	this->logAction(subject, object, "zjada");
}


void GUI::logWygranieWalki(Organizm* subject, Organizm* object) {
	this->logAction(subject, object, "zabija");
}


void GUI::logBarszczyk(Organizm* barszcz, Organizm* zwierze) {
	this->logAction(zwierze, barszcz, "wdepnelo w");
}



void GUI::drawWorldElement(const int x, const int y, const char r, const int c) {
	int drawX = this->offsetX + x + 1;
	int drawY = this->offsetY + y + 1;

	this->printAt(drawX, drawY, r, c);
}



const int GUI::getInput() {
	return getch();
}



void GUI::end() {
	this->clear();
	this->goTo(0, 0);
}



const int GUI::getIndex() {
	return this->index;
}



const char* GUI::getFirstName() {
	return this->firstName;
}



const char* GUI::getSurname() {
	return this->surname;
}



void GUI::logOdbicie(Organizm* zolw, Organizm* zwierze) {
	this->logAction(zolw, zwierze, "odbija atak");
}



void GUI::logNieWejdzie(Organizm* lis, Organizm* inne) {
	this->logAction(lis, inne, "omija");
}



void GUI::logUnik(Organizm* lopa, Organizm* inne) {
	this->logAction(lopa, inne, "ucieka od");
}
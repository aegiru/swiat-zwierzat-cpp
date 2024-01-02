#pragma once

#include <conio.h>
#include <cstdio>
#include <string.h>

#define STRINGLENGTH 25

#include "Kontener.h"
#include "GUI.h"
#include "Swiat.h"
#include "rosliny/BarszczSosnowskiego.h"
#include "rosliny/Guarana.h"
#include "rosliny/Mlecz.h"
#include "rosliny/Trawa.h"
#include "rosliny/WilczeJagody.h"
#include "zwierzeta/Antylopa.h"
#include "zwierzeta/Lis.h"
#include "zwierzeta/Owca.h"
#include "zwierzeta/Wilk.h"
#include "zwierzeta/Zolw.h"
#include "Czlowiek.h"

Kontener::Kontener(int sizeX, int sizeY, int index, char* firstName, char* surname) {
	this->graphics = new GUI('#', sizeX, sizeY, 1, 1, index, firstName, surname);

	this->world = new Swiat(sizeX, sizeY, &graphics);
}



Kontener::Kontener(char* filename) {
	FILE* fp;

	fp = fopen(filename, "r");

	int sizeX, sizeY, index, liczbaOrganizmow, tura;
	char* firstName = new char[STRINGLENGTH];
	char* surname = new char[STRINGLENGTH];

	fscanf(fp, "%d %d %d %d", &sizeX, &sizeY, &index, tura);
	fscanf(fp, "%s", firstName);
	fscanf(fp, "%s", surname);
	fscanf(fp, "%d", &liczbaOrganizmow);

	this->graphics = new GUI('#', sizeX, sizeY, 1, 1, index, firstName, surname);

	this->world = new Swiat(sizeX, sizeY, &graphics);
	this->world->setTura(tura);

	for (int i = 0; i < liczbaOrganizmow; i++) {
		int x, y, sila, inicjatywa, wiek, range, color;
		char representation;
		char nazwa[STRINGLENGTH];

		fscanf(fp, "%s %d %d %d %d %d %d %c %d", nazwa, &x, &y, &sila, &inicjatywa, &wiek, &range, &representation, &color);

		Organizm* organ = interpret(nazwa, x, y);
		organ->setSila(sila);
		organ->setInicjatywa(inicjatywa);
		organ->setRange(range);
		organ->setRepresentation(representation);
		organ->setColor(color);

		this->world->dodajOrganizm(organ);

		organ->setWiek(wiek);
	}

	fclose(fp);
}



void Kontener::rozpocznijGre() {
	bool toContinue = true;

	while (toContinue) {
		this->world->rysujSwiat();

		this->world->posortujOrganizmy();

		this->world->wykonajTure();

		char ch = _getch();

		switch (ch) {
		case 'q':
			this->world->getGUI()->end();
			toContinue = false;
			break;
		default:
			this->world->wykonajTure();
			break;
		}
	}
}



void Kontener::przykladoweOrganizmy1() {
	Czlowiek* gracz = new Czlowiek(0, 0, &this->world);
	this->world->dodajOrganizm(gracz);

	Owca* owca1 = new Owca(8, 8, &this->world);
	this->world->dodajOrganizm(owca1);

	Owca* owca2 = new Owca(10, 10, &this->world);
	this->world->dodajOrganizm(owca2);

	BarszczSosnowskiego* barszczyk = new BarszczSosnowskiego(13, 13, &this->world);
	this->world->dodajOrganizm(barszczyk);
}



void Kontener::zapiszSwiat(char* filename) {
	FILE* fp;
	fp = fopen(filename, "w");

	int sizeX = this->world->getSizeX();
	int sizeY = this->world->getSizeY();

	fprintf(fp, "%d %d %d %d\n", sizeX, sizeY, this->graphics->getIndex(), this->world->getTura());
	fprintf(fp, "%s\n", this->graphics->getFirstName());
	fprintf(fp, "%s\n", this->graphics->getSurname());

	int liczbaOrganizmow = this->world->liczbaOrganizmow();

	fprintf(fp, "%d\n", liczbaOrganizmow);

	for (int i = 0; i < (sizeX * sizeY); i++) {
		Organizm* organ = this->world->getOrganizm(i);

		if (organ != nullptr) {
			fprintf(fp, "%s %d %d %d %d %d %d %c %d\n", organ->getName(), organ->getX(), organ->getY(), organ->getSila(), organ->getInicjatywa(), organ->getWiek(), organ->getRange(), organ->getReprezentacja(), organ->getColor());
		}
	}

	fclose(fp);
}



Organizm* Kontener::interpret(char* nazwa, int x, int y) {
	Organizm* organ = nullptr;

	if (strcmp(nazwa, "Antylopa") == 0) {
		organ = new Antylopa(x, y, &this->world);
	}

	if (strcmp(nazwa, "Lis") == 0) {
		organ = new Lis(x, y, &this->world);
	}

	if (strcmp(nazwa, "Owca") == 0) {
		organ = new Owca(x, y, &this->world);
	}

	if (strcmp(nazwa, "Wilk") == 0) {
		organ = new Wilk(x, y, &this->world);
	}

	if (strcmp(nazwa, "Zolw") == 0) {
		organ = new Zolw(x, y, &this->world);
	}

	if (strcmp(nazwa, "BarszczSosnowskiego") == 0) {
		organ = new BarszczSosnowskiego(x, y, &this->world);
	}

	if (strcmp(nazwa, "Guarana") == 0) {
		organ = new Guarana(x, y, &this->world);
	}

	if (strcmp(nazwa, "Mlecz") == 0) {
		organ = new Mlecz(x, y, &this->world);
	}

	if (strcmp(nazwa, "Trawa") == 0) {
		organ = new Trawa(x, y, &this->world);
	}

	if (strcmp(nazwa, "WilczeJagody") == 0) {
		organ = new WilczeJagody(x, y, &this->world);
	}

	if (strcmp(nazwa, "Czlowiek") == 0) {
		organ = new Czlowiek(x, y, &this->world);
	}

	return organ;
}
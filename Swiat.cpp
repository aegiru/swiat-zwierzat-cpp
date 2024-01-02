#include "Swiat.h"
#include "GUI.h"
#include "Organizm.h"



void Swiat::setOrganizm(Organizm* organ) {
	for (int i = 0; i < (this->getSizeX() * this->getSizeY()); i++) {
		if (organizmy[i] == nullptr) {
			organizmy[i] = organ;
			return;
		}
	}
}



int Swiat::getSizeX() {
	return this->sizeX;
}



int Swiat::getSizeY() {
	return this->sizeY;
}



void Swiat::clearOrganizm(int x, int y) {
	for (int i = 0; i < (this->getSizeX() * this->getSizeY()); i++) {
		if (organizmy[i] != nullptr) {
			if (organizmy[i]->getX() == x && organizmy[i]->getY() == y) {
				delete organizmy[i];
				organizmy[i] = nullptr;
				return;
			}
		}
	}
}



Swiat::Swiat(int x, int y, GUI** gui) {
	this->sizeX = x;
	this->sizeY = y;

	this->gui = gui;

	this->organizmy = new Organizm*[x * y];

	for (int i = 0; i < (x * y); i++) {
		this->organizmy[i] = nullptr;
	}
}



GUI* Swiat::getGUI() {
	return (*this->gui);
}



void Swiat::rysujSwiat() {
	this->tura++;
	this->getGUI()->drawGUI(this->tura);

	for (int i = 0; i < (this->getSizeX() * this->getSizeY()); i++) {
		Organizm* temp = this->getOrganizm(i);

		if (temp != nullptr) {
			temp->rysowanie();
		}
	}
}



void Swiat::wykonajTure() {
	for (int i = (this->getSizeX() * this->getSizeY()) - 1; i >= 0; i--) {
		Organizm* temp = this->getOrganizm(i);

		if (temp != nullptr) {
			temp->akcja();
		}
	}
}



Organizm* Swiat::getOrganizm(int x, int y) {
	for (int i = 0; i < (this->getSizeX() * this->getSizeY()); i++) {
		Organizm* temp = this->getOrganizm(i);

		if (temp != nullptr) {
			if (temp->getX() == x && temp->getY() == y) {
				return organizmy[i];
			}
		}
	}

	return nullptr;
}



Organizm* Swiat::getOrganizm(int id) {
	return this->organizmy[id];
}



void Swiat::dodajOrganizm(Organizm* organ) {
	organ->setWiek(this->liczbaDodanychOrganizmow);
	this->liczbaDodanychOrganizmow++;
	this->setOrganizm(organ);
}



void Swiat::setOrganizm(int id, Organizm* organ) {
	this->organizmy[id] = organ;
}



bool Swiat::czyPusty(int x, int y) {
	if (this->getOrganizm(x, y) == nullptr) {
		return true;
	}

	return false;
}



void Swiat::zamienOrganizmy(int i, int j) {
	Organizm* temp = this->getOrganizm(i);
	this->setOrganizm(i, this->getOrganizm(j));
	this->setOrganizm(j, temp);
}



int Swiat::partycja(int niskie, int wysokie) {
	Organizm* pivot = this->getOrganizm(wysokie);

	int i = (niskie - 1);

	for (int j = niskie; j < wysokie; j++) {
		if (this->czyPierwszyMniejszyRownyDrugi(this->getOrganizm(j), pivot)) {
			i++;

			this->zamienOrganizmy(i, j);
		}
	}

	this->zamienOrganizmy(i + 1, wysokie);

	return (i + 1);
}



void Swiat::sortujOrganizmy(int niskie, int wysokie) {
	if (niskie < wysokie) {
		int pi = this->partycja(niskie, wysokie);

		this->sortujOrganizmy(niskie, pi - 1);
		this->sortujOrganizmy(pi + 1, wysokie);
	}
}



void Swiat::posortujOrganizmy() {
	this->sortujOrganizmy(0, (this->getSizeX() * this->getSizeY()) - 1);
}



bool Swiat::czyPierwszyMniejszyRownyDrugi(Organizm* o1, Organizm* o2) {
	if (o1 == nullptr && o2 != nullptr) {
		return true;
	}

	if (o1 != nullptr && o2 == nullptr) {
		return false;
	}

	if (o1 == nullptr && o2 == nullptr) {
		return false;
	}

	if (o1 != nullptr && o2 != nullptr) {
		if (o1->getInicjatywa() < o2->getInicjatywa()) {
			return true;
		}

		if (o1->getInicjatywa() == o2->getInicjatywa()) {
			if (o1->getWiek() > o2->getWiek()) {
				return true;
			}
		}
	}

	return false;
}



int Swiat::liczbaOrganizmow() {
	int l = 0;

	for (int i = 0; i < (this->getSizeX() * this->getSizeY()); i++) {
		if (this->getOrganizm(i) != nullptr) {
			l++;
		}
	}

	return l;
}



int Swiat::getTura() {
	return this->tura;
}



void Swiat::setTura(int tura) {
	this->tura = tura;
}

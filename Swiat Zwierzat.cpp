#include "Kontener.h"
#include "Swiat Zwierzat.h"

using namespace std;

int main()
{
	Kontener* main = new Kontener(15, 15, DS_INDEKS, DS_IMIE, DS_NAZWISKO);

	main->przykladoweOrganizmy1();
	main->rozpocznijGre();
	
	main->zapiszSwiat("uwu.txt");

	Kontener* main2 = new Kontener("uwu.txt");
	main2->rozpocznijGre();

	return 0;
}

#include <iostream>
#include "ProducerFactory.h"
#include "MartinScorseseFilms.h"
#include "StevenSpielbergFilms.h"

using namespace std;

int main()
{
	ProducerFactory *producer1, *producer2;
	CriminalFilms *cFilm1, *cFilm2;
	HistoryFilms *hFilm1, *hFilm2;

	producer1 = new StevenSpielbergFilms();
	producer2 = new MartinScorseseFilms();

	cFilm1 = producer1->createCriminalFilms();
	hFilm1 = producer1->createHistoryFilms();

	cFilm2 = producer2->createCriminalFilms();
	hFilm2 = producer2->createHistoryFilms();

	cFilm1->print();
	hFilm1->print();
	cout << endl;
	cFilm2->print();
	hFilm2->print();

	cout << endl;
	system("pause");
}
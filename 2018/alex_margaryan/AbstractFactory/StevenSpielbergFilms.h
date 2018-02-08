#pragma once
#include "ProducerFactory.h"
#include "SS_CriminalFilm.h"
#include "SS_HistoryFilm.h"

class StevenSpielbergFilms: public ProducerFactory
{
public:
	CriminalFilms *createCriminalFilms()
	{
		return new SS_CriminalFilm;
	}
	HistoryFilms *createHistoryFilms()
	{
		return new SS_HistoryFilm;
	}
};


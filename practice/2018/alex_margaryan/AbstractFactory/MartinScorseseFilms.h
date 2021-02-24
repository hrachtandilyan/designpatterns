#pragma once
#include "ProducerFactory.h"
#include "MS_CriminalFilm.h"
#include "MS_HistoryFilm.h"

class MartinScorseseFilms: public ProducerFactory
{
public:
	CriminalFilms *createCriminalFilms()
	{
		return new MS_CriminalFilm();
	}
	HistoryFilms *createHistoryFilms()
	{
		return new MS_HistoryFilm;
	}
};


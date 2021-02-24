#pragma once
#include "CriminalFilms.h"
#include "HistoryFilms.h"

class ProducerFactory
{
public:
	virtual CriminalFilms *createCriminalFilms() = 0;
	virtual HistoryFilms *createHistoryFilms() = 0;
};


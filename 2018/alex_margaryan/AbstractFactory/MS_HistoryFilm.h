#pragma once
#include <iostream>
#include "HistoryFilms.h"

class MS_HistoryFilm: public HistoryFilms
{
public:
	void print()
	{
		std::cout << "Gangs of New York" << std::endl;
	}
};


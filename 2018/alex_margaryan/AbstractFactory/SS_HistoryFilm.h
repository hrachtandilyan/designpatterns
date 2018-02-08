#pragma once
#include <iostream>
#include "HistoryFilms.h"

class SS_HistoryFilm: public HistoryFilms
{
public:
	void print()
	{
		std::cout << "Schindler's list" << std::endl;
	}
};


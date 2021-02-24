#pragma once
#include <iostream>
#include "CriminalFilms.h"

class SS_CriminalFilm: public CriminalFilms
{
public:
	void print()
	{
		std::cout << "Catch Me If You Can" << std::endl;
	}
};

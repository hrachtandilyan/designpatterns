#pragma once
#include <iostream>
#include "CriminalFilms.h"

class MS_CriminalFilm: public CriminalFilms
{
public:
	void print()
	{
		std::cout << "The Departed" << std::endl;
	}
};


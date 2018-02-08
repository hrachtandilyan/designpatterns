#pragma once
#include <string>

class SuperHeroBase
{
public:
	virtual std::string lifeBeforeSuperpower() = 0;
	virtual std::string gettingSuperpower() = 0;
	virtual std::string saveWorld() = 0;
	virtual std::string getName() = 0;
	virtual ~SuperHeroBase()
	{}
};
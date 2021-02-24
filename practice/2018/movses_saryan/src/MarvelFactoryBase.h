#pragma once
#include <memory>

#include "SuperHeroBase.h"
#include "BadGuyBase.h"
#include "MainGirlBase.h"

class MarvelFactoryBase
{
public:
	virtual std::unique_ptr<SuperHeroBase> createSuperHero(bool censored = false) = 0;
	virtual std::unique_ptr<BadGuyBase> createBadGuy() = 0;
	virtual std::unique_ptr<MainGirlBase> createMainGirl() = 0;
	virtual ~MarvelFactoryBase()
	{}
};

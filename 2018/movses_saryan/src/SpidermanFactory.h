#pragma once
#include "MarvelFactoryBase.h"
#include "BadGuyBase.h"
#include "MainGirlBase.h"
#include "SuperHeroBase.h"

class SpidermanFactory : public MarvelFactoryBase
{
public:
	virtual std::unique_ptr<SuperHeroBase> createSuperHero(bool censored = false) override;
	virtual std::unique_ptr<BadGuyBase> createBadGuy() override;
	virtual std::unique_ptr<MainGirlBase> createMainGirl() override;
public:
	static SpidermanFactory& getInstance()
	{
		static SpidermanFactory inst;
		return inst;
	}
public:
	SpidermanFactory(SpidermanFactory&) = delete;
	SpidermanFactory(SpidermanFactory&&) = delete;
	SpidermanFactory& operator= (SpidermanFactory&) = delete;
	SpidermanFactory& operator= (SpidermanFactory&&) = delete;
private:
	SpidermanFactory()
	{}

};

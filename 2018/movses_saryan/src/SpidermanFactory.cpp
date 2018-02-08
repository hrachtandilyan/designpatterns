#include "SpidermanFactory.h"
#include "SpidermanClasses.h"
#include "Censored.h"

std::unique_ptr<SuperHeroBase> SpidermanFactory::createSuperHero(bool censored)
{
	return censored ? std::make_unique<Censored<SpiderMan> >() : std::make_unique<SpiderMan>();
}

std::unique_ptr<BadGuyBase> SpidermanFactory::createBadGuy()
{
	return std::make_unique<Evil>();
}

std::unique_ptr<MainGirlBase> SpidermanFactory::createMainGirl()
{
	return std::make_unique<MerryJnae>();
}
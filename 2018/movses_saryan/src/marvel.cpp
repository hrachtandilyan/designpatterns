#include <iostream>
#include <memory>

#include "MarvelFactoryBase.h"
#include "SpidermanFactory.h"

void playMovie(MarvelFactoryBase& factory)
{
	std::unique_ptr<SuperHeroBase> hero = factory.createSuperHero(true);
	std::unique_ptr<MainGirlBase> girl = factory.createMainGirl();
	std::unique_ptr<BadGuyBase> guy = factory.createBadGuy();

	std::cout << hero->getName() << ": " << hero->lifeBeforeSuperpower() << std::endl;
	std::cout << hero->getName() << ": " << hero->gettingSuperpower() << std::endl;
	std::cout << girl->getName() << ": " << girl->expressLove() << std::endl;
	std::cout << guy->getName() << ": " << guy->lifeBeforEvil() << std::endl;
	std::cout << guy->getName() << ": " << guy->evilPlan() << std::endl;
	std::cout << hero->getName() << ": " << hero->saveWorld() << std::endl;
	std::cout << guy->getName() << ": " << guy->evilLaugh() << std::endl;
	std::cout << guy->getName() << ": " << guy->die() << std::endl;
	std::cout << "Happy end" << std::endl;
}
int main()
{
	MarvelFactoryBase& factory = SpidermanFactory::getInstance(); //can be replaced with say SupermanFactory
	playMovie(factory);
	return 0;
}
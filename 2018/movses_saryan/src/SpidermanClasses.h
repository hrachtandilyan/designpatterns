#pragma once
#include <string>

#include "SuperHeroBase.h"
#include "BadGuyBase.h"
#include "MainGirlBase.h"

class SpiderMan : public SuperHeroBase
{
public:
	virtual std::string lifeBeforeSuperpower() override
	{
		return "I was fucking shit before I got my superpower";
	}
	virtual std::string gettingSuperpower() override
	{
		return "I was fucking amazed when I suddenly got the superpower";
	}
	virtual std::string saveWorld() override
	{
		return "I will save this fucking world";
	}
	virtual std::string getName() override
	{
		return "Spider-man";
	}
};

//don't remember the real name
class Evil : public BadGuyBase
{
public:
	virtual std::string lifeBeforEvil() override
	{
		return "I was poor guy, everyone bit me";
	}
	virtual std::string evilPlan() override
	{
		return "I will destroy the world!!(idk why)";
	}
	virtual std::string die() override
	{
		return "Ooo superhero you killed me now i am dead";
	}
	virtual std::string evilLaugh() override
	{
		return "Buahahahahha";
	}
	virtual std::string getName() override
	{
		return "Evil";
	}
};

class MerryJnae : public MainGirlBase
{
public:
	virtual std::string expressLove() override
	{
		return "I love you spiderman!!";
	}
	virtual std::string getName() override
	{
		return "Merry Jnae";
	}
};
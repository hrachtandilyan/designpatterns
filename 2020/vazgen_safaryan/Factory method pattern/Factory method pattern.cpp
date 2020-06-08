#include "pch.h"
#include <iostream>
#include <vector>

// Game characters' hierarchy

class Warrior
{
public:
	virtual void info() = 0;
	virtual ~Warrior() {}
};

class Infantryman : public Warrior
{
public:
	void info() {
		std::cout << "Infantryman" << std::endl;
	};
};

class Archer : public Warrior
{
public:
	void info() {
		std::cout << "Archer" << std::endl;
	};
};

class Horseman : public Warrior
{
public:
	void info() {
		std::cout << "Horseman" << std::endl;
	};
};


// Factory of objects
class Factory
{
public:
	virtual Warrior* createWarrior() = 0;
	virtual ~Factory() {}
};

class InfantryFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Infantryman;
	}
};

class ArchersFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Archer;
	}
};

class CavalryFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Horseman;
	}
};


//Creation of objects with factory of objects
int main()
{
	InfantryFactory* infantry_factory = new InfantryFactory;
	ArchersFactory*  archers_factory = new ArchersFactory;
	CavalryFactory*  cavalry_factory = new CavalryFactory;

	std::vector<Warrior*> v;
	v.push_back(infantry_factory->createWarrior());
	v.push_back(archers_factory->createWarrior());
	v.push_back(cavalry_factory->createWarrior());

	for (int i = 0; i < v.size(); i++)
	{
		v[i]->info();
	}
}
#pragma once

#include <iostream>
#include <vector>


class rockBand
{
public:
	virtual void info() = 0;
	virtual ~rockBand() {}
};

class Vocalist : public rockBand
{
public:
	void info() {
		std::cout << "Vocalist" << std::endl;
	};
};

class Guitarist : public rockBand
{
public:
	void info() {
		std::cout << "Guitarist" << std::endl;
	};
};

class Drummer : public rockBand
{
public:
	void info() {
		std::cout << "Drummer" << std::endl;
	};
};


class Factory
{
public:
	virtual rockBand* create_rockBand() = 0;
	virtual ~Factory() {}
};

class VocalistFactory : public Factory
{
public:
	rockBand* create_rockBand() {
		return new Vocalist;
	}
};

class GuitaristFactory : public Factory
{
public:
	rockBand* create_rockBand() {
		return new Guitarist;
	}
};

class DrummerFactory : public Factory
{
public:
	Drummer* create_rockBand() {
		return new Drummer;
	}
};


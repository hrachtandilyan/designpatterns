#pragma once
#include "Watches.h"
#include "Quartz.h"
#include "Automatic.h"
#include "Mechanical.h"

class FacadeWatches
{
public:
	FacadeWatches()
	{
		quartz = new Quartz();
		mechanical = new Mechanical();
		automatic = new Automatic();
	}
	void printQuartz()
	{
		quartz->print();
	}
	void printMechanical()
	{
		mechanical->print();
	}
	void printAutomatic()
	{
		automatic->print();
	}
	
private:
	Watches *quartz;
	Watches *mechanical;
	Watches *automatic;
};


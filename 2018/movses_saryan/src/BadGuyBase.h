#pragma once
#include <string>

class BadGuyBase
{
public:
	virtual std::string lifeBeforEvil() = 0;
	virtual std::string evilPlan() = 0;
	virtual std::string die() = 0;
	virtual std::string evilLaugh() = 0;
	virtual std::string getName() = 0;
	virtual ~BadGuyBase()
	{}
};

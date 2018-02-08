#pragma once
#include <string>

class MainGirlBase
{
public:
	virtual std::string expressLove() = 0;
	virtual std::string getName() = 0;
	virtual ~MainGirlBase()
	{}
};
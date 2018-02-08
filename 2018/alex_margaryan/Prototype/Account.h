#pragma once
class Account
{
public:
	virtual void print() = 0;
	virtual Account* clone() = 0;
};


#pragma once
class Singleton
{
private:
	static Singleton* instance;
	Singleton();
public:
	static Singleton* getInstance();	
};
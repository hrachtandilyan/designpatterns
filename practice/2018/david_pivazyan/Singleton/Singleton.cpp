#include "Singleton.h"

Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
	if (instance == 0)                  //Meyer's Singleton!
	{									//
		instance = new Singleton();		//
	}									//
	return instance;}					//

Singleton::Singleton()
{}
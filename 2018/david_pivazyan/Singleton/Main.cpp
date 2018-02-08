#include <iostream>
#include "Singleton.h"
int main()
{
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	Singleton* s3 = Singleton::getInstance();
	Singleton* s4 = Singleton::getInstance();

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
}
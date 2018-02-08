#include <iostream>
#include "Guns.h"
#include "Decorator.h"
#include "Rifle.h"
#include "Muffler.h"
#include "Scope.h"

using namespace std;

int main()
{
	Guns *gun = new Muffler(new Scope(new Rifle()));
	cout << "The gun's weight is " << gun->getWeight() << " kg" << endl;
	cout << "The gun's price is " << gun->getCost() << " $" << endl;
	
	cout << endl;
	system("pause");
}
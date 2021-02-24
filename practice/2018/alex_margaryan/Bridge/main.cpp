#include <iostream>
#include "Coffee.h"
#include "Cappuccino.h"
#include "Espresso.h"
#include "Packaging.h"
#include "VacuumSealedBags.h"
#include "ValveSealedBags.h"

using namespace std;

int main()
{
	Coffee * coffee1 = new Espresso(new ValveSealedBags());
	Coffee * coffee2 = new Cappuccino(new VacuumSealedBags());

	coffee1->print();
	coffee2->print();

	cout << endl;
	system("pause");
}
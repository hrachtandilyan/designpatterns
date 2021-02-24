#include <iostream>
#include "Bike.h"
#include "Engineer.h"
#include "BikeBuilder.h"
#include "TrekBuilder.h"
#include "CubeBuilder.h"


using namespace std;

int main()
{
	Bike * bike;
	BikeBuilder * builder1 = new TrekBuilder();
	Engineer * engineer = new Engineer(builder1);
	engineer->buildBike();
	bike = engineer->getBike();

	cout << endl << endl;

	BikeBuilder * builder2 = new CubeBuilder();
	engineer = new Engineer(builder2);
	engineer->buildBike();
	bike = engineer->getBike();

	cout << endl;
	system("pause");
}
#include <iostream>
#include "FacadeWatches.h"

using namespace std;

int main()
{
	FacadeWatches *facadewatches = new FacadeWatches();
	facadewatches->printAutomatic();
	facadewatches->printMechanical();
	facadewatches->printQuartz();

	system("pause");
}
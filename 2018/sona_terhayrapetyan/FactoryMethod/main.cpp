#include "FactoryMethod.h"

int main()
{
	VocalistFactory* vocalist_factory = new VocalistFactory;
	GuitaristFactory*  guitarist_factory = new GuitaristFactory;
	DrummerFactory*  drummer_factory = new DrummerFactory;

	std::vector<rockBand*> v;
	v.push_back(vocalist_factory->create_rockBand());
	v.push_back(guitarist_factory->create_rockBand());
	v.push_back(drummer_factory->create_rockBand());

	for (int i = 0; i<v.size(); i++)
		v[i]->info();

	system("pause");
	return 0;
}
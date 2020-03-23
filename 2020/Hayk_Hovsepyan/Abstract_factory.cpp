#include <iostream>
#include <string>
using namespace std;

class Phones
{
public:
	virtual void phone_characteristics() const = 0;
	virtual ~Phones() {};
};

class Iphone11 : public Phones
{
public:
	int price_in_dollars = 930;
	void phone_characteristics() const override
	{
		cout << "Iphone 11 characteristics...\n";
	}
};

class GalaxyS20 : public Phones
{
public:
	int price_in_dollars = 990;
	void phone_characteristics() const override
	{
		cout << "Galaxy S20 characteristics...\n";
	}
};

class Tablets
{
public:
	virtual void tablet_characteristics() const = 0;
	virtual ~Tablets() {};
};

class IpadPro : public Tablets
{
public:
	int price_in_dollars = 1400;
	void tablet_characteristics() const
	{
		cout << "Ipad Pro characteristics...\n";
	}
};

class GalaxyTabS6 : public Tablets
{
public:
	int price_in_dollars = 850;
	void tablet_characteristics() const
	{
		cout << "Galaxy Tab S6 characteristics...\n";
	}
};

class AbstractGadgetsShop
{
public:
	virtual Phones *return_phone() const = 0;
	virtual Tablets *return_tablet() const = 0;
};

class Apple : public AbstractGadgetsShop
{
public:
	Phones *return_phone() const
	{
		return new Iphone11();
	}
	Tablets *return_tablet() const
	{
		return new IpadPro();
	}
};

class Samsung : public AbstractGadgetsShop
{
public:
	Phones *return_phone() const
	{
		return new GalaxyS20();
	}
	Tablets *return_tablet() const
	{
		return new GalaxyTabS6();
	}
};

void ShowProducts(const AbstractGadgetsShop &factory)
{
	Phones *a = factory.return_phone();
	Tablets *b = factory.return_tablet();
	a->phone_characteristics();
	b->tablet_characteristics();
	delete a;
	delete b;
}

int main()
{
	Apple *f1 = new Apple();
	Samsung *f2 = new Samsung();
	ShowProducts(*f1);
	ShowProducts(*f2);
	delete f1;
	delete f2;
}

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

class AbstractGagdetsShop
{
public:
	virtual Phones *AppleProduct() const = 0;
	virtual Tablets *SamsungProduct() const = 0;
};

class Apple : public AbstractGagdetsShop
{
public:
	Phones *AppleProduct() const
	{
		return new Iphone11();
	}
	Tablets *SamsungProduct() const
	{
		return new IpadPro();
	}
};

class Samsung : public AbstractGagdetsShop
{
public:
	Phones *AppleProduct() const
	{
		return new GalaxyS20();
	}
	Tablets *SamsungProduct() const
	{
		return new GalaxyTabS6();
	}
};

void ShowProducts(const AbstractGagdetsShop &factory)
{
	Phones *a = factory.AppleProduct();
	Tablets *b = factory.SamsungProduct();
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

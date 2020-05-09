#include <iostream>

class Backpack 
{
public:
	virtual ~Backpack() {}
	virtual void assemble() = 0;
};

class SimpleBackpack : public Backpack
{
public:
	void assemble()
	{
		std::cout << "Simple Backpack";
	}
};

class BackpackDecorator : public Backpack 
{
protected:
	Backpack *m_decorator;
public:
	BackpackDecorator(Backpack *dec) : m_decorator(dec) {}
	void assemble() 
	{ 
		m_decorator->assemble();
	}
};

class WithWaterBottle : public BackpackDecorator 
{
public:
	WithWaterBottle(Backpack *dec) : BackpackDecorator(dec){}
	void assemble()
	{
		BackpackDecorator::assemble();
		std::cout << " with WaterBottle";
	}
};

class WithUSBCharge : public BackpackDecorator
{
public:
	WithUSBCharge(Backpack *dec) : BackpackDecorator(dec){}
	void assemble()
	{
		BackpackDecorator::assemble();
		std::cout << " with USBCharger";
	}
};

int main() 
{
	Backpack* pBackpack = new WithUSBCharge(
		new WithWaterBottle(
			new SimpleBackpack()));

	pBackpack->assemble();

	delete pBackpack;

	return 0;
}
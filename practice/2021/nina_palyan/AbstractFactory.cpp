#include <iostream>
#include <math.h>
using namespace std;

class Phone
{
public:
	virtual void sendSMS() = 0;
};

class Apple : public Phone
{
public:
	virtual void sendSMS() { cout << "Sent from iPhone" << endl; }
};

class Samsung : public Phone
{
public:
	virtual void sendSMS() { cout << "Sent from Samsung" << endl; }
};
class Car
{
public:
	void drive() {
		if (!fuel) { 
			cout << "No more fuel" << endl; 
			park(); 
		} 
		else {
			cout << "driving..." << endl;
			fuel--;
		}
	}
	void park() { cout << "Car is parked." << endl; }
protected:
	int fuel;
};
class Ford : public Car
{
public:
	Ford()
	{
		fuel = 3; //gave random low numbers just for demonstration
	}

};
class Kia : public Car
{
public:
	Kia()
	{
		fuel = 5;
	}
};

class Brand
{
public:
	virtual Car* makeCar() = 0;
	virtual Phone* makePhone() = 0;
};
class USBrand : public Brand
{
public:
	virtual Car* makeCar() { return new Ford(); }
	virtual Phone* makePhone() { return new Apple(); }
};

class KoreanBrand : public Brand
{
public:
	virtual Car* makeCar() { return new Kia(); }
	virtual Phone* makePhone() { return new Samsung; }
};


int main()
{
	string client;
	Brand* brandSalesman;
	cin >> client;
	if (client == "American") {
		brandSalesman = new USBrand();
	}
	else
	{
		brandSalesman = new KoreanBrand();
	}
	brandSalesman->makePhone()->sendSMS();
	Car* clientCar = brandSalesman->makeCar();
	clientCar->drive();
	clientCar->drive();
	clientCar->drive();
	clientCar->drive();
	return 0;
}
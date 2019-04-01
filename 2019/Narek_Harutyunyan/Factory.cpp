//Factory Method Design Pattern
#include <iostream>
#include <string>

using namespace std;

// Product
class Vehicle {
public:
	virtual void driveVehicle() = 0;
protected:
	string _type;
};

// ConcreteProduct
class Bycicle : public Vehicle {
public:
	Bycicle() {
		_type = "Bicycle";
	}

	void driveVehicle() {
		cout << "I am driving " << _type << endl;
		cout << "My speed is 15 km/h" << endl;
	}
};

// ConcreteProduct
class Car : public Vehicle {
public:
	Car() {
		_type = "Car";
	}

	void driveVehicle() {
		cout << "I am driving " << _type << endl;
		cout << "My speed is 60 km/h" << endl;
	}

};

// Creator
class Delivery {
public:
	void packageDelivery() {
		Vehicle* v = createVehicle();

		cout << "The courier is coming" << endl;
		v->driveVehicle();
		cout << "..." << endl << "You received you package." << endl;
	}

	// Factory Method
	virtual Vehicle* createVehicle() = 0;
};

// ConcreteCreator
class CarDelivery : public Delivery {
	Vehicle* createVehicle() {
		return new Car();
	}
};

// ConcreteCreator
class BikeDelivery : public Delivery {
	Vehicle* createVehicle() {
		return new Bycicle();
	}
};

int main() {

	Delivery* car = new CarDelivery();
	car->packageDelivery();

	cout << endl;

	Delivery* bike = new BikeDelivery();
	bike->packageDelivery();

	cout << endl;
	return 0;
}
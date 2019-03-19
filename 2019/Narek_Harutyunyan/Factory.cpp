//Factory Method Design Pattern
#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
	
	void driveVehicle() {
		type = typeOfVehicle();
		cout << "I am driving a " << type << endl;
	}
	
	// This is factory method
	virtual string typeOfVehicle() = 0;
private:
	string type;
};

class Bycicle : public Vehicle {
	string typeOfVehicle() {
		cout << "This is Bycicle" << endl;
		return "Bycicle";
	}
};

class Car : public Vehicle {
	string typeOfVehicle() {
		cout << "This is Car" << endl;
		return "Car";
	}
};

int main()
{
	Vehicle *bike = new Bycicle;
	bike->driveVehicle();
	
	cout << endl;

	Vehicle *car = new Car;
	car->driveVehicle();

	return 0;
}
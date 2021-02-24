//Builder Design Pattern
#include <iostream>
#include <string>


class House {
public:
	void houseDetails() {
		std::cout << "Amount of doors - " << _doors << std::endl;
		std::cout << "Amount of windows - " << _windows << std::endl;
	}

	int _doors;
	int _windows;
};


class HouseBuilder {
public:
	void buildWalls() {
		std::cout << "Building walls for house!" << std::endl;
	}

	int buildDoor() {
		std::cout << "Installing the door!" << std::endl;
		int door = 1;
		return door;
	}

	int buildWindows() {
		std::cout << "Installing 2 windows!" << std::endl;

		// Adding 2 windows from sides
		int windows = 2;
		return windows;
	}
	
	void buildRoof(){
		std::cout << "Building roof for our house!" << std::endl;
	}

	House* getHouse() {
		House* currHouse = new House();

		this->buildWalls();
		currHouse->_doors = this->buildDoor();
		currHouse->_windows = this->buildWindows();
		this->buildRoof();

		return currHouse;
	}
};


int main() {
	House* h;
	HouseBuilder* hBuilder = new HouseBuilder();

	h = hBuilder->getHouse();
	h->houseDetails();

	return 0;
}
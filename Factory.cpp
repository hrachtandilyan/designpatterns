#include <iostream> 
using namespace std;

class Flight {
public:
	virtual void printType() = 0;
};
class FirstClassFlight : public Flight {
public:
	void printType() {
		cout << "First Class" << endl;
	}
};
class BusinessClassFlight : public Flight {
public:
	void printType() {
		cout << "Business Class" << endl;
	}
};

class Ticket {
public:
	Ticket(int type) {
		if (type == 1)
			flightType = new FirstClassFlight();
		else if (type == 2)
			flightType = new BusinessClassFlight();
		else
			flightType = NULL;
	}

	~Ticket() {
		if (flightType)
		{
			delete[] flightType;
			flightType = NULL;
		}
	}

	Flight* getFlightType() {
		return flightType;
	}
private:
	Flight *flightType;
};
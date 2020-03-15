#include <iostream>
#include <string>

using namespace std;

// Product
class Party {
public:
	virtual void registeration() = 0;
	string _type;
	int votes;
};

// ConcreteProduct
class HHK : public Party {
public:
	HHK()
	{
		_type = "HHK";
		votes = 0;
	}

	virtual void registeration() {
		votes = 700;
		cout << _type << " is registered. Please wait for answer" << endl;
	}
};

// ConcreteProduct
class ImQayl : public Party {
public:
	ImQayl() {
		_type = "ImQayl";
		votes = 0;
	}

	virtual void registeration() {
		votes = 1000;
		cout << _type << " is registered. Please wait for answer" << endl;
	}
};

// ConcreteProduct
class BHK : public Party {
public:
	BHK() {
		_type = "BHK";
		votes = 0;
	}

	virtual void registeration() {
		votes = 500;
		cout << _type << " is registered. Please wait for answer" << endl;
	}

};

// Creator
class Election {
public:
	void startingElection() {
		Party* p = createParty();

		cout << "Starting Elections" << endl;
		p->registeration();
		cout << "..." << endl;
		if (p->votes > 600)
			cout << "YOU ARE ELECTED" << endl;
		else
			cout << "SORRY, NOT ENOUGH VOTES. TRY NEXT TIME" << endl;
	}

	// Factory Method
	virtual Party* createParty() = 0;
};

// ConcreteCreator
class BHKelection : public Election {
	Party* createParty() {
		return new BHK();
	}
};

// ConcreteCreator
class HHKelection : public Election {
	Party* createParty() {
		return new HHK();
	}
};

// ConcreteCreator
class ImQaylelection : public Election {
	Party* createParty() {
		return new ImQayl();
	}
};

int main() {

	Election* bhk = new BHKelection();
	bhk->startingElection();

	cout << endl;

	Election* hhk = new HHKelection();
	hhk->startingElection();

	cout << endl;
	int a;
	cin >> a;
	return 0;
}
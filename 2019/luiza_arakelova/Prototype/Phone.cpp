#include <iostream>
#include <string>

using namespace std;

class Phone {
public:
	Phone() {}
	~Phone() { }
	virtual Phone *  clone() = 0;
};

class SamsungPhone : public Phone {
	Phone * clone() {
		return new SamsungPhone(*this);
	}
};
class ApplePhone : public Phone {
	Phone * clone() {
		return new ApplePhone(*this);
	}
};
class SonyPhone : public Phone {
	Phone * clone() {
		return new SonyPhone(*this);
	}
};
int main() {
	static Phone * prototypes[3] = { new SamsungPhone(), new ApplePhone(), new SonyPhone() };

	string name;
	cout << "Please choose and write phone brand you want to make from {Samsung,Apple,Sony}" << endl;
	cin >> name;
	Phone * phone = nullptr;

	if (name == "Samsung")
		phone = prototypes[0]->clone();
	if (name == "Apple")
		phone = prototypes[1]->clone();
	if (name == "Sony")
		phone = prototypes[2]->clone();

	system("pause");
	return 0;
}

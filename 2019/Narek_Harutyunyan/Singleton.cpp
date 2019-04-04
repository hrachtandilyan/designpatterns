//Singleton Design Pattern
#include <iostream>
#include <string>
#include <mutex>   

using namespace std;


mutex mtx;

class Singleton {
public:
	static Singleton* getInstance() {
		if (_instance == 0) {
		    
		    // Making thread safe
		    lock_guard<mutex> lck (mtx);
		    if (_instance == 0) {
			_instance = new Singleton;
		    }
		}

		return _instance;
	}

	int getData() {
		return _data;
	}

	void setData(int d) {
		_data = d;
	}

private:
	Singleton() {
		_data = 0;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;
	~Singleton() {}

	static Singleton* _instance;
	int _data;
};

Singleton *Singleton::_instance = 0;

int main() {
	Singleton* s = Singleton::getInstance();

	cout << s->getData() << endl;
	s->setData(1);
	cout << s->getData() << endl;
	
	Singleton* s2 = Singleton::getInstance();

	s2->setData(2);
	cout << s->getData() << endl;
	cout << s2->getData() << endl;
	return 0;
}

//Abstract Factory Design Pattern
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void create() = 0;
};

class Circle : public Shape {
public:
	void create() {
		cout << "Drawing circle" << endl;
	}
};
class Square : public Shape {
public:
	void create() {
		cout << "Drawing square" << endl;
	}
};
class Sphere : public Shape {
public:
	void create() {
		cout << "Making sphere" << endl;
	}
};
class Cylinder : public Shape {
public:
	void create() {
		cout << "Making cylinder" << endl;
	}
};

class Model {
public:	
	virtual Shape* firstPart() = 0;
	virtual Shape* secondPart() = 0;
};

class twoDimentionalModel : public Model {
public:
	Shape* firstPart() {
		return new Circle;
	}
	Shape* secondPart() {
		return new Square;
	}
};
class threeDimentionalModel : public Model {
public:
	Shape* firstPart() {
		return new Sphere;
	}
	Shape* secondPart() {
		return new Cylinder;
	}
};

int main() {
	Model* paper = new twoDimentionalModel;
	paper->firstPart()->create();
	paper->secondPart()->create();

	cout << endl;

	Model* cardboard = new threeDimentionalModel;
	cardboard->firstPart()->create();
	cardboard->secondPart()->create();
}
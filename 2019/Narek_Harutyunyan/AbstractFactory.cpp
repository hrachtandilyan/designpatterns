//Abstract Factory Design Pattern
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
};

class Circle : public Shape {
public:
	void draw() {
		cout << "Drawing circle" << endl;
	}
};
class Square : public Shape {
public:
	void draw() {
		cout << "Drawing square" << endl;
	}
};
class Sphere : public Shape {
public:
	void draw() {
		cout << "Making sphere" << endl;
	}
};
class Cylinder : public Shape {
public:
	void draw() {
		cout << "Making cylinder" << endl;
	}
};

class Model {
public:
	void makeModel() {
		Shape* part1 = createFirstPart();
		Shape* part2 = createSecondPart();

		part1->draw();
		part2->draw();
	}
	virtual Shape* createFirstPart() = 0;
	virtual Shape* createSecondPart() = 0;
};

class twoDimentionalModel : public Model {
public:
	Shape* createFirstPart() {
		return new Circle;
	}
	Shape* createSecondPart() {
		return new Square;
	}
};
class threeDimentionalModel : public Model {
public:
	Shape* createFirstPart() {
		return new Sphere;
	}
	Shape* createSecondPart() {
		return new Cylinder;
	}
};

int main() {
	Model* paper = new twoDimentionalModel();
	paper->makeModel();

	cout << endl;

	Model* cardboard = new threeDimentionalModel();
	cardboard->makeModel();
}
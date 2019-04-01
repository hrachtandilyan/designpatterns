//Prototype Design Pattern
#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	Shape():x(0),y(0) { }

	Shape(const Shape& copyShape) {
		this->x = copyShape.x;
		this->y = copyShape.y;
	}

	virtual void draw() = 0;
	virtual Shape* clone() = 0;

	int x;
	int y;
};

class Circle : public Shape {
public:
	Circle():radius(1) { }

	Circle(const Circle &copyCircle):Shape(copyCircle) {
		this->radius = copyCircle.radius;
	}

	void draw() {
		cout << "Drawing circle on (" << this->x << "," << this->y <<") with radius " << this->radius  << endl;
	}

	Shape* clone() {
		return new Circle(*this);
	}

	int radius;
};

class Square : public Shape {
public:
	Square() :side(1) { }

	Square(const Square &copySquare) :Shape(copySquare) {
		this->side = copySquare.side;
	}

	void draw() {
		cout << "Drawing square on (" << this->x << "," << this->y << ") with side " << this->side << endl;
	}

	Shape* clone() {
		return new Square(*this);
	}
	int side;
};

int main() {
	Shape* prototypes[2] = { new Circle(), new Square() };

	cout << "Testing Prototype Pattern\n";
	cout << "Making clone and drawing it \nType 0 for circle or other number for square to make clone:";

	bool type;
	cin >> type;

	Shape* clone;

	if (type == 0) {
		clone = prototypes[0]->clone();
	}
	else {
		clone = prototypes[1]->clone();
	}

	clone->draw();
}
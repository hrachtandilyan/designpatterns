#include <iostream>

class Shape {
public:
	Shape() {
		id = count++;
	}
	virtual void draw() = 0;
protected:
	int id;
	static int count;
};
int Shape::count = 0;

class Circle : public Shape {
public:
	void draw() {
		std::cout << "circle " << id << std::endl;
	}
};
class Ellipse : public Shape {
public:
	void draw() {
		std::cout << "ellipse " << id << std::endl;
	}
};
class Square : public Shape {
public:
	void draw() {
		std::cout << "square " << id << std::endl;
	}
};
class Rectangle : public Shape {
public:
	void draw() {
		std::cout << "rectangle " << id << std::endl;
	}
};

class Factory {
public:
	virtual Shape* createCurvedInstance() = 0;
	virtual Shape* createStraightInstance() = 0;
};

class RegularShapeFactory : public Factory {
public:
	Shape* createCurvedInstance() {
		return new Circle;
	}
	Shape* createStraightInstance() {
		return new Square;
	}
};
class IrregularShapeFactory : public Factory {
public:
	Shape* createCurvedInstance() {
		return new Ellipse;
	}
	Shape* createStraightInstance() {
		return new Rectangle;
	}
};

int main() {
	Factory* abstractFactory = new IrregularShapeFactory();

	Shape* figure[3];

	figure[0] = abstractFactory->createCurvedInstance();
	figure[1] = abstractFactory->createStraightInstance();
	figure[2] = abstractFactory->createCurvedInstance();

	for (int i = 0; i < 3; i++) {
		figure[i]->draw();
	}

	return 0;
}
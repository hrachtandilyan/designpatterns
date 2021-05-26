#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
public:
	Shape() {}
	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
};
class Triangle : public Shape
{
public:
	Triangle(double _side1 = 3, double _side2 = 4, double _side3 = 5) {
		side1 = _side1;
		side2 = _side2;
		side3 = _side3;
	}
	double getPerimeter() {
		return side1 + side2 + side3;
	}
	double getArea() {
		double s = (side1 + side2 + side3) / 2;
		return sqrt(s * (s - side1) * (s - side2) * (s - side3));
	}
private:
	double side1, side2, side3;
};

class Square : public Shape
{
public:
	Square(double a = 4) {
		side = a;
	}
	double getPerimeter() {
		return 4 * side;
	}
	double getArea() {
		return side * side;
	}
	double getDiagonal() {
		return side * sqrt(2);
	}
private:
	double side;
};

class Rectangle : public Shape
{
public:
	Rectangle(double a = 2, double b = 6) {
		width = a;
		length = b;
	}
	double getPerimeter() {
		return 2 * (width + length);
	}
	double getArea() {
		return width * length;
	}
private:
	double width, length;
};

class ShapeFactory
{
public:
	virtual Shape* createShape() = 0;
};

class SquareClient : public ShapeFactory
{
public:
	Shape* createShape() { return new Square; }
};

class TriangleClient : public ShapeFactory
{
public:
	Shape* createShape() { return new Triangle; }
};

class RectangleClient : public ShapeFactory
{
public:
	Shape* createShape() { return new Rectangle; }
};

int main()
{
	
	Shape* triangle = TriangleClient().createShape();
	cout << triangle->getArea() << " " << triangle->getPerimeter() << endl;
	Shape* square = SquareClient().createShape();
	cout << square->getArea() << " " << square->getPerimeter() << endl;
	Shape* rectangle = RectangleClient().createShape();
	cout << rectangle->getArea() << " " << rectangle->getPerimeter() << endl;
	return 0;
}
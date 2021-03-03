#include <iostream>
#include <math.h>
using namespace std;

class Geometry
{
public:
	Geometry() {}
	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
};
class Triangle : public Geometry
{
public:
	Triangle(double _side1, double _side2, double _side3) {
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

class Square : public Geometry
{
public:
	Square(double a) {
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

class Rectangle : public Geometry
{
public:
	Rectangle(double a, double b) {
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

class Shape
{
public:
	Shape(double a) {
		//square
		geometry = new Square(a);
	}
	Shape(double a, double b) {
		//rectangle
		geometry = new Rectangle(a,b);
	}
	Shape(double a, double b, double c) {
		//triangle
		geometry = new Triangle(a,b,c);
	}
	Geometry* geometry;
};

int main()
{
	Shape triangle = Shape(3, 4, 5);
	cout << triangle.geometry->getArea() << " " << triangle.geometry->getPerimeter() << endl;
	Shape square = Shape(10);
	cout << square.geometry->getArea() << " " << square.geometry->getPerimeter() << endl;
	Shape rectangle = Shape(7, 8);
	cout << rectangle.geometry->getArea() << " " << rectangle.geometry->getPerimeter() << endl;
	return 0;
}
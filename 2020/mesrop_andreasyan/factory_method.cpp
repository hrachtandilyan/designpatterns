#include <iostream>
#include <string>
using namespace std;

class Shape
{
    public:
       virtual void Draw() = 0;
       static Shape* Create(string type);
};

class Circle : public Shape
{
    public:
       void Draw() { cout << "klor" << endl; }
};

class Square : public Shape
{
    public:
       void Draw() { cout << "qarakusi" << endl; }
};

Shape* Shape::Create(string type)
{
    if ( type == "circle" ) return new Circle();
    if ( type == "square" ) return new Square();
    return 0;
}

int main()
{
   Shape* obj1 = Shape::Create("circle");
   Shape* obj2 = Shape::Create("square");
   obj1->Draw();
   obj2->Draw();
}

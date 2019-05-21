using AbstractFactory;
using System;

namespace AbstractFactory
{
    class Program
    {
        static void Main(string[] args)
        {

            IPolygonFactory factory;

            var shape = Console.ReadLine();

            switch (shape)
            {
                case "Rectangle":
                    factory = new RectangleFactory();
                    break;
                case "Triangle":
                    factory = new TriangleFactory();
                    break;
                default:
                    throw new NotImplementedException();
            }

            var button = factory.CreatePolygon();
            button.DrawPolygon();

        }
    }
}

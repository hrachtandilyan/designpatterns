using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory
{
    interface IPolygon
    {
        void DrawPolygon();
    }

    interface IPolygonFactory
    {
        IPolygon CreatePolygon();
    }

    class TriangleFactory : IPolygonFactory
    {
        public IPolygon CreatePolygon()
        {
            return new Triangle();
        }
    }

    class RectangleFactory : IPolygonFactory
    {
        public IPolygon CreatePolygon()
        {
            return new Rectangle();
        }
    }

    class Triangle : IPolygon
    {
        public void DrawPolygon()
        {
            int left_border = 5;
            int right_border = 5;
            for (int i = 0; i <= 5; ++i)
            {
                for (int j = 0; j <= 10; ++j)
                {
                    if (left_border == j || right_border == j)
                        Console.Write('*');
                    else if(i == 5)
                        Console.Write('*');
                    else
                        Console.Write(' ');
                }
                --left_border;
                ++right_border;
                Console.WriteLine();
            }
        }
    }

    class Rectangle : IPolygon
    {
        public void DrawPolygon()
        {
            for (int i = 0; i < 7; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    if (i == 0 || j == 9 || j == 0 || i == 6)
                        Console.Write('*');
                    else
                        Console.Write(' ');
                }
                Console.WriteLine();
            }
        }
    }
}
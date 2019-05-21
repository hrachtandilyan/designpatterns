using System;
using System.Collections.Generic;
using System.Text;

namespace Adapter
{
    public class RectangleLibrary
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Height { get; set; }
        public int Length { get; set; }

        public int Area()
        {
            return Height * Length;
        }
        public int Perimeter()
        {
            return 2 * (Height + Length);
        }

        public RectangleLibrary(int x, int y, int height, int length)
        {
            this.X = x;
            this.Y = y;
            this.Height = height;
            this.Length = length;
        }
    }

    public class RectangleAdaptor
    {
        private RectangleLibrary rect;
        public RectangleAdaptor(int x1, int y1, int x2, int y2)
        {
            rect = new RectangleLibrary(x1, y1, x2 - x1, y2 - y1);
        }
        public int Area()
        {
            return rect.Area();
        }
        public int Perimeter()
        {
            return rect.Perimeter();
        }

        public KeyValuePair<int, int> LL
        {
            get
            {
                return new KeyValuePair<int, int>(rect.X, rect.Y);
            }
            set
            {
                rect.Length = rect.Length + rect.X - value.Key;
                rect.Height = rect.Height + rect.Y - value.Value;
                rect.X = value.Key;
                rect.Y = value.Value;
            }
        }
        public KeyValuePair<int, int> UR
        {
            get
            {
                return new KeyValuePair<int, int>(rect.X + rect.Length, rect.Y + rect.Height);
            }

            set
            {
                rect.Length = value.Key - rect.X;
                rect.Height = value.Value - rect.Y;
            }
        }
    }

    public class Rectangle : RectangleAdaptor
    {
        public Rectangle(int x1, int y1, int x2, int y2): base (x1, y1, x2, y2)
        {
        }

        public void Draw()
        {
            int i = 0, j;
            KeyValuePair<int, int> LL = this.LL;
            KeyValuePair<int, int> UR = this.UR;

            for (; i < LL.Key; ++i)
            {
                for (j = 0; j <= UR.Value; ++j)
                    Console.Write(".");
                Console.WriteLine();
            }

            for (; i <= UR.Key; ++i)
            {
                for (j = 0; j < LL.Value; ++j)
                    Console.Write(".");
                for (j = LL.Value; j <= UR.Key; ++j)
                    Console.Write("*");
                Console.WriteLine();
            }
        }

    };

}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Singleton si = Singleton.Initialize();
            Console.WriteLine(si.GetHashCode());
            Singleton si1 = Singleton.Initialize();
            Console.WriteLine(si1.GetHashCode());

            Console.ReadKey();

        }
    }
}

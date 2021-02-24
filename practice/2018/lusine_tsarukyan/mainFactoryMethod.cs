using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactoryMethod
{
    class mainFactoryMethod
    {
        static void Main(string[] args)
        {
            String s1 = "BIG";
            String s2 = "notBig";
            BurgerCreatorBase creator = new BurgerCreator();
            creator.makeBurger(s1);
            creator.makeBurger(s2);
        }
    }
}

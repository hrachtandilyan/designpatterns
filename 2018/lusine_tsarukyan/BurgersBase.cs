using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactoryMethod
{

    abstract class BurgerCreatorBase
    {
        public abstract BurgerBase makeBurger(string burgerName);
    }

    public abstract class BurgerBase
    {
    }

    class BurgerCreator : BurgerCreatorBase
    {

        public override BurgerBase makeBurger(string burgerName)
        {
            if (burgerName == "BIG")
            {
                Console.WriteLine("Big burger is created!");
                return new BigBurger();
            }
            else
            {
                Console.WriteLine("This is not Big Burger!");
                return new SmallBurger();
            }
        }
    }

    internal class BigBurger : BurgerBase
    {
    }
    internal class SmallBurger : BurgerBase
    {
    }
}


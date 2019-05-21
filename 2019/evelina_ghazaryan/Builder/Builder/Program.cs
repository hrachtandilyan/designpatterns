using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Builder
{
    class Program
    {
        static void Main(string[] args)
        {
            PhoneBuilder builder;
            var store = new Store();
            builder = new XS();
            store.Construct(builder);
            builder.Phone.Print();
            builder = new GalaxyS9();
            store.Construct(builder);
            builder.Phone.Print();
        }
    }
}
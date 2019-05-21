using System;
using System.Collections.Generic;

namespace Builder
{
    class Store
    {
        public void Construct(PhoneBuilder phoneBuilder)
        {
            phoneBuilder.SetYear();
            phoneBuilder.SetModel();
            phoneBuilder.SetMemory();
            phoneBuilder.SetPrice();
        }
    }
    abstract class PhoneBuilder
    {
        protected Phone phone;
        public Phone Phone
        {
            get
            {
                return phone;
            }
        }
        public abstract void SetYear();
        public abstract void SetModel();
        public abstract void SetMemory();
        public abstract void SetPrice();
    }

    class GalaxyS9 : PhoneBuilder
    {
        public GalaxyS9()
        {
            phone = new Phone("Samsung Galaxy S9");
        }

        public override void SetYear()
        {
            phone["year"] = 2017;
        }

        public override void SetModel()
        {
            phone["model"] = "Galaxy S9";
        }

        public override void SetMemory()
        {
            phone["memory"] = "64GB";
        }

        public override void SetPrice()
        {
            phone["price"] = "720$";
        }

    }
   
    class XS : PhoneBuilder
    {
        public XS()
        {
            phone = new Phone("Iphone XS");
        }

        public override void SetYear()
        {
            phone["year"] = 2018;
        }

        public override void SetModel()
        {
            phone["model"] = "XS";
        }

        public override void SetMemory()
        {
            phone["memory"] = "64GB";
        }

        public override void SetPrice()
        {
            phone["price"] = "749$";
        }

    }
    class Phone
    {
        private string phoneType;
        private Dictionary<string, object> phones = new Dictionary<string, object>();

        public Phone(string phoneType)
        {
            this.phoneType = phoneType;
        } 
        public object this[string key]
        {
            get { return phones[key]; }
            set { phones[key] = value; }
        }

        public void Print()
        {
            Console.WriteLine("Phone: {0}", phoneType);
            Console.WriteLine(" Year: {0}", phones["year"]);
            Console.WriteLine(" Model: {0}", phones["model"]);
            Console.WriteLine(" Memory: {0}", phones["memory"]);
            Console.WriteLine(" Price: {0}", phones["price"]);
            Console.WriteLine();
        }
    }
}
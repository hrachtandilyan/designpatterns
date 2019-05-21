using System;
using System.Collections.Generic;
using System.Text;

namespace Singleton
{
    public sealed class Singleton
    {

        private static Singleton db = new Singleton();

        private Singleton() { }

        public static Singleton DB
        {
            get
            {
                if (db == null)
                    db = new Singleton();
                return db;
            }
        }
    }
}

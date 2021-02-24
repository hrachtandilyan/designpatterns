package com.company;

public class Singleton {
    static private Singleton singleton;

    public static Singleton getInstance()
    {
        if (singleton == null)
        {
            singleton = new Singleton();
        }
        return singleton;
    }

    private Singleton () {}
}

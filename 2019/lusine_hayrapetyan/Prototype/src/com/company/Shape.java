package com.company;

import java.lang.Object;

public abstract class Shape implements Cloneable{
    public abstract void draw();

    public Object clone()
    {
        Object shape = null;
        try {
            shape = super.clone();
        } catch (CloneNotSupportedException e)
        {
            e.printStackTrace();
        }
        return shape;
    }
}

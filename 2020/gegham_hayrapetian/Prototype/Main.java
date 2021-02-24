package com.rau;

import com.rau.prototype.Human;

public class Main {

    public static void main(String[] args) {
        Human original = new Human(23, "Gegham");
        Human copy = (Human) original.copy();
        System.out.println(original);
        System.out.println(copy);


    }
}

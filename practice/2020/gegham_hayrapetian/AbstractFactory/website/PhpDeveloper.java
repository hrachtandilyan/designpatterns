package com.rau.website;

import com.rau.interfaces.Developer;

public class PhpDeveloper implements Developer {

    @Override
    public void writeCode() {

        System.out.println("Developer writes PHP code...");
    }
}

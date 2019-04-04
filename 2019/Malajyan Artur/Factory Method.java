package com.company;


import java.util.Date;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Factory factory=new Gfactory("Digital");
        Watch watch=factory.creator();
        watch.showtime();
    }
}

interface Watch{
 void showtime();
}

class DigitalWatch implements Watch{

    @Override
    public void showtime() {
        System.out.println(new Date());
    }
}

class RomeWatch implements Watch{

    @Override
    public void showtime() {
        System.out.println("VIIII");
    }
}

abstract class Factory{
    String a;
    Factory(String a){
        this.a=a;
    }
    abstract Watch creator();
}

class Gfactory extends Factory{


    Gfactory(String a) {
        super(a);
    }

    @Override
    Watch creator() {
        if(a.equals("Digital"))
            return new DigitalWatch();
        if(a.equals("Rome"))
            return new RomeWatch();
        throw  new RuntimeException("We dont have this watch "+a);
    }
}
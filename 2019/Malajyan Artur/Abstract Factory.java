package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Abstractfactory abstractfactory=new factory1();
        abstractfactory.getPhonemodel().model();
        abstractfactory.getWatchmodel().model();
        Abstractfactory abstractfactory1=new factory2();
        SmartPhone smartPhone=abstractfactory1.getPhonemodel();
        SmartWatch smartWatch=abstractfactory1.getWatchmodel();
        smartPhone.model();
        smartWatch.model();

    }
}

interface SmartPhone{
    void model();

}

class Mobile1 implements SmartPhone{
    @Override
    public void model(){
        System.out.println("Mobile1");
    }


}

class Mobile2 implements SmartPhone{
    @Override
    public void model(){
        System.out.println("Mobile2");
    }


}

interface SmartWatch{
    void model();

}

class Watch1 implements SmartWatch{
    @Override
    public void model(){
        System.out.println("Watch1");
    }

}

class Watch2 implements SmartWatch{
    @Override
    public void model(){
        System.out.println("Watch2");
    }


}


interface Abstractfactory{
    SmartPhone getPhonemodel();
    SmartWatch getWatchmodel();
}

class factory1 implements  Abstractfactory{


    @Override
    public SmartPhone getPhonemodel() {
        return new Mobile1();
    }

    @Override
    public SmartWatch getWatchmodel() {
        return new Watch1();
    }
}

class factory2 implements  Abstractfactory{


    @Override
    public SmartPhone getPhonemodel() {
        return new Mobile2();
    }

    @Override
    public SmartWatch getWatchmodel() {
        return new Watch2();
    }
}



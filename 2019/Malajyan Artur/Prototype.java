package com.company;

public class Main {

    public static void main(String[] args) {
	
        Car b=new Car("BMW",2019);
         Carfactory carfactory=new Carfactory(b);
         Car c=carfactory.makecopy();
         c.print();
    }
}

interface Copy{
    Car copy();
}
class Car implements Copya{
    private String name;
    private int year;

    public Car(String name,int year){
        this.name=name;
        this.year=year;
    }

    @Override
    public Car copy() {
        Car copy=new Car(name,year);
        return copy;
    }

    public void print(){
        System.out.println(name+year);
    }


}

class Carfactory{
    Car car;
    public Carfactory(Car car){
         setprototype(car);
    }
    public void setprototype(Car car){
        this.car=car;
    }
    public Car makecopy(){
        return car.copy();
    }
}
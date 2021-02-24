package com.rau.car_builder;

public abstract class CarBuilder {
    Car car;

    public void createCar() {
        car = new Car();
    }

    abstract void buildMake();

    abstract void buildTransmission();

    abstract void builMaxSpeed();

    public Car getCar() {
        return car;
    }
}

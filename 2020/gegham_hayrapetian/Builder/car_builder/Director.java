package com.rau.car_builder;

public class Director {
    CarBuilder builder;

    public void setBuilder(CarBuilder b) {
        builder = b;

    }

    public Car BuildCar() {
        builder.createCar();
        builder.buildMake();
        builder.buildTransmission();
        builder.builMaxSpeed();
        Car car= builder.getCar();
        return car;

    }
}

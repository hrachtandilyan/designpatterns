package com.rau.car_builder;

public class FordBuilder extends CarBuilder {
    @Override
    void buildMake() {
        car.setMake("Ford");

    }

    @Override
    void buildTransmission() {
        car.setTransmission(Transmission.AUTO);

    }

    @Override
    void builMaxSpeed() {
        car.setMaxSpeed(260);

    }
}

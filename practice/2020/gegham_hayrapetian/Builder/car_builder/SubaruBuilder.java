package com.rau.car_builder;

public class SubaruBuilder extends CarBuilder {
    @Override
    void buildMake() {
        car.setMake("Subaru");

    }

    @Override
    void buildTransmission() {
        car.setTransmission(Transmission.MANUAL);

    }

    @Override
    void builMaxSpeed() {
        car.setMaxSpeed(360);

    }
}

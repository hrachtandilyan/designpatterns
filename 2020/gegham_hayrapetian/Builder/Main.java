package com.rau;

import com.rau.car_builder.Car;
import com.rau.car_builder.Director;
import com.rau.car_builder.SubaruBuilder;

public class Main {

    public static void main(String[] args) {
        Director director= new Director();
        director.setBuilder(new SubaruBuilder());
        Car car =director.BuildCar();
        System.out.println(car);

    }
}

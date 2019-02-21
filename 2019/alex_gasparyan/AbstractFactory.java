class Test {

    public static void main(String[] args) {
        AbstractFactory factory1 = FactoryProvider.getFactory(FactoryProvider.Type.CAR);
        AbstractFactory factory2 = FactoryProvider.getFactory(FactoryProvider.Type.BIKE);
        Car car = (Car) factory1.create("BMW");
        Bike bike = (Bike) factory2.create("KAWASAKI");
    }
}

class FactoryProvider {
    enum Type {
        CAR, BIKE
    }

    public static AbstractFactory getFactory(Type type) {
        switch (type) {
            case CAR:
                return new CarFactory();
            default:
                return new BikeFactory();
        }
    }

}

interface AbstractFactory<T> {
    T create(String type);
}


class CarFactory implements AbstractFactory<Car> {

    @Override
    public Car create(String type) {
        switch (type) {
            case "BMW":
                return new BMW();
            default:
                return new Mercedes();
        }
    }
}

abstract class Car {
    abstract int getHorsePower();
}

class BMW extends Car {

    @Override
    public int getHorsePower() {
        return 350;
    }
}

class Mercedes extends Car {

    @Override
    public int getHorsePower() {
        return 250;
    }
}

class BikeFactory implements AbstractFactory<Bike>{

    enum Type {
        KAWASAKI, DUCATI
    }

    public Bike create(String type) {
        switch (type) {
            case "KAWASAKI":
                return new Kawasaki();
            default:
                return new Ducati();
        }
    }
}

abstract class Bike {
    abstract int getMaxSpeed();
}

class Kawasaki extends Bike {

    @Override
    public int getMaxSpeed() {
        return 350;
    }
}

class Ducati extends Bike {

    @Override
    public int getMaxSpeed() {
        return 320;
    }
}}

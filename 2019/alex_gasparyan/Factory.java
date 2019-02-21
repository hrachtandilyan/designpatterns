class Test {

	public static void main(String[] args) {
		Car car1 = CarFactory.getCar(CarFactory.Type.BMW);
		Car car2 = CarFactory.getCar(CarFactory.Type.MERCEDES);
		Car car3 = CarFactory.getCar(CarFactory.Type.AUDIO);
	}
}


class CarFactory {

	enum Type {
		BMW, MERCEDES, AUDI
	}

	public static Car getCar(Type type) {
		switch (type) {
			case BMW: 
				return new BMW();
			case MERCEDES: 
				return new Mercedes();
			default:
				return new Audi();
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

class Audi extends Car {

	@Override
	public int getHorsePower() {
		return 200;
	}
}
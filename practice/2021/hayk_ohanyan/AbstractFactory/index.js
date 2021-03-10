const CarFactory = require('./CarFactory.class');

const factory = new CarFactory();

try {
  const cars = [
    factory.create('bmw', 'x5'),
    factory.create('mercedes', 'c300'),
    factory.create('mercedes', 'e320'),
    factory.create('mercedes', 'c200'),
    factory.create('bmw', 'x6'),
    factory.create('mercedes', 'c180')
  ];

  cars.forEach(car => car.info());
} catch (e) {
  console.log(e);
}

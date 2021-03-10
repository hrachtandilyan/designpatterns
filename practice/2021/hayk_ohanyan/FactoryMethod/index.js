const MercedesFactory = require('./MercedesCars/Factory.class');

const factory = new MercedesFactory();

try {
  const cars = [
    factory.create('c300'),
    factory.create('c180'),
    factory.create('c200'),
  ];
  
  cars.forEach(car => car.info());
} catch (e) {
  console.log(e);
} 

const MercedesFactory = require('./Mercedes/Factory.class');
const BmwFactory = require('./Bmw/Factory.class');

class CarFactory {
  static cars = {
    mercedes: MercedesFactory,
    bmw: BmwFactory
  }

  create(type, model) {
    if (!CarFactory.cars[type]) {
      throw new Error(`${type.toUpperCase()} car not found :(`);
    }

    return CarFactory.cars[type].models[model];
  }
}

module.exports = CarFactory;

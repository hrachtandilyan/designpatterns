const Laptop = require('./Gadget/Laptop.class');
const Tablet = require('./Gadget/Tablet.class');
const SmartPhone = require('./Gadget/SmartPhone.class');

class GadgetFactory {
  static gadgets = {
    Laptop,
    Tablet,
    SmartPhone
  }

  create(type, options) {
    const Gadget = GadgetFactory.gadgets[type];

    return new Gadget(options);
  }
}

module.exports = GadgetFactory;

const X = require('./Models/X.class');

class BmwFactory {
  static models = {
    x5: new X('x5', 300, '$108,000', 2020),
    x6: new X('x6', 320, '$111,000', 2020)
  }

  create(model) {
    if (!BmwFactory.models[model]) {
      throw new Error(`Bmw model ${model} not found :(`);
    }

    return BmwFactory.models[model];
  }
}

module.exports = BmwFactory;

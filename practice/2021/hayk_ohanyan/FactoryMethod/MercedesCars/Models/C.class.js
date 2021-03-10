class C {
  constructor(model, maxSpeed, price, year) {
    this.model = model;
    this.year = year;
    this.price = price;
    this.maxSpeed = maxSpeed;
  }

  info() {
    console.log(`Model: ${this.model}`);
    console.log(`Year: ${this.year}`);
    console.log(`Max speed: ${this.maxSpeed}`);
    console.log(`Price: ${this.price}`, '\n');
  }
}

module.exports = C;
